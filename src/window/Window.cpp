#include "Window.hpp"

Window::Window(unsigned int width, unsigned int height, bool isResizable, std::string title) {
    this->width = width;
    this->height = height;

    // Setup window hints
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, isResizable ? GLFW_TRUE : GLFW_FALSE);
	glfwWindowHint(GLFW_SAMPLES, 4); // Set multisampling count to 4
	#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    // Create the window
    this->window = glfwCreateWindow(this->width, this->height, title.c_str(), NULL, NULL);
    if(this->window == nullptr) {
        throw WindowNotCreatedException();
    }
}

Window::~Window() {
    // Destroy window
    if(this->window != nullptr)
        glfwDestroyWindow(this->window);
}

GLFWwindow* Window::getGLWindow() {
    return this->window;
}

bool Window::ShouldClose() {
    return glfwWindowShouldClose(this->window);
}

void Window::SwapBuffers() {
    glfwSwapBuffers(this->window);
}

void Window::ClearColor(Color& color) {
    glClearColor(color.r, color.g, color.b, color.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::Launch() {
    // Set window as the new context
    glfwMakeContextCurrent(this->window);
    glfwSetWindowUserPointer(this->window, this);
	
    // Load glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw GladInitFailedException();
	} 
    
    // Sets frame buffer size callback and viewport
    glfwSetFramebufferSizeCallback(window, Window::framebuffer_size_callback);
    glViewport(0, 0, this->width, this->height);

    // Enable depth testing with GL_LESS depth function
    glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS); 

    // Enable multisampling
    glEnable(GL_MULTISAMPLE);
    
    // Enable back face culling
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);
}

void Window::ApplyCloseWindowToInputHandler(InputHandler& inputHandler) {
    inputHandler.AddKeyCallback(GLFW_KEY_ESCAPE, false, [this](GLFWwindow*) {
        // Set the window to close
        glfwSetWindowShouldClose(this->window, GLFW_TRUE);
    });
}

void Window::framebuffer_size_callback(GLFWwindow* glfwWindow, int width, int height) {
    // Get the window of the system
    Window* window = (Window*) glfwGetWindowUserPointer(glfwWindow);

    if(window) {
        // Update window states
        window->width = width;
        window->height = height;
        glViewport(0, 0, window->width, window->height);
    }
}