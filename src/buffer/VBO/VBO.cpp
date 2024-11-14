#include "VBO.hpp"

VBO::VBO(GLfloat verticies[], GLsizeiptr size) {
    glGenBuffers(1, &(Buffer::id));
    this->Bind();
    glBufferData(GL_ARRAY_BUFFER, size, verticies, GL_STATIC_DRAW);
}

VBO::VBO(std::vector<GLfloat>& verticies, GLsizeiptr size) {
    glGenBuffers(1, &(Buffer::id));
    this->Bind();
    glBufferData(GL_ARRAY_BUFFER, size, verticies.data(), GL_STATIC_DRAW);
}

void VBO::Bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, Buffer::id);
}

void VBO::Unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Delete() {
    glDeleteBuffers(1, &(Buffer::id));
}

void VBO::UpdateData(std::vector<GLfloat>& data, GLsizeiptr size) {
    this->Bind();
    glBufferData(GL_ARRAY_BUFFER, size, data.data(), GL_STATIC_DRAW);
    this->Unbind();
}