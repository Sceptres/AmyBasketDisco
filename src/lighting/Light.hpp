#ifndef LIGHT_CLASS

#define LIGHT_CLASS

#include <iostream>
#include <glm/glm.hpp>
#include "../color/Color.hpp"
#include "../shader/ShaderProgram.hpp"

class Light {
    public:
        /**
         * Applies the light to the shader
         * 
         * @param[inout] shaderProgram The shader program to apply the light to
         */
        virtual void Apply(ShaderProgram& shaderProgram) const;

    protected:
        glm::vec3 pos;
        Color diffuseColor;
        Color ambientColor;
        float kc;
        float kl;
        float kq;
        std::string shaderPrefix;
        std::string shaderPostfix;

        /**
         * Initializes a light with its parameters
         * 
         * @param[in] pos The position of the light
         * @param[in] diffuseColor The light diffuse color
         * @param[in] ambientColor The light ambient color
         * @param[in] kc The light constant
         * @param[in] kl The light linear constant
         * @param[in] kq The light quadratic constant
         * @param[in] shaderPrefix The prefix of this light in the shader program
         * @param[in] shaderPostfix The postfix of this light in the shader program
         */
        Light(
            glm::vec3 pos,
            Color diffuseColor, 
            Color ambientColor, 
            float kc, 
            float kl, 
            float kq,
            std::string shaderPrefix,
            std::string shaderPostfix
        );
};

#endif