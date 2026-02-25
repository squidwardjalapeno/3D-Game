#include "World.h"
#include "Chunk.h" 
#include <iostream>

World::World() {}

World::~World() {
    for (auto& pair : chunks) {
        delete pair.second;
    }
}

bool World::isSolidAt(int x, int y, int z) {
    if (y < 0 || y >= 16) return false;

    // 1. Calculate which chunk this block belongs to
    // Use floor to handle negative coordinates correctly (e.g., -1 becomes chunk -1)
    int cx = std::floor((float)x / 16.0f);
    int cz = std::floor((float)z / 16.0f);

    glm::ivec2 chunkPos(cx, cz);
    if (chunks.find(chunkPos) == chunks.end()) return false;

    // 2. Convert global coord to local chunk coord (0-15)
    int lx = x % 16; if (lx < 0) lx += 16;
    int lz = z % 16; if (lz < 0) lz += 16;

    return chunks[chunkPos]->isSolid(lx, y, lz);
}

void World::update(glm::vec3 playerPos) {
    int pX = std::floor(playerPos.x / 16.0f);
    int pZ = std::floor(playerPos.z / 16.0f);

    // Load chunks in a square around the player
    for (int x = pX - renderDistance; x <= pX + renderDistance; x++) {
        for (int z = pZ - renderDistance; z <= pZ + renderDistance; z++) {
            if (chunks.find(glm::ivec2(x, z)) == chunks.end()) {
                loadChunk(x, z);
            }
        }
    }
    // TODO: unloadFarChunks(playerPos);
}

void World::loadChunk(int x, int z) {
    chunks[glm::ivec2(x, z)] = new Chunk(x, z);
}

void World::render(unsigned int shaderProgram) {
    for (auto const& [pos, chunk] : chunks) {
        chunk->render(shaderProgram);
    }
}
