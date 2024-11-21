#ifndef TINYOBJLOADER_IMPLEMENTATION
#define TINYOBJLOADER_IMPLEMENTATION
#endif

#include <iostream>
#include <numbers>
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
#include "entity/amy/Amy.hpp"
#include "entity/bucket/Bucket.hpp"
#include "entity/floor/Floor.hpp"
#include "lighting/spotlight/SpotLight.hpp"

DebugFilter debug; // The debug filter that renders shapes as lines
PPMCapture capturer; // Captures the contents of the window as a PPM

int main() {
	try {
		glfwInit();

		// Create and startup window
		Window window(1024, 576, false, "Amy, Bucket, and Disco");
		window.Launch();

		// Input handler that processes clicks of registered keys
		InputHandler inputHandler(window.getGLWindow());
		window.ApplyCloseWindowToInputHandler(inputHandler);
		debug.ApplyToInputHandler(inputHandler);
		capturer.ApplyToInputHandler(inputHandler);

		// Load shader program from the disk
		ShaderProgram shaderProgram("resources/shaders/default.vert", "resources/shaders/default.frag");

		// Load meshes
		Mesh* amyMesh = new Mesh("resources/meshes/Amy.obj", "resources/meshes/Amy.png");
		Mesh* bucketMesh = new Mesh("resources/meshes/bucket.obj", "resources/meshes/bucket.jpg");
		Mesh* floorMesh = new Mesh("resources/meshes/floor.obj", "resources/meshes/floor.jpg");

		// Setup meshes
		amyMesh->GLInit();
		bucketMesh->GLInit();
		floorMesh->GLInit();

		// Setup entities
		Amy amy(amyMesh, glm::vec3(0), 1, 0, glm::vec3(0));
		Bucket bucket(bucketMesh, glm::vec3(0), 1, 0, glm::vec3(0));
		Floor floor(floorMesh, glm::vec3(0), 1, 0, glm::vec3(0));

		// Setup spotlights
		// Constant spotlight parameters
		glm::vec3 spotlightPos(0, 200, 0);
		Color ambientColor(0.2, 0.2, 0.2);
		float kc = 1;
		float kl = 0.000035;
		float kq = 0.000044;
		float cuttof = std::numbers::pi / 6;

		// Spotlight objects
		SpotLight red(
			spotlightPos,
			glm::vec3(50, -200, -50), 
			Color(1, 0, 0), 
			ambientColor, 
			kc, 
			kl, 
			kq,
			cuttof
		);

		SpotLight green(
			spotlightPos,
			glm::vec3(-50, -200, -50), 
			Color(0, 1, 0), 
			ambientColor, 
			kc, 
			kl, 
			kq,
			cuttof
		);

		SpotLight blue(
			spotlightPos,
			glm::vec3(0, -200, 50), 
			Color(0, 0, 1), 
			ambientColor, 
			kc, 
			kl, 
			kq,
			cuttof
		);

		// Setup the camera
		Camera camera(glm::vec3(0, 100, 180), 60.0f, 16.0f/9.0f, 0.1f, 1000.0f);
		camera.LookAt(glm::vec3(0, 80, 0));

		// Background color of the window
		Color backgroundColor(0.3, 0.4, 0.5, 1.0f);

		float theta = 0.0;

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

			// Rotate spotlights
			red.RotateY(theta);
			green.RotateY(theta);
			blue.RotateY(theta);

			// Apply lights
			red.Apply(shaderProgram);
			green.Apply(shaderProgram);
			blue.Apply(shaderProgram);

			// Render Entities
			amy.Render(shaderProgram);
			bucket.Render(shaderProgram);
			floor.Render(shaderProgram);

			// Update spotlight rotation
			theta += 0.05f;

			// Swap back and front buffers
			window.SwapBuffers();

			// Poll keyboard input
			glfwPollEvents();
		}

		// Delete shader program
		shaderProgram.Delete();

		// Delete meshes
		amyMesh->Delete();
		bucketMesh->Delete();
		floorMesh->Delete();
		delete amyMesh;
		delete bucketMesh;
		delete floorMesh;

		glfwTerminate();

		return 0;
	} catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
		glfwTerminate();
		return -1;
	}
}