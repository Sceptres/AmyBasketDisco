#include "Light.hpp"

Light::Light(
    glm::vec3 pos,
    Color diffuseColor, 
    Color ambientColor, 
    float kc, 
    float kl, 
    float kq, 
    std::string shaderPrefix, 
    std::string shaderPostfix
) : pos(pos), 
    kc(kc), 
    kl(kl), 
    kq(kq), 
    diffuseColor(diffuseColor), 
    ambientColor(ambientColor),
    shaderPrefix(shaderPrefix),
    shaderPostfix(shaderPostfix) {}

void Light::Apply(ShaderProgram& shaderProgram) const {
    // Each light parameter has the format shaderPrefix{variable name}shaderPostfix in the shader
    std::string posName = this->shaderPrefix + "LightPos" + this->shaderPostfix;
    std::string diffuseColorName = this->shaderPrefix + "DiffuseColor" + this->shaderPostfix;
    std::string ambientColorName = this->shaderPrefix + "AmbientColor" + this->shaderPostfix;
    std::string kcName = this->shaderPrefix + "Kc" + this->shaderPostfix;
    std::string klName = this->shaderPrefix + "Kl" + this->shaderPostfix;
    std::string kqName = this->shaderPrefix + "Kq" + this->shaderPostfix;

    glm::vec3 diffuseColorVec = glm::vec3(
        this->diffuseColor.r, 
        this->diffuseColor.g, 
        this->diffuseColor.b
    );

    glm::vec3 ambientColorVec = glm::vec3(
        this->ambientColor.r, 
        this->ambientColor.g, 
        this->ambientColor.b
    );

    shaderProgram.setVec3(posName, this->pos);
    shaderProgram.setVec3(diffuseColorName, diffuseColorVec);
    shaderProgram.setVec3(ambientColorName, ambientColorVec);
    shaderProgram.setFloat(kcName, this->kc);
    shaderProgram.setFloat(klName, this->kl);
    shaderProgram.setFloat(kqName, this->kq);
}