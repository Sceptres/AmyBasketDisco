#include "Bucket.hpp"

Bucket::Bucket(Mesh* bucketMesh, glm::vec3 initPosition, GLfloat scale, GLfloat angle, glm::vec3 rotateAxis) : 
    Entity(initPosition, scale, angle, rotateAxis) {
        this->bucketMesh = bucketMesh;
    }

void Bucket::Draw() const {
    this->bucketMesh->Bind();
    glDrawArrays(GL_TRIANGLES, 0, this->bucketMesh->getMeshDataSize());
    this->bucketMesh->Unbind();
}