#ifndef DEBUG_FILTER_CLASS

#define DEBUG_FILTER_CLASS

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../input/InputHandler.hpp"
#include "../shader/ShaderProgram.hpp"

/**
 * A class that represents a debug mode where rendered items are rendered in wireframe mode
 */
class DebugFilter {
    public:
        /**
         * Instantiate the debug filter
         */
        DebugFilter();

        /**
         * An access method that provides if the system is in debug mode
         * 
         * @returns bool True if the system is in debug mode. False otherwise.
         */
        bool IsInDebugMode();

        /**
         * Applys the debug filter to the input handler to add callback action to the debug key
         * 
         * @param[out] inputHandler The input handler of the system to register the debug filter key
         */
        void ApplyToInputHandler(InputHandler& inputHandler);

        /**
         * Applys the debug filter to the shader to toggle debug mode in the vertex and fragment shaders
         * 
         * @param[out] shaderProgram The shader program to apply the debug filter to
         */
        void HandleDebugShader(ShaderProgram& shaderProgram);

    private:
        bool isInDebugMode;

        /**
         * The callback that is used to toggle the debug mode
         * 
         * @param[out] window The window instance of the application
         */
        void ToggleDebugMode(GLFWwindow* window);
};

#endif