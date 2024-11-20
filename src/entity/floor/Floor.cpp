#include "Floor.hpp"

Floor::Floor(Mesh* floorMesh, glm::vec3 initPosition, GLfloat scale, GLfloat angle, glm::vec3 rotateAxis) :
    Entity(initPosition, scale, angle, rotateAxis) {
        this->floorMesh = floorMesh;
    }

void Floor::Draw() const {
    this->floorMesh->Bind();
    glDrawArrays(GL_TRIANGLES, 0, this->floorMesh->getMeshDataSize());
    this->floorMesh->Unbind();
}