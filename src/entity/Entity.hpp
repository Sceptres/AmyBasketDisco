#ifndef ENTITY_CLASS

#define ENTITY_CLASS

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include "../shader/ShaderProgram.hpp"

/**
 * The parent class representing an entity in the system
 */
class Entity {
    public:
        /**
         * An access method for the position of the entity
         * 
         * @returns glm::vec3 The position of the entity
         */
        glm::vec3 getPosition() const;

        /**
         * A method to move an entity to a new position
         * 
         * @param[in] newPosition The position to move the entity to
         */
        virtual void MoveTo(glm::vec3 newPosition);

        /**
         * A method to rotate an entity by an angle around a certain axis
         * 
         * @param[in] rotationAxis The axis to rotate the entity around
         * @param[in] angle The angle to rotate the entity by
         */
        virtual void Rotate(glm::vec3 rotationAxis, GLfloat angle);

        /**
         * A method that scales an entity by a certian factor
         * 
         * @param[in] scale The scaling factor
         */
        virtual void Scale(GLfloat scale);

        /**
         * Renders the entity in the world
         * 
         * @param[out] shaderProgram The shader program to render the entity in
         */
        void Render(ShaderProgram& shaderProgram);

    protected:
        glm::vec3 position;
        GLfloat scale;
        GLfloat angle;
        glm::vec3 rotateAxis;
        glm::mat4 model;

        /**
         * A protected constructor used to instantiate the entity super class
         * 
         * @param[in] initPosition The initial position of the entity in the world space
         * @param[in] scale The scaling factor of the entity
         * @param[in] angle The initial angle to rotate the entity by
         * @param[in] rotateAxis The initial axis to rotate the entity around
         */
        Entity(glm::vec3 initPosition, GLfloat scale, GLfloat angle, glm::vec3 rotateAxis);

        /**
         * Sets the position of the entity by updating the model matrix
         * 
         * @param[in] newPosition The new position of the entity
         */
        virtual void setPosition(glm::vec3 newPosition);

        /**
         * Applies the transformations of the entity to the entity model
         */
        virtual void ApplyTransformations();

        /**
         * Updates the shader of the entity by updating the model matrix
         */
        virtual void UpdateShader(ShaderProgram& shaderProgram);

        /**
         * A method that is set by every entity as to how the entity should be drawn
         */
        virtual void Draw() const = 0;
};

#endif