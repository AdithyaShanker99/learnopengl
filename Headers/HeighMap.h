#ifndef HEIGHTMAP_H
#define HEIGHTMAP_H

#include<vector>

#include"VAO.h"
#include"EBO.h"
#include "VBO.h"
#include"Textures.h"

class heightMap
{
public:
	std::vector <float> vertices;
    std::vector <float> normals;
    std::vector <GLuint> indices;

    std::vector <float> createVertices(const char* filePath);
    std::vector <GLuint> createIndices();
    std::vector <float> createNormals();

};
#endif