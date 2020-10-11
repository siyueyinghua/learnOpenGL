#version 330 core
out vec4 FragColor;

struct Material {
    sampler2D texture_diffuse;
    sampler2D texture_specular;
    float shininess;
}; 

#define NR_MATERIALS 1

in vec2 TexCoords;

uniform Material material[NR_MATERIALS];

void main()
{    
    vec3 diffuse = texture(material[0].texture_diffuse, TexCoords).rgb;
    vec3 specular = texture(material[0].texture_specular, TexCoords).rgb;
    vec3 result = mix(diffuse, specular, 0.1);
    FragColor = vec4(result, 1.0);
}

