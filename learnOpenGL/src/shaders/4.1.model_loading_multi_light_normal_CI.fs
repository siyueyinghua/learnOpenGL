#version 330 core

struct Material {
    sampler2D texture_diffuse;
    sampler2D texture_specular;
    sampler2D texture_normal;
    float shininess;
}; 

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


in vec2 TexCoords;
in vec3 TangentFragPos;
in vec3 TangentViewPos;
in DirLight TangentDirLight;
in PointLight TangentPointLight;
in SpotLight TangentSpotLight;

#define NR_MATERIALS 1
uniform Material material[NR_MATERIALS];

out vec4 FragColor;

// function prototypes
vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir);
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir);

void main()
{    
    // properties
    vec3 TangentNormal = vec3(texture(material[0].texture_normal, TexCoords));
    TangentNormal = normalize(TangentNormal * 2.0 - 1.0);  // this normal is in tangent space
    vec3 TangentViewDir = normalize(TangentViewPos - TangentFragPos);
    
    // == =====================================================
    // Our lighting is set up in 3 phases: directional, point lights and an optional flashlight
    // For each phase, a calculate function is defined that calculates the corresponding color
    // per lamp. In the main() function we take all the calculated colors and sum them up for
    // this fragment's final color.
    // == =====================================================
    // phase 1: directional lighting
    vec3 result = CalcDirLight(TangentDirLight, TangentNormal, TangentViewDir);
    // phase 2: point lights
    result += CalcPointLight(TangentPointLight, TangentNormal, TangentFragPos, TangentViewDir);
    // phase 3: spot light
    result += CalcSpotLight(TangentSpotLight, TangentNormal, TangentFragPos, TangentViewDir);
    //-- result = vec3(1.0f, 0.0f, 0.0f);
    
    FragColor = vec4(result, 1.0);
}

// calculates the color when using a directional light.
vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir)
{
    vec3 lightDir = normalize(-light.direction);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material[0].shininess);
    // combine results
    vec3 ambient = light.ambient * vec3(texture(material[0].texture_diffuse, TexCoords));
    vec3 diffuse = light.diffuse * diff * vec3(texture(material[0].texture_diffuse, TexCoords));
    vec3 specular = light.specular * spec * vec3(texture(material[0].texture_specular, TexCoords));
    return (ambient + diffuse + specular);
}

// calculates the color when using a point light.
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material[0].shininess);
    // attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    
    // combine results
    vec3 ambient = light.ambient * vec3(texture(material[0].texture_diffuse, TexCoords));
    vec3 diffuse = light.diffuse * diff * vec3(texture(material[0].texture_diffuse, TexCoords));
    vec3 specular = light.specular * spec * vec3(texture(material[0].texture_specular, TexCoords));
    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;
    return (ambient + diffuse + specular);
}

// calculates the color when using a spot light.
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material[0].shininess);
    // attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    
    // spotlight intensity
    float theta = dot(lightDir, normalize(-light.direction)); 
    float epsilon = light.cutOff - light.outerCutOff;
    float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);
    // combine results
    vec3 ambient = light.ambient * vec3(texture(material[0].texture_diffuse, TexCoords));
    vec3 diffuse = light.diffuse * diff * vec3(texture(material[0].texture_diffuse, TexCoords));
    vec3 specular = light.specular * spec * vec3(texture(material[0].texture_specular, TexCoords));
    ambient *= attenuation * intensity;
    diffuse *= attenuation * intensity;
    specular *= attenuation * intensity;
    return (ambient + diffuse + specular);
}

