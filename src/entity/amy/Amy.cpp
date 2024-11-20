#include "Amy.hpp"

// Amy constructor that feeds Entity super constructor
Amy::Amy(Mesh* amyMesh, glm::vec3 initPosition, GLfloat scale, GLfloat angle, glm::vec3 rotateAxis) :
    Entity(initPosition, scale, angle, rotateAxis) {
        this->amyMesh = amyMesh;
    }

void Amy::Draw() const {
    this->amyMesh->Bind();
    glDrawArrays(GL_TRIANGLES, 0, this->amyMesh->getMeshDataSize());
    this->amyMesh->Unbind();
}