#include "Chunk.h"
#include <iostream>

Chunk::Chunk(int x, int z) : worldX(x), worldZ(z) {
    // Initialize OpenGL buffers
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

	//fuck git h ub
    generateTerrain();
    rebuildMesh();
}

void Chunk::generateTerrain() {
    for (int x = 0; x < 16; x++) {
        for (int z = 0; z < 16; z++) {
            for (int y = 0; y < 16; y++) {
                // For now, just make a solid floor
                if (y < 8) data[x][y][z] = 1;
                else data[x][y][z] = 0;
            }
        }
    }
}

bool Chunk::isSolid(int x, int y, int z) {
    if (x < 0 || x >= 16 || y < 0 || y >= 16 || z < 0 || z >= 16) return false;
    return data[x][y][z] != 0;
}

void Chunk::addFace(std::vector<Vertex>& vertices, std::vector<unsigned int>& indices, int x, int y, int z, FaceDirection dir) {
	float fx = (float)x;
	float fy = (float)y;
	float fz = (float)z;

	unsigned int offset = (unsigned int)vertices.size();

	switch (dir) {
	case TOP:

		vertices.push_back({ {-1 + fx, 1 + fy, 1 + fz}, {0, 0} });
		vertices.push_back({ {-1 + fx, 1 + fy, -1 + fz}, {0, 1} });
		vertices.push_back({ {1 + fx, 1 + fy, -1 + fz},   {1, 1} });
		vertices.push_back({ {1 + fx, 1 + fy, 1 + fz},    {1, 0} });

		indices.push_back(offset + 0);
		indices.push_back(offset + 1);
		indices.push_back(offset + 2);
		// Triangle 2
		indices.push_back(offset + 0);
		indices.push_back(offset + 2);
		indices.push_back(offset + 3);

		break;
	case BOTTOM:
		vertices.push_back({ {-1 + fx, -1 + fy, 1 + fz}, {0, 0} });
		vertices.push_back({ {-1 + fx, -1 + fy, -1 + fz}, {0, 1} });
		vertices.push_back({ {1 + fx, -1 + fy, -1 + fz},   {1, 1} });
		vertices.push_back({ {1 + fx, -1 + fy, 1 + fz},    {1, 0} });

		indices.push_back(offset + 0);
		indices.push_back(offset + 1);
		indices.push_back(offset + 2);
		// Triangle 2
		indices.push_back(offset + 0);
		indices.push_back(offset + 2);
		indices.push_back(offset + 3);

		break;
	case LEFT:
		vertices.push_back({ {-1 + fx, -1 + fy, -1 + fz}, {0, 0} });
		vertices.push_back({ {-1 + fx, 1 + fy, -1 + fz}, {0, 1} });
		vertices.push_back({ {-1 + fx, 1 + fy, 1 + fz},   {1, 1} });
		vertices.push_back({ {-1 + fx, -1 + fy, 1 + fz},    {1, 0} });

		indices.push_back(offset + 0);
		indices.push_back(offset + 1);
		indices.push_back(offset + 2);
		// Triangle 2
		indices.push_back(offset + 0);
		indices.push_back(offset + 2);
		indices.push_back(offset + 3);
		break;
	case RIGHT:
		//vertices.push_back({ {-fx, -fy, fz}, {0.0f, 0.0f, 0.0f},    {0, 0} });

		vertices.push_back({ {1 + fx, -1 + fy, 1 + fz}, {0, 0} });
		vertices.push_back({ {1 + fx, 1 + fy, 1 + fz}, {0, 1} });
		vertices.push_back({ {1 + fx, 1 + fy, -1 + fz},   {1, 1} });
		vertices.push_back({ {1 + fx, -1 + fy, -1 + fz},    {1, 0} });

		indices.push_back(offset + 0);
		indices.push_back(offset + 1);
		indices.push_back(offset + 2);
		// Triangle 2
		indices.push_back(offset + 0);
		indices.push_back(offset + 2);
		indices.push_back(offset + 3);
		/*
		vertices.push_back({ {fx + 1, fy + 1, fz + 1},{0.0f, 0.0f, 0.0f}, {1, 1} });
		*/
		break;
	case FRONT:


		vertices.push_back({ {-1 + fx, -1 + fy, 1 + fz}, {0, 0} });
		vertices.push_back({ {-1 + fx, 1 + fy, 1 + fz}, {0, 1} });
		vertices.push_back({ {1 + fx, 1 + fy, 1 + fz},   {1, 1} });
		vertices.push_back({ {1 + fx, -1 + fy, 1 + fz},    {1, 0} });

		indices.push_back(offset + 0);
		indices.push_back(offset + 1);
		indices.push_back(offset + 2);
		// Triangle 2
		indices.push_back(offset + 0);
		indices.push_back(offset + 2);
		indices.push_back(offset + 3);

		break;
	case BACK:
		vertices.push_back({ {1 + fx, -1 + fy, -1 + fz}, {0, 0} });
		vertices.push_back({ {1 + fx, 1 + fy, -1 + fz}, {0, 1} });
		vertices.push_back({ {-1 + fx, 1 + fy, -1 + fz},   {1, 1} });
		vertices.push_back({ {-1 + fx, -1 + fy, -1 + fz},    {1, 0} });

		indices.push_back(offset + 0);
		indices.push_back(offset + 1);
		indices.push_back(offset + 2);
		// Triangle 2
		indices.push_back(offset + 0);
		indices.push_back(offset + 2);
		indices.push_back(offset + 3);

		break;
	}
}

void Chunk::rebuildMesh() {
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;

    for (int x = 0; x < 16; x++) {
        for (int y = 0; y < 16; y++) {
            for (int z = 0; z < 16; z++) {
                if (data[x][y][z] == 0) continue;

                if (!isSolid(x, y + 1, z)) addFace(vertices, indices, (2 * x), (2 * y), (2 * z), TOP);
                if (!isSolid(x, y - 1, z)) addFace(vertices, indices, (2 * x), (2 * y), (2 * z), BOTTOM);
                if (!isSolid(x + 1, y, z)) addFace(vertices, indices, (2 * x), (2 * y), (2 * z), RIGHT);
                if (!isSolid(x - 1, y, z)) addFace(vertices, indices, (2 * x), (2 * y), (2 * z), LEFT);
                if (!isSolid(x, y, z + 1)) addFace(vertices, indices, (2 * x), (2 * y), (2 * z), FRONT);
                if (!isSolid(x, y, z - 1)) addFace(vertices, indices, (2 * x), (2 * y), (2 * z), BACK);
            }
        }
    }

    indexCount = indices.size();

    // Upload to this chunk's specific buffers
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    // Set Attributes (Position and UV)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoords));
    glEnableVertexAttribArray(1);

	this->indexCount = indices.size();

	// PRINT THIS:
	std::cout << "Chunk [" << worldX << ", " << worldZ << "] generated "
		<< indexCount << " indices (" << indexCount / 6 << " faces)" << std::endl;

	// ... upload to GPU ...
}

void Chunk::render(unsigned int shaderProgram) {
    // 1. Move the chunk to its world position using a Model Matrix
    glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(worldX, 0, worldZ));


    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"), 1, GL_FALSE, &model[0][0]);

    // 2. Draw
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
}

// Inside Chunk.cpp
Chunk::~Chunk() {
	// This is where you will eventually delete your OpenGL buffers
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ebo);
}

// ... include your corrected addFace function here ...
