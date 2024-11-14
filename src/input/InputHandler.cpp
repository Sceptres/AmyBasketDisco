#include "InputHandler.hpp"

InputHandler::InputHandler(GLFWwindow* window) {
    this->window = window;
}

void InputHandler::AddKeyCallback(int key, bool holdable, std::function<void(GLFWwindow*)> func) {
    this->keyFuncMap[key] = func;
    this->keyHoldableMap[key] = holdable;
    this->keyPressedMap[key] = false;
}

void InputHandler::ProcessInput() {
    for(auto const& [key, func] : this->keyFuncMap) {
        if(glfwGetKey(this->window, key) == GLFW_PRESS) {
            if(this->keyHoldableMap[key] || !this->keyPressedMap[key]) { // Single click for button
                func(this->window);
                this->keyPressedMap[key] = true;
            }
        } else {
            this->keyPressedMap[key] = false;
        }
    }
}