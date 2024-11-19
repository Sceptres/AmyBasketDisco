#ifndef TINYOBJLOADER_IMPLEMENTATION
#define TINYOBJLOADER_IMPLEMENTATION
#endif

#include <iostream>
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "ppm/PPMCapture.hpp"
#include "buffer/VBO/VBO.hpp"
#include "buffer/EBO/EBO.hpp"
#include "array/VAO.hpp"
#include "shader/ShaderProgram.hpp"
#include "camera/Camera.hpp"
#include "input/InputHandler.hpp"
#include "debug/DebugFilter.hpp"
#include "window/Window.hpp"
#include "color/Color.hpp"
#include "mesh/Mesh.hpp"

DebugFilter debug; // The debug filter that renders shapes as lines
PPMCapture capturer; // Captures the contents of the window as a PPM

int main() {
	try {
		glfwInit();

		// Create and startup window
		Window window(1024, 576, false, "Facial Expressions");
		window.Launch();

		// Input handler that processes clicks of registered keys
		InputHandler inputHandler(window.getGLWindow());
		window.ApplyCloseWindowToInputHandler(inputHandler);
		debug.ApplyToInputHandler(inputHandler);
		capturer.ApplyToInputHandler(inputHandler);

		// Load shader program from the disk
		ShaderProgram shaderProgram("resources/shaders/default.vert", "resources/shaders/default.frag");

		// Setup the camera
		Camera camera(glm::vec3(0, 100, 180), 60.0f, 16.0f/9.0f, 0.1f, 1000.0f);
		camera.LookAt(glm::vec3(0, 80, 0));

		// Background color of the window
		Color backgroundColor(0.3, 0.4, 0.5, 1.0f);

		while(!window.ShouldClose()) {
			// Process user input into the window
			inputHandler.ProcessInput();

			// Set background color of the window
			window.ClearColor(backgroundColor);

			// Activate shader program
			shaderProgram.Activate();
			
			// Send info to shader
			debug.HandleDebugShader(shaderProgram);
			camera.Apply(shaderProgram);

			// Swap back and front buffers
			window.SwapBuffers();

			// Poll keyboard input
			glfwPollEvents();
		}

		// Delete shader program
		shaderProgram.Delete();
		glfwTerminate();

		return 0;
	} catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
		glfwTerminate();
		return -1;
	}
}