#ifndef VBO_CLASS_H
#define VBO_CLASS_H


#include<glad/glad.h>
#include <vector>    // Required for std::vector

struct Vertex {
	GLfloat position[3];
	GLfloat texCoords[2];
};



class VBO
{
public:
	// Reference ID of the Vertex Buffer Object
	GLuint ID;
	// Constructor that generates a Vertex Buffer Object and links it to vertices
	VBO(const std::vector<Vertex>& vertices);
	
	

	// Binds the VBO
	void Bind();
	// Unbinds the VBO
	void Unbind();
	// Deletes the VBO
	void Delete();
};

#endif