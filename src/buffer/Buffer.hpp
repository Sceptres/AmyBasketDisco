#ifndef BUFFER_CLASS

#define BUFFER_CLASS

#include <glad/glad.h>

/**
 * A parent class used to represent all OpenGL buffers
 */
class Buffer {
    protected:
        Buffer() {};
        GLuint id;

    public:
        /**
         * Binds the buffer
         */
        virtual void Bind() const = 0;
        
        /**
         * Unbinds the buffer
         */
        virtual void Unbind() const = 0;
        
        /**
         * Deletes the buffer
         */
        virtual void Delete() = 0;

        /**
         * The access method to the id of the buffer
         * @returns GLuint Returns an GL unsigned int representing the id of the buffer
         */
        GLuint getId();
};

#endif