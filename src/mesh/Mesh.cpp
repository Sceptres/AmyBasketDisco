#include "Mesh.hpp"

Mesh::Mesh(const char* source, const char* texture) {
    std::string warn, err;
    bool bTriangulate = true;

    // Load obj mesh
    bool bSuc = tinyobj::LoadObj(
        &this->attrib,
        &this->shapes,
        &this->materials,
        &warn,
        &err,
        source,
        nullptr,
        bTriangulate
    );

    if (!warn.empty()) {
        std::cout << "TinyObj Warning: " << warn << std::endl;
    }

    if(!bSuc) {
        std::cout << "TinyObj Error" << err << std::endl;
        throw FailedToLoadMeshException(source);
    }

    // Store verticies
    for(int i=0; i < this->attrib.vertices.size(); i+=3) {
        this->verticies.push_back(this->attrib.vertices[i]);
        this->verticies.push_back(this->attrib.vertices[i+1]);
        this->verticies.push_back(this->attrib.vertices[i+2]);
    }

    // Store normals
    for(int i=0; i < this->attrib.normals.size(); i+=3) {
        this->normals.push_back(this->attrib.normals[i]);
        this->normals.push_back(this->attrib.normals[i+1]);
        this->normals.push_back(this->attrib.normals[i+2]);
    }

    for(const auto& shape : this->shapes) {
        for(const auto& face : shape.mesh.indices) {
            unsigned int vid = face.vertex_index;
            unsigned int nid = face.normal_index;
            unsigned int tid = face.texcoord_index;

            // Get vertex coordinates
            GLfloat vertX = this->attrib.vertices[vid*3];
            GLfloat vertY = this->attrib.vertices[vid*3+1];
            GLfloat vertZ = this->attrib.vertices[vid*3+2];

            // Get normal coordinates
            GLfloat normX = this->attrib.normals[nid*3];
            GLfloat normY = this->attrib.normals[nid*3+1];
            GLfloat normZ = this->attrib.normals[nid*3+2];

            // Get texture coordinates
            GLfloat textureU = this->attrib.texcoords[tid*2];
            GLfloat textureV = this->attrib.texcoords[tid*2+1];

            // Store vertices and normal together for VBO
            this->meshData.push_back(vertX);
            this->meshData.push_back(vertY);
            this->meshData.push_back(vertZ);
            this->meshData.push_back(normX);
            this->meshData.push_back(normY);
            this->meshData.push_back(normZ);
            this->meshData.push_back(textureU);
            this->meshData.push_back(textureV);
        }
    }

    // Load texture
    this->texture = new Texture(texture);
}

Mesh::~Mesh() {
    delete this->vao;
    delete this->vbo;
    delete this->texture;
}

void Mesh::GLInit() {
    // Create VAO
    this->vao = new VAO();
    this->vao->Bind();

    // Create VBO
    this->vbo = new VBO(this->meshData, this->meshData.size() * sizeof(GLfloat));

    // Link VBO to VAO
    GLuint stride = 8 * sizeof(GLfloat);
    this->vao->LinkBuffers(0, stride, (void*) 0);
    this->vao->LinkBuffers(1, stride, (void*) (3 * sizeof(GLfloat)));
    this->vao->LinkBuffers(2, stride, (void*) (6 * sizeof(GLfloat)));

    // Unbind both VAO and VBO
    this->vao->Unbind();
    this->vbo->Unbind();
}

void Mesh::Bind() {
    this->texture->Bind();
    this->vao->Bind();
}

void Mesh::Unbind() {
    this->vao->Unbind();
    this->texture->Unbind();
}

void Mesh::Delete() {
    this->texture->Delete();
    this->vao->Delete();
    this->vbo->Delete();
}

GLuint Mesh::getVertexCount() {
    return this->verticies.size() / 3;
}

GLuint Mesh::getNormalCount() {
    return this->normals.size() / 3;
}

GLuint Mesh::getMeshDataSize() {
    return this->meshData.size() / 8;
}

tinyobj::attrib_t& Mesh::getAttrib() {
    return this->attrib;
}