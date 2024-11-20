#ifndef AMY_ENTITY_CLASS

#define AMY_ENTITY_CLASS

#include "../Entity.hpp"
#include "../../mesh/Mesh.hpp"

class Amy : public Entity {
    public:
        /**
         * Initializes an Amy entity
         * 
         * @param[in] amyMesh The mesh to use to render the Amy entity
         * @param[in] initPosition The initial position of the Amy entity
         * @param[in] scale The initial scale of the Amy entity
         * @param[in] angle The initial angle of the Amy entity
         * @param[in] rotateAxis The initial axis to rotate the Amy entity around
         */
        Amy(Mesh* amyMesh, glm::vec3 initPosition, GLfloat scale, GLfloat angle, glm::vec3 rotateAxis);

    private:
        Mesh* amyMesh;
        virtual void Draw() const override;
};

#endif