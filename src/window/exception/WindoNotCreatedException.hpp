#ifndef WINDOW_NOT_CREATED_EXCEPTION_CLASS

#define WINDOW_NOT_CREATED_EXCEPTION_CLASS

#include <iostream>

/**
 * A class representing the exception when the window failed to be created
 */
class WindowNotCreatedException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Failed to create a window";
        }
};

#endif