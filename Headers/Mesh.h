#ifndef MESH_CLASS_H
#define MESH_CLASS_H


#include <string>

#include "VAO.h"
#include "EBO.h"
#include "Camera.h"
#include "Textures.h"


class Mesh
{
    public:
        std::vector <Vertex> vertices;
        std::vector <GLuint> indices;
        std::vector <Texture> textures;


        VAO VAO;

        MESH
}












#endif