
#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include"Texture.h"
#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"
#include"Camera.h"
#include"Window.h"
#include"Chunk.h"
#include"World.h"



const unsigned int width = 800;
const unsigned int height = 800;

//0.0f, 0.0f, 0.0f,



// Vertices coordinates
/*
GLfloat vertices[] =
{ //     COORDINATES     /        COLORS        /    TexCoord    /

//BOTTOM
	-1.0f, -1.0f,  1.0f,    0.0f, 0.0f, 0.0f,	0.0f, 0.0f,
	-1.0f, -1.0f, -1.0f,    0.0f, 0.0f, 0.0f,	0.0f, 1.0f,
	 1.0f, -1.0f, -1.0f,    0.0f, 0.0f, 0.0f,	1.0f, 1.0f,
	 1.0f, -1.0f,  1.0f,    0.0f, 0.0f, 0.0f,	1.0f, 0.0f,
	 
//LEFT
	-1.0f, -1.0f, -1.0f,    0.0f, 0.0f, 0.0f,	0.0f, 0.0f,
	-1.0f,  1.0f, -1.0f,    0.0f, 0.0f, 0.0f,	0.0f, 1.0f,
	-1.0f,  1.0f,  1.0f,    0.0f, 0.0f, 0.0f,	1.0f, 1.0f,
	-1.0f, -1.0f,  1.0f,    0.0f, 0.0f, 0.0f,	1.0f, 0.0f,

//BACK
	 1.0f, -1.0f, -1.0f,    0.0f, 0.0f, 0.0f,	0.0f, 0.0f,
	 1.0f,  1.0f, -1.0f,    0.0f, 0.0f, 0.0f,	0.0f, 1.0f,
	-1.0f,  1.0f, -1.0f,    0.0f, 0.0f, 0.0f,	1.0f, 1.0f,
	-1.0f, -1.0f, -1.0f,    0.0f, 0.0f, 0.0f,	1.0f, 0.0f,

//RIGHT
	 1.0f, -1.0f,  1.0f,    0.0f, 0.0f, 0.0f,	0.0f, 0.0f,
	 1.0f,  1.0f,  1.0f,    0.0f, 0.0f, 0.0f,	0.0f, 1.0f,
	 1.0f,  1.0f, -1.0f,    0.0f, 0.0f, 0.0f,	1.0f, 1.0f,
	 1.0f, -1.0f, -1.0f,    0.0f, 0.0f, 0.0f,	1.0f, 0.0f,

//FRONT
	-1.0f, -1.0f,  1.0f,    0.0f, 0.0f, 0.0f,	0.0f, 0.0f,
	-1.0f,  1.0f,  1.0f,    0.0f, 0.0f, 0.0f,	0.0f, 1.0f,
	 1.0f,  1.0f,  1.0f,    0.0f, 0.0f, 0.0f,	1.0f, 1.0f,
	 1.0f, -1.0f,  1.0f,    0.0f, 0.0f, 0.0f,	1.0f, 0.0f,
	 
//TOP
	-1.0f, 1.0f,  1.0f,     0.0f, 0.0f, 0.0f,	0.0f, 0.0f,
	-1.0f, 1.0f, -1.0f,     0.0f, 0.0f, 0.0f,	0.0f, 1.0f,
	 1.0f, 1.0f, -1.0f,     0.0f, 0.0f, 0.0f,	1.0f, 1.0f,
	 1.0f, 1.0f,  1.0f,     0.0f, 0.0f, 0.0f,	1.0f, 0.0f

	 
	 

	 
	 

};

*/



//std::vector<Vertex> vertices;





// Indices for vertices order
/*
GLuint indices[] =
{
	0, 1, 2,	
	0, 2, 3,
	
	4, 5, 6,	
	4, 6, 7,

	8, 9, 10,
	8, 10, 11,

	12, 13, 14,
	12, 14, 15,

	16, 17, 18,
	16, 18, 19,

	20, 21, 22,
	20, 22, 23
	
	

	
	
	1, 2, 6,
	1, 5, 6,

	2, 3, 7,
	2, 6, 7,

	0, 3, 7,
	0, 4, 7,

	4, 5, 6,
	4, 6, 7

	
	
};
*/
/*
struct Chunk {
	static const int SIZE = 16;
	uint8_t blocks[SIZE * SIZE * SIZE];
	bool isLoaded = false;

	int x, y, z;



};

*/








//int chunk[16][16][16];










//std::vector<GLfloat> vertices;


std::vector<Vertex> vertices;

std::vector<unsigned int> indices;

World myWorld;

//enum FaceDirection { TOP, BOTTOM, LEFT, RIGHT, FRONT, BACK };


