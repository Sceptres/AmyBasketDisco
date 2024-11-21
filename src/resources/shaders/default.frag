#version 330 core

#define M_PI 3.1415926535897932384626433832795

in vec3 vecColor;
in vec3 Normal;
in vec2 TextCoord;
in vec3 lightPos;
in vec3 FragPos;
in float theta;

out vec4 FragColor;

uniform sampler2D Texture;

// Spotlight parameters
// Red spotlight parameters
uniform vec3 spotlightLightPos1;
uniform vec3 spotlightSpotDir1;
uniform vec3 spotlightDiffuseColor1;
uniform vec3 spotlightAmbientColor1;
uniform float spotlightKc1;
uniform float spotlightKl1;
uniform float spotlightKq1;
uniform float spotlightCutoff1;

// Green spotlight parameters
uniform vec3 spotlightLightPos2;
uniform vec3 spotlightSpotDir2;
uniform vec3 spotlightDiffuseColor2;
uniform vec3 spotlightAmbientColor2;
uniform float spotlightKc2;
uniform float spotlightKl2;
uniform float spotlightKq2;
uniform float spotlightCutoff2;

// Blue spotlight parameters
uniform vec3 spotlightLightPos3;
uniform vec3 spotlightSpotDir3;
uniform vec3 spotlightDiffuseColor3;
uniform vec3 spotlightAmbientColor3;
uniform float spotlightKc3;
uniform float spotlightKl3;
uniform float spotlightKq3;
uniform float spotlightCutoff3;

// Calculates spotlight lighting
vec4 calculateSpotlight(
    vec3 lightPosition, 
    vec3 spotDir, 
    vec3 diffuseColor, 
    vec3 ambientColor, 
    float kc,
    float kl,
    float kq,
    float cuttoff
) {
    vec3 objColor = vec3(1.0, 1.0, 1.0);
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPosition - FragPos);
    vec3 ambient = ambientColor * objColor;

    float theta = dot(lightDir, -normalize(spotDir));

    if(theta > cos(cuttoff)) {
        float diff = max(dot(norm, lightDir), 0.0);
        float distance = length(lightPosition - FragPos);
        float attenuation = 1.0 / (kc + kl * distance + kq * distance * distance);
        vec3 diffuse = diffuseColor * objColor * diff * attenuation;
        return vec4(ambient + diffuse, 1.0);
    } else {
        return vec4(ambient, 1.0);
    }
}

// The main body of the shader when the system is not in debug mode
void mainBody() {
    vec4 red = calculateSpotlight(
        spotlightLightPos1, 
        spotlightSpotDir1, 
        spotlightDiffuseColor1, 
        spotlightAmbientColor1,
        spotlightKc1,
        spotlightKl1,
        spotlightKq1,
        spotlightCutoff1
    );
    
    vec4 green = calculateSpotlight(
        spotlightLightPos2, 
        spotlightSpotDir2, 
        spotlightDiffuseColor2, 
        spotlightAmbientColor2,
        spotlightKc2,
        spotlightKl2,
        spotlightKq2,
        spotlightCutoff2
    );
    
    vec4 blue = calculateSpotlight(
        spotlightLightPos3, 
        spotlightSpotDir3, 
        spotlightDiffuseColor3, 
        spotlightAmbientColor3,
        spotlightKc3,
        spotlightKl3,
        spotlightKq3,
        spotlightCutoff3
    );
    
    vec4 textColor = texture(Texture, TextCoord);
    FragColor = textColor * red + textColor * green + textColor * blue;
}

void main() {
    if(vecColor == vec3(-1.0, -1.0, -1.0)) { // If the system is not in debug mode, ignore vecColor
        mainBody();
    } else {
        FragColor = vec4(vecColor, 1.0);
    }
}