#include "SpotLight.hpp"

unsigned int SpotLight::count = 0;

SpotLight::SpotLight(
    glm::vec3 pos,
    glm::vec3 spotDir,
    Color diffuseColor, 
    Color ambientColor, 
    float kc, 
    float kl, 
    float kq, 
    float cutoff
) : Light(
        pos,
        diffuseColor, 
        ambientColor, 
        kc, 
        kl, 
        kq, 
        "spotlight", // Spotlight parameters look like spotlight{Parameter Name}{Spotlight ID} in the shader
        std::to_string(SpotLight::count+1)
    ), cutoff(cutoff), spotDir(spotDir), spotDirRotated(spotDir) {
        SpotLight::count += 1;
}

void SpotLight::RotateY(float theta) {
    this->spotDirRotated.x = sin(theta) * this->spotDir.x;
    this->spotDirRotated.z = cos(theta) * this->spotDir.z;
}

void SpotLight::Apply(ShaderProgram& shaderProgram) const {
    Light::Apply(shaderProgram);

    // Spotlight direction and cutoff angle variables
    std::string cutoffName = Light::shaderPrefix + "Cutoff" + Light::shaderPostfix;
    std::string spotDirName = Light::shaderPrefix + "SpotDir" + Light::shaderPostfix;
    
    shaderProgram.setFloat(cutoffName, this->cutoff);
    shaderProgram.setVec3(spotDirName, this->spotDirRotated);
}