/*
bool isSolid(int x, int y, int z) {
	if (x < 0 || x >= 16 || y < 0 || y >= 16 || z < 0 || z >= 16) return false;
	return chunk[x][y][z] != 0; // 0 = Air
}
*/
//int offset = vertices.size();










/*
void rebuildMesh() {
	//std::vector<Vertex> vertices;
	for (int x = 0; x < 16; x++) {
		for (int y = 0; y < 16; y++) {
			for (int z = 0; z < 16; z++) {

				if (chunk[x][y][z] == 0) continue; // Skip air blocks

				// Check all 6 neighbors. Only add the face if the neighbor is Air.
				if (!isSolid(x + 1, y, z)) addFace(vertices, indices, (2 * x), (2 * y), (2 * z), RIGHT);
				if (!isSolid(x - 1, y, z)) addFace(vertices, indices, (2 * x), (2 * y), (2 * z), LEFT);
				if (!isSolid(x, y + 1, z)) addFace(vertices, indices, (2 * x), (2 * y), (2 * z), TOP);
				if (!isSolid(x, y - 1, z)) addFace(vertices, indices, (2 * x), (2 * y), (2 * z), BOTTOM);
				if (!isSolid(x, y, z + 1)) addFace(vertices, indices, (2 * x), (2 * y), (2 * z), FRONT);
				if (!isSolid(x, y, z - 1)) addFace(vertices, indices, (2 * x), (2 * y), (2 * z), BACK);
			}
		}
	}
	// Now upload 'vertices' to your VBO

}
*/














int main()
{

	Window createWindow(width, height);

	GLFWwindow* window = createWindow.window;

	//Load GLAD so it configures OpenGL
	gladLoadGL();

	//addFace(vertices, indices, 1, 1, 1, BOTTOM);

	//addFace(vertices, indices, 3, 3, 3, BOTTOM);

	/*
	// Before calling rebuildMesh()
	for (int x = 0; x < 16; x++) {
		for (int y = 0; y < 16; y++) {
			for (int z = 0; z < 16; z++) {
				chunk[x][y][z] = 1; // 1 = Stone/Solid
			}
		}
	}
	*/

	// Create two separate chunks

	/*
			Chunk chunkA(0, 16);
			Chunk chunkB(16, 16);
			Chunk chunkC(32, 16);
			Chunk chunkD(48, 16);
			Chunk chunkE(64, 16);
			Chunk chunkF(80, 16);
			Chunk chunkG(96, 16);
			Chunk chunkH(112, 16);
			Chunk chunkI(128, 16);
			Chunk chunkJ(144, 16);
			*/


			 // 16 units to the right
		
	






	//rebuildMesh();


	/*
	for (int x = 0; x < 16; x++) {
		for (int y = 0; y < 16; y++) {
			for (int z = 0; z < 16; z++) {


				addFace(vertices, indices, (2 * x), (2 * y), (2 * z), BOTTOM);
				addFace(vertices, indices, (2 * x), (2 * y), (2 * z), LEFT);
				addFace(vertices, indices, (2 * x), (2 * y), (2 * z), BACK);
				addFace(vertices, indices, (2 * x), (2 * y), (2 * z), RIGHT);
				addFace(vertices, indices, (2 * x), (2 * y), (2 * z), FRONT);
				addFace(vertices, indices, (2 * x), (2 * y), (2 * z), TOP);

			}
		}
				
				
				

	}
	*/

	

	/*
	for (int x = 0; x < 16; x++) {
		for (int y = 0; y < 16; y++) {
			for (int z = 0; z < 16; z++) {
				if (chunk[x][y][z] == 0) continue; // Skip air blocks

				// Check all 6 neighbors. Only add the face if the neighbor is Air.
				if (!isSolid(x + 1, y, z)) addFace(vertices, indices, (2 * x), (2 * y), (2 * z), BOTTOM);
				if (!isSolid(x - 1, y, z)) addFace(vertices, indices, (2 * x), (2 * y), (2 * z), LEFT);
				if (!isSolid(x, y + 1, z)) addFace(vertices, indices, (2 * x), (2 * y), (2 * z), BACK);
				if (!isSolid(x, y - 1, z)) addFace(vertices, indices, (2 * x), (2 * y), (2 * z), RIGHT);
				if (!isSolid(x, y, z + 1)) addFace(vertices, indices, (2 * x), (2 * y), (2 * z), FRONT);
				if (!isSolid(x, y, z - 1)) addFace(vertices, indices, (2 * x), (2 * y), (2 * z), TOP);
			}
		}
	}

	*/


			
				

	//addFace(vertices, 0, 0, 0, FRONT);
	//addFace(vertices, 2, 0, 0, FRONT);



				
				

				/*
				addFace(vertices, 2, 2, 2, BOTTOM);
				addFace(vertices, 2, 2, 2, LEFT);
				addFace(vertices, 2, 2, 2, BACK);
				addFace(vertices, 2, 2, 2, RIGHT);
				addFace(vertices, 2, 2, 2, FRONT);
				addFace(vertices, 2, 2, 2, TOP);
				*/


			
		
	


	//rebuildMesh();
	/*
	std::vector<Vertex> vertices;
	
	for (int x = 0; x < 16; x++) {
		for (int y = 0; y < 16; y++) {
			for (int z = 0; z < 16; z++) {
				if (chunk[x][y][z] == 0) continue; // Skip air blocks

				// Check all 6 neighbors. Only add the face if the neighbor is Air.
				if (!isSolid(x + 1, y, z)) addFace(vertices, x, y, z, RIGHT);
				if (!isSolid(x - 1, y, z)) addFace(vertices, x, y, z, LEFT);
				if (!isSolid(x, y + 1, z)) addFace(vertices, x, y, z, TOP);
				if (!isSolid(x, y - 1, z)) addFace(vertices, x, y, z, BOTTOM);
				if (!isSolid(x, y, z + 1)) addFace(vertices, x, y, z, FRONT);
				if (!isSolid(x, y, z - 1)) addFace(vertices, x, y, z, BACK);
			}
		}
	*/


	/*
	vertices.push_back({-1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f});
	vertices.push_back({ -1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f });
	vertices.push_back({ 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f });
	vertices.push_back({ 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f });
	*/
	
	

	/*
	vertices.push_back({ glm::vec3(0, 0, 1),glm::vec3(0, 0, 1),  glm::vec2(0, 0) });
	vertices.push_back({ glm::vec3(1, 0, 1),glm::vec3(0, 0, 1), glm::vec2(1, 0) });
	vertices.push_back({ glm::vec3(1, 1, 1),glm::vec3(0, 0, 1), glm::vec2(1, 1) });
	*/

	

	
	
	
	//vertices.push_back({ 0.0f, 0.0f, 0.0f });
	//vertices.push_back({ 0.0f, 0.0f});

	
	/*
	vertices.push_back({ 0.0f, 0.0f, 0.0f });
	vertices.push_back({ 0.0f, 1.0f });


	vertices.push_back({ 1.0f, -1.0f, -1.0f });
	vertices.push_back({ 0.0f, 0.0f, 0.0f });
	vertices.push_back({ 1.0f, 1.0f });

	vertices.push_back({ 1.0f, -1.0f, 1.0f });
	vertices.push_back({ 0.0f, 0.0f, 0.0f });
	vertices.push_back({ 1.0f, 0.0f });
	*/


	

	






	// Generates Shader object using shaders default.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");




	// Generates Vertex Array Object and binds it
	VAO VAO1;
	VAO1.Bind();

	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO1(vertices);
	// Generates Element Buffer Object and links it to indices
	EBO EBO1(indices);

	int stride = 5 * sizeof(float);

	// Links VBO attributes such as coordinates and colors to VAO
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, stride, (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 2, GL_FLOAT, stride, (void*)(3 * sizeof(float)));

	/*
	VAO1.LinkAttrib(VBO1, 3, 3, GL_FLOAT, 11 * sizeof(float) + sizeof(int), (void*)offsetof(Block, position));
	VAO1.LinkIntAttrib(VBO1, 4, 1, GL_INT,11 * sizeof(float) + sizeof(int), (void*)offsetof(Block, blockType));
	*/

	// Unbind all to prevent accidentally modifying them
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();





	// Texture
	Texture popcat("pop_cat.png", GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE);
	// Original code from the tutorial
	/*Texture brickTex("brick.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	brickTex.texUnit(shaderProgram, "tex0", 0);*/



	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);

	//glDisable(GL_CULL_FACE);

	// Enable face-culling
	glEnable(GL_CULL_FACE);

	// Specify which face to cull (opengl is reversed for some reason)
	glCullFace(GL_FRONT);


	// Creates camera object
	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

	/*

	int widthImg, heightImg, numColCh;

	unsigned char* bytes = stbi_load("C:/Users/josep/source/repos/retryTest/retryTest", &widthImg, &heightImg, &numColCh, 4);


	if (bytes) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthImg, heightImg, 0, GL_RGBA, GL_UNSIGNED_BYTE, bytes);
		glGenerateMipmap(GL_TEXTURE_2D);
		stbi_image_free(bytes);
	}

	*/




	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.0f, 0.1f, 0.0f, 1.0f);
		// Clean the back buffer and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		/*
		// 1. Create a temporary Framebuffer to hold your texture
		GLuint fbo;
		glGenFramebuffers(1, &fbo);
		glBindFramebuffer(GL_READ_FRAMEBUFFER, fbo);

		// 2. Attach your texture to it
		glFramebufferTexture2D(GL_READ_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, popcat.ID, 0);

		// 3. "Blit" (copy) it directly to the screen (0, 0 to width, height)
		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0); // Target the screen
		glBlitFramebuffer(0, 0, 256, 256, 0, 0, 256, 256, GL_COLOR_BUFFER_BIT, GL_NEAREST);

		// 4. Cleanup
		glDeleteFramebuffers(1, &fbo);
		*/
		// Tell OpenGL which Shader Program we want to use
		shaderProgram.Activate();



		// Handles camera inputs
		camera.Inputs(window);
		// Updates and exports the camera matrix to the Vertex Shader
		camera.Matrix(45.0f, 0.1f, 100.0f, shaderProgram, "camMatrix");

		// Binds texture so that is appears in rendering
		//popcat.Bind();
		// Bind the VAO so OpenGL knows to use it
		VAO1.Bind();








		// Initializes matrices so they are not the null matrix
		//glm::mat4 model = glm::mat4(1.0f);

		//model = glm::translate(model, glm::vec3(5.0f, 0.0f, 0.0f));

		// Outputs the matrices into the Vertex Shader
		//int modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
		//glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		//glm::vec4 translateWorldMatrix = glm::vec4(1.0f);

		
		
		//glm::vec3 chunk[16][16][16];


		//struct Block newBlock;

		/*
		int newBlock[16];

		GLfloat newBlock_data[16];

		for (int i = 0; i < 16; i++) {

			

			newBlock[i] = i;

			

			newBlock_data[i] = newBlock[i];



		}

		
		//Output block location to the vertex shader
		int blockLoc = glGetUniformLocation(shaderProgram.ID, "newBlock_data");
		glUniform1fv(blockLoc, 16, newBlock_data);



		*/



		


		/*
		glm::vec3 newArray;


		std::vector<int> testVector{};

		for (unsigned int i = 0; i < 16; i++)

		{
			int valuePending = i;

			testVector.push_back(valuePending);

		}

		int testVectorLoc = glGetUniformLocation(shaderProgram.ID, "testVector");
		glUniform1f(testVectorLoc,testVector[14]);

		*/

		

		
		

		








		/*
		float number = 1;

		int numberLoc = glGetUniformLocation(shaderProgram.ID, "number");
		glUniform1f(numberLoc, number);

		
		*/

		
	
		



		// Draw primitives, number of indices, datatype of indices, index of indices
		//glDrawElements(GL_TRIANGLES, (GLsizei)indices.size(), GL_UNSIGNED_INT, 0);

		

		

		glUseProgram(shaderProgram.ID);

		

		// 1. "Tune" the GPU to Channel 0
		glActiveTexture(GL_TEXTURE0);
		// 2. Put 'popcat' on Channel 0
		glBindTexture(GL_TEXTURE_2D, popcat.ID);

		// 3. Tell the Shader variable to listen to Channel 0
		// This is the most common place for it to fail!
		int texLoc = glGetUniformLocation(shaderProgram.ID, "ourTexture");
		if (texLoc != -1) {
			glUniform1i(texLoc, 0); // 0 matches GL_TEXTURE0
		}
		else {
			std::cout << "ERROR: Could not find 'ourTexture' in shader!" << std::endl;
		}
		

		
		/*
		// Draw them
		chunkA.render(shaderProgram.ID);
		chunkB.render(shaderProgram.ID);
		chunkC.render(shaderProgram.ID);
		chunkD.render(shaderProgram.ID);
		chunkE.render(shaderProgram.ID);
		chunkF.render(shaderProgram.ID);
		chunkG.render(shaderProgram.ID);
		chunkH.render(shaderProgram.ID);
		chunkI.render(shaderProgram.ID);
		chunkJ.render(shaderProgram.ID);

		*/


		myWorld.update(camera.Position);

		// 3. Mesh Management 
		for (auto const& pair : myWorld.chunks) {
			Chunk* chunk = pair.second;
			if (chunk->needsMeshUpdate) {
				chunk->rebuildMesh(&myWorld);
				chunk->needsMeshUpdate = false;
			}
		}

		// 3. Render
		myWorld.render(shaderProgram.ID);


		

		//std::cout << "Rendering texture with ID: " << popcat.ID << std::endl;
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}



	// Delete all the objects we've created
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	//popcat.Delete();
	shaderProgram.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
};