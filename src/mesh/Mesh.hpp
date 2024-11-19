#ifndef MESH_CLASS

#define MESH_CLASS

#include <iostream>
#include <tiny_obj_loader.h>
#include "exception/FailedToLoadMeshException.hpp"
#include "../buffer/VBO/VBO.hpp"
#include "../buffer/EBO/EBO.hpp"
#include "../array/VAO.hpp"
#include "../buffer/texture/Texture.hpp"

/**
 * The class representing a Wavefront obj mesh
 */
class Mesh {
    public:
        /**
         * Instantiate a mesh given its path
         * 
         * @param[in] source The path to the wavefront obj mesh
         * @param[in] texture The path to the texture of this mesh
         */
        Mesh(const char* source, const char* texture);

        /**
         * Mesh destructor that deletes VAO and VBO instances
         */
        ~Mesh();
        
        /**
         * Initialize the OpenGL components of the mesh
         */
        void GLInit();

        /**
         * Access method to the amount of vertices in the mesh
         * 
         * @returns The number of unique vertices in the mesh
         */
        GLuint getVertexCount();

        /**
         * Access method to the amount of normals in the mesh
         * 
         * @returns The number of unique normals in the mesh
         */
        GLuint getNormalCount();
        
        /**
         * Access method to the amount of data points in the mesh
         * 
         * @returns The number of data points in the mesh data
         */
        GLuint getMeshDataSize();
        
        /**
         * Binds the mesh VAO
         */
        void Bind();
        
        /**
         * Unbinds the mesh VAO
         */
        void Unbind();
        
        /**
         * Deletes the mesh VAO and VBO
         */
        void Delete();

        /**
         * Access method to the attributes of this mesh
         * 
         * @return tinyobj::attrib_t The tinyobj::attrib_t object that holds the attributes of this mesh
         */
        tinyobj::attrib_t& getAttrib();

    protected:
        VAO* vao;
        VBO* vbo;
        Texture* texture;
        tinyobj::attrib_t attrib;
        std::vector<GLfloat> verticies;
        std::vector<GLfloat> normals;
        std::vector<GLfloat> meshData;
        std::vector<tinyobj::shape_t> shapes;
        std::vector<tinyobj::material_t> materials;
};

#endif