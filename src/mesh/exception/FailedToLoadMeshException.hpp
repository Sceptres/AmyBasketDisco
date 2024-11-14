#ifndef FAILED_TO_LOAD_MESH_EXCEPTION_CLASS

#define FAILED_TO_LOAD_MESH_EXCEPTION_CLASS

#include <iostream>

/**
 * A class that represents the failed loading of a mesh
 */
class FailedToLoadMeshException : public std::exception {
    public:
        FailedToLoadMeshException(const char* filePath) {
            this->path = filePath;
        }
        const char* what() const noexcept override {
            return strcat("Failed to load the mesh located at ", this->path);
        }

    private:
        const char* path;
};

#endif