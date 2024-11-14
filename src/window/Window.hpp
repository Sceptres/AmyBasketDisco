#ifndef WINDOW_CLASS

#define WINDOW_CLASS

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include "exception/WindoNotCreatedException.hpp"
#include "exception/GladInitFailedException.hpp"
#include "../input/InputHandler.hpp"
#include "../color/Color.hpp"

/**
 * A class representing a system Window
 */
class Window {
    public:
        /**
         * Instantiate a window
         * 
         * @param[in] width The width of the window
         * @param[in] height The height of the window
         * @param[in] isResizable True if the window is resizable. False if the windows size is fixed
         * @param[in] title The title of the window
         */
        Window(unsigned int width, unsigned int height, bool isResizable, std::string title);
        
        /**
         * A window destructor that destroys the GLFW window
         */
        ~Window();

        /**
         * An access method to the GLFW window instance
         * 
         * @returns GLFWwindow* The GLFW window instance
         */
        GLFWwindow* getGLWindow();

        /**
         * A method that provides updates as to whether the window should close
         * 
         * @returns True if the window should close. False otherwise.
         */
        bool ShouldClose();

        /**
         * Launches a window
         */
        void Launch();

        /**
         * Registers the ESC key to close the window when clicked
         * 
         * @param[out] inputHandler The input handler to register the key callback to
         */
        void ApplyCloseWindowToInputHandler(InputHandler& inputHandler);

        /**
         * Swaps the back and front buffers
         */
        void SwapBuffers();

        /**
         * Sets the background color of the window
         * 
         * @param[in] color The color to set the backround color to
         */
        void ClearColor(Color& color);

    private:
        GLFWwindow* window;
        unsigned int width;
        unsigned int height;

        /**
         * The callback that handles changes to the window size
         * 
         * @param[in, out] glfwWindow The GLFW window
         * @param[in] width The new width of the window
         * @param[in] height The new height of the window
         */
        static void framebuffer_size_callback(GLFWwindow* glfwWindow, int width, int height);
};

#endif