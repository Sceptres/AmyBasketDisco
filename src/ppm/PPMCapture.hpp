#ifndef PPM_CAPTURE_CLASS
#define PPM_CAPTURE_CLASS

#include <iostream>
#include <fstream>
#include <string>
#include <glad/glad.h>
#include "../input/InputHandler.hpp"

/**
 * A class representing the screen capture into a PPM file functionality
 */
class PPMCapture {
    public:
        /**
         * Instantiate a PPMCapture instance
         */
        PPMCapture();

        /**
         * Dumps the captured pixels into a PPM file on the disk
         * 
         * @param[in] prefix The name of the file to save the captured content into
         * @param[in] width The width of the PPM image
         * @param[in] height The height of the PPM image
         */
        void Dump(std::string prefix, unsigned int width, unsigned int height);
        
        /**
         * Access method to the id of the current file
         * 
         * @returns int The integer id of the file
         */
        unsigned int getId();

        /**
         * Register the key to capture the window screen
         * 
         * @param[out] inputHandler The input handler to register the capture key to
         */
        void ApplyToInputHandler(InputHandler& inputHandler);

    private:
        unsigned int idCounter;

        /**
         * Callback to capture the window screen into PPM
         * 
         * @param[in, out] window The window instance of the application
         */
        void Capture(GLFWwindow* window);
};

#endif