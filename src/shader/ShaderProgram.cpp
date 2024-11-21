#include "ShaderProgram.hpp"

std::string ShaderProgram::get_shader_content(const char* file) {
    std::ifstream in(file, std::ios::binary);
    
    if(in) {
        std::string contents;
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        in.close();

        return(contents);
    }

    throw(errno);
}

ShaderProgram::ShaderProgram(const char* vertexShaderFile, const char* fragmentShaderFile) {
    int  success;
    char infoLog[512];

    // Load vertex and fragment shader contents
    std::string vertexShaderStr = ShaderProgram::get_shader_content(vertexShaderFile);
    std::string fragmentShaderStr = ShaderProgram::get_shader_content(fragmentShaderFile);
    const char* vertexShaderSource = vertexShaderStr.c_str();
    const char* fragmentShaderSource = fragmentShaderStr.c_str();

    // Create the vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if(!success) {
        // Vertex shader creation has failed
        glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // Create the fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    if(!success) {
        // Fragment shader creation has failed
        glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // Create the shader program
    this->id = glCreateProgram();
    glAttachShader(this->id, vertexShader);
    glAttachShader(this->id, fragmentShader);
    glLinkProgram(this->id);
    glGetProgramiv(this->id, GL_LINK_STATUS, &success);

    if(!success) {
        // Shader program creation has failed
        glGetShaderInfoLog(this->id, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    // Delete vertex and fragment shaders
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

GLuint ShaderProgram::getId() {
    return this->id;
}

void ShaderProgram::Activate() {
    glUseProgram(this->id);
}

void ShaderProgram::Delete() {
    glDeleteProgram(this->id);
}

void ShaderProgram::setMat4(const std::string& name, glm::mat4 value) {
    int loc = glGetUniformLocation(this->id, name.c_str());
    glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(value));
}

void ShaderProgram::setVec3(const std::string& name, glm::vec3 value) {
    int loc = glGetUniformLocation(this->id, name.c_str());
    glUniform3fv(loc, 1, &value[0]);
}

void ShaderProgram::setBool(const std::string& name, GLboolean value) {
    int loc = glGetUniformLocation(this->id, name.c_str());
    glUniform1i(loc, value);
}

void ShaderProgram::setInt(const std::string& name, GLint value) {
    int loc = glGetUniformLocation(this->id, name.c_str());
    glUniform1i(loc, value);
}