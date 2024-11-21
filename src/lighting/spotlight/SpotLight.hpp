#ifndef SPOTLIGHT_CLASS

#define SPOTLIGHT_CLASS

#include "../Light.hpp"

class SpotLight : public Light {
    public:
        /**
         * Initializes a spotlight
         * 
         * @param[in] pos The position of the spotlight
         * @param[in] spotDir The direction the spotlight is pointing at
         * @param[in] diffuseColor The diffuse color of the spotlight
         * @param[in] ambientColor The ambient color of the spotlight
         * @param[in] kc The light constant of the spotlight
         * @param[in] kl The linear constant of the spotlight
         * @param[in] kq The quadratic constant of the spotlight
         * @param[in] cutoff The cutoff angle of the spotlight
         */
        SpotLight(
            glm::vec3 pos,
            glm::vec3 spotDir,
            Color diffuseColor, 
            Color ambientColor, 
            float kc, 
            float kl, 
            float kq,
            float cutoff
        );

        /**
         * Rotates a spotlights direction around the Y-Axis by theta
         * 
         * @param[in] theta The angle to rotate the spotlight by
         */
        void RotateY(float theta);

        virtual void Apply(ShaderProgram& shaderProgram) const override;

    private:
        static unsigned int count;
        float cutoff;
        glm::vec3 spotDir;
        glm::vec3 spotDirRotated;
};

#endif