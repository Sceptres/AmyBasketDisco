#ifndef EBO_CLASS 

#define EBO_CLASS

#include <iostream>
#include <glad/glad.h>
#include "../Buffer.hpp"

/**
 * A class that represents a Element Buffer Object (EBO) used to store and send VBO indices in OpenGL.
 */
class EBO : public Buffer {
    public:
        /**
         * Instantiate an EBO
         * 
         * @param[in] indices The array of indices of the VBO
         * @param[in] size The size of the EBO data set
         */
        EBO(GLuint indices[], GLsizeiptr size);

        /**
         * Instantiate an EBO
         * 
         * @param[in] indices The vector containing the indices of the VBO
         * @param[in] size The size of the EBO data set
         */
        EBO(std::vector<GLuint>& indices, GLsizeiptr size);

        /**
         * Binds the EBO
         */
        void Bind() const override;

        /**
         * Unbinds the EBO
         */
        void Unbind() const override;

        /**
         * Deletes the EBO
         */
        void Delete() override;
};

#endif