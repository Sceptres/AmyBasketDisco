#ifndef INPUT_HANDLER_CLASS

#define INPUT_HANDLER_CLASS

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <map>
#include <functional>

/**
 * A class representing the keyboard/mouse input handler of the system
 */
class InputHandler {
    public:
        /**
         * Instantiate the input handler
         * 
         * @param[in, out] window The window of the application
         */
        InputHandler(GLFWwindow* window);

        /**
         * Registers a key and its click callback
         * 
         * @param[in] key The key to register
         * @param[in] holdable True if the key can be held down. False if it is only one click.
         * @param[in] func The callback function to run when the key is clicked
         */
        void AddKeyCallback(int key, bool holdable, std::function<void(GLFWwindow*)> func);

        /**
         * Processes all the registered keys input. This method should be called in the main loop.
         */
        void ProcessInput();

    private:
        GLFWwindow* window;
        std::map<int, std::function<void(GLFWwindow*)>> keyFuncMap;
        std::map<int, bool> keyHoldableMap;
        std::map<int, bool> keyPressedMap;
};

#endif