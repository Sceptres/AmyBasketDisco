#ifndef VAO_CLASS

#define VAO_CLASS

#include <glad/glad.h>
#include "../buffer/Buffer.hpp"

/**
 * A class that represents a Vertex Array Object (VAO) used to render vertices in OpenGL.
 */
class VAO {
    public:
        /**
         * Instantiate a Vertex Access Object (VAO)
         */
        VAO();

        /**
         * Access method for the id of the VAO
         * 
         * @returns GLuint Return a GL unsigned int representing the id of the VAO
         */
        GLuint getId();

        /**
         * Links data of the VBO to a layout variable in the vertex shader
         * 
         * @param[in] layout The layout number of the vertex shader variable to link to
         * @param[in] stride The stride to jump over to get to the next data point
         * @param[in] offset The offset to start at for this data point 
         */
        void LinkBuffers(GLuint layout, GLuint stride, void* offset);

        /**
         * Binds the VAO
         */
        void Bind();
        
        /**
         * Unbinds the VAO
         */
        void Unbind();
        
        /**
         * Deletes the VAO
         */
        void Delete();

    private:
        GLuint id;

};

#endif