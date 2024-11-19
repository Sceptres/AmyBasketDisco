#ifndef TEXTURE_CLASS

#define TEXTURE_CLASS

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../Buffer.hpp"
#include "../../image/stb_image.h"
#include <iostream>

class Texture : public Buffer {
    public:
        /**
         * Initializes a texture by loading data from file
         * 
         * @param[in] source The path to the texture file
         */
        Texture(const char* source);

        /**
         * Binds the Texture Buffer
         */
        void Bind() const override;

        /**
         * Unbinds the Texture Buffer
         */
        void Unbind() const override;

        /**
         * Deletes the Texture Buffer
         */
        void Delete() override;
};

#endif