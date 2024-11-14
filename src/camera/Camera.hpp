#ifndef CAMERA_CLASS

#define CAMERA_CLASS

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../shader/ShaderProgram.hpp"

/**
 * A class representing a camera that uses a perspective projection through which the user views the world
 */
class Camera {
    public:
        /**
         * Instantiate a camera
         * 
         * @param[in] startPos The start position of the camera
         * @param[in] fov The field of view of the camera
         * @param[in] aspectRatio The aspect ratio of the camera to render on the screen with
         * @param[in] nearPlaneDistance The distance from the camera's position to the near plane
         * @param[in] farPlaneDistance The distance from the camera's postion to the far plane
         */
        Camera(const glm::vec3 startPos, GLfloat fov, GLfloat aspectRatio, GLfloat nearPlaneDistance, GLfloat farPlaneDistance);

        /**
         * Apply the camera to the shader program, sending the view and projection matrices to the vertex shader
         * 
         * @param[out] shaderProgram The shader program to use to set the view and projection matrices
         */
        void Apply(ShaderProgram& shaderProgram);

        /**
         * Sets the location at which the camera should look at
         * 
         * @param[in] target The world position that the camera should look at
         */
        void LookAt(glm::vec3 target);

        /**
         * Moves the camera to the given position
         * 
         * @param[in] newPosition The position to move the camera to
         */
        void MoveTo(glm::vec3 newPosition);

        /**
         * Access method for the position of the camera
         * 
         * @returns glm::vec3 A 3D vector representing the cameras current position in the world
         */
        glm::vec3 getPosition();

    private:
        glm::vec3 position;
        glm::vec3 target;
        glm::vec3 up;
        glm::mat4 view;
        glm::mat4 projection;

        /**
         * Updates the view matrix of the camera based on its position and target
         * 
         * @param[in] pos The current position of the camera
         * @param[in] target The point the camera is currently looking at
         */
        void UpdateStates(glm::vec3 pos, glm::vec3 target);
};

#endif