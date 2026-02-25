#ifndef WORLD_H
#define WORLD_H

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtx/hash.hpp> // Required for using ivec2 in unordered_map
#include <unordered_map>
#include <vector>

class Chunk; // Forward declaration to avoid circular dependency

class World {
public:
    World();
    ~World();

    // The core storage: maps chunk coordinates to Chunk objects
    std::unordered_map<glm::ivec2, Chunk*> chunks;

    int renderDistance = 6; // How many chunks to load around player

    void update(glm::vec3 playerPos);
    void render(unsigned int shaderProgram);

    // Global check: handles coordinates across different chunks
    bool isSolidAt(int x, int y, int z);

private:
    void loadChunk(int x, int z);
    void unloadFarChunks(glm::vec3 playerPos);
};

#endif
