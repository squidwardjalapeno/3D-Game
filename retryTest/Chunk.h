#ifndef CHUNK_H
#define CHUNK_H

#include "vbo.h" 
#include <vector>
#include <glad/glad.h> // Or your OpenGL loader
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


enum FaceDirection { TOP, BOTTOM, LEFT, RIGHT, FRONT, BACK };

class World; // Forward declaration to avoid circular dependency

class Chunk {
public:
    // 1. Position and Data
    int worldX, worldZ;
    unsigned char data[16][16][16]; // 0 = Air, 1 = Stone, etc.

    // 2. OpenGL Handles
    unsigned int vao, vbo, ebo;
    int indexCount = 0;

    Chunk(int x, int z);
    ~Chunk();

    void generateTerrain();
    void rebuildMesh(World* world);
    void render(unsigned int shaderProgram);


    bool isSolid(int x, int y, int z);
    void addFace(std::vector<Vertex>& vertices, std::vector<unsigned int>& indices, int x, int y, int z, FaceDirection dir);

    bool needsMeshUpdate = true;
};

#endif
#pragma once
