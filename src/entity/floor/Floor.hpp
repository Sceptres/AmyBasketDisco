#ifndef FLOOR_ENTITY_CLASS

#define FLOOR_ENTITY_CLASS

#include "../Entity.hpp"
#include "../../mesh/Mesh.hpp"

class Floor : public Entity {
    public:
        /**
         * Initializes an Floor entity
         * 
         * @param[in] bucketMesh The mesh to use to render the Floor entity
         * @param[in] initPosition The initial position of the Floor entity
         * @param[in] scale The initial scale of the Floor entity
         * @param[in] angle The initial angle of the Floor entity
         * @param[in] rotateAxis The initial axis to rotate the Floor entity around
         */
        Floor(Mesh* floorMesh, glm::vec3 initPosition, GLfloat scale, GLfloat angle, glm::vec3 rotateAxis);

    private:
        Mesh* floorMesh;
        void Draw() const override;
};

#endif