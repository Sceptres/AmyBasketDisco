#ifndef BUCKET_ENTITY_CLASS

#define BUCKET_ENTITY_CLASS

#include "../Entity.hpp"
#include "../../mesh/Mesh.hpp"

class Bucket : public Entity {
    public:
        /**
         * Initializes an Bucket entity
         * 
         * @param[in] bucketMesh The mesh to use to render the Bucket entity
         * @param[in] initPosition The initial position of the Bucket entity
         * @param[in] scale The initial scale of the Bucket entity
         * @param[in] angle The initial angle of the Bucket entity
         * @param[in] rotateAxis The initial axis to rotate the Bucket entity around
         */
        Bucket(Mesh* bucketMesh, glm::vec3 initPosition, GLfloat scale, GLfloat angle, glm::vec3 rotateAxis);

    private:
        Mesh* bucketMesh;
        virtual void Draw() const override;
};

#endif