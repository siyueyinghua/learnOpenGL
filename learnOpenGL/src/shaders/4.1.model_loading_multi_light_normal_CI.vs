#version 330 core

// New type def
struct DirLight {
    vec3 direction;
	
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct PointLight {
    vec3 position;
    
    float constant;
    float linear;
    float quadratic;
	
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct SpotLight {
    vec3 position;
    vec3 direction;
    float cutOff;
    float outerCutOff;
  
    float constant;
    float linear;
    float quadratic;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;       
};

// input var
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;
layout (location = 3) in vec3 aTangent;
layout (location = 4) in vec3 aBitangent;

// output var
out vec2 TexCoords;
out vec3 TangentFragPos;
out vec3 TangentViewPos;
out DirLight TangentDirLight;
out PointLight TangentPointLight;
out SpotLight TangentSpotLight;

// uniform var
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
// fixme: why cal and send normalMatrix here doesn't work
//-- uniform mat3 normalMatrix;

uniform vec3 viewPos;
uniform DirLight dirLight;
uniform PointLight pointLight;
uniform SpotLight spotLight;

void main()
{
    TexCoords = aTexCoords;
    vec3 FragPos = vec3(model * vec4(aPos, 1.0));

    TangentDirLight = dirLight;
    TangentPointLight = pointLight;
    TangentSpotLight = spotLight;

    // Best method, guarantee T & B & N being perpendicular to each other,
    // by doing the Gram-Schmidt process even if normalMatrix is not a orthogonal matrix.
    mat3 normalMatrix = transpose(inverse(mat3(model)));
    vec3 T = normalize(normalMatrix * aTangent);
    vec3 N = normalize(normalMatrix * aNormal);
    T = normalize(T - dot(T, N) * N);
    vec3 B = cross(N, T);
    mat3 TBN = transpose(mat3(T, B, N));

    // Another optional method when the normalMatrix is a orthogonal matrix
    //-- vec3 T = normalize(normalMatrix * aTangent);
    //-- vec3 N = normalize(normalMatrix * aNormal);
    //-- vec3 B = normalize(normalMatrix * aBitangent);
    //-- mat3 TBN = transpose(mat3(T, B, N));

    TangentViewPos  = TBN * viewPos;
    TangentFragPos  = TBN * FragPos;
    TangentDirLight.direction = TBN * dirLight.direction;
    TangentPointLight.position = TBN * pointLight.position;
    TangentSpotLight.position = TBN * spotLight.position;
    TangentSpotLight.direction = TBN * spotLight.direction;

    gl_Position = projection * view * vec4(FragPos, 1.0);
}

