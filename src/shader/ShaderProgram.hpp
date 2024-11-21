#ifndef SHADER_PROGRAM_CLASS

#define SHADER_PROGRAM_CLASS

#include <glad/glad.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cerrno>
#include <glm/gtc/type_ptr.hpp>

class ShaderProgram {
    public:
        /**
         * Instantiate a Shader program given the path to the vertex and fragment shaders
         * 
         * @param[in] vertexShaderSource The path to the vertex shader
         * @param[in] fragmentShaderSource The path to the fragment shader
         */
        ShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource);

        /**
         * An access method to the id of the shader program
         * 
         * @returns GLuint The id of the shader program
         */
        GLuint getId();

        /**
         * Activates a shader program
         */
        void Activate();

        /**
         * Deletes a shader program
         */
        void Delete();

        /**
         * Sets a 4D matrix variable in the vertex shader
         * 
         * @param[in] name The name of the variable in the vertex shader
         * @param[in] value The 4D matrix value to set the variable to
         */
        void setMat4(const std::string& name, glm::mat4 value);

        /**
         * Sets a 3D vector variable in the shader program
         */
        void setVec3(const std::string& name, glm::vec3 value);

        /**
         * Sets a bool variable in the vertex shader
         * 
         * @param[in] name The name of the variable in the vertex shader
         * @param[in] value The bool value to set the variable to
         */
        void setBool(const std::string& name, GLboolean value);

        /**
         * Sets an integer variable in the shader
         * 
         * @param[in] name The name of the variable in the shader
         * @param[in] value The integer value to set the variable to
         */
        void setInt(const std::string& name, GLint value);

    private:
        GLuint id;

        /**
         * Reads the contents of a shader file
         * 
         * @param[in] file The path to the shader file
         * @returns std::string A string containing all the contents of the shader file
         */
        static std::string get_shader_content(const char* file);
};

#endif