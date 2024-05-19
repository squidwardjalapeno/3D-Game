#version 330 core

// Positions/Coordinates
layout (location = 0) in vec3 aPos;
// Colors
layout (location = 1) in vec3 aColor;
// Texture Coordinates
layout (location = 2) in vec2 aTex;


// Outputs the color for the Fragment Shader
out vec3 color;
// Outputs the texture coordinates to the fragment shader
out vec2 texCoord;

// Imports the camera matrix from the main function
uniform mat4 camMatrix;
uniform mat4 model;
uniform float number;
uniform vec2 offsets[100];
uniform float testVector;




void main()
{

	/*int baseValue = int(sqrt(number));
	int squareSize = 2;
	
	

		
	for ( int i = -1; i < (baseValue * baseValue); i = i + baseValue){
	float multiplier = (i + 1);
	
    

	// Outputs the positions/coordinates of all vertices
	if ( gl_InstanceID > i){
	
	gl_Position = camMatrix * model * 

	vec4
	(aPos.x + ((gl_InstanceID - multiplier) * 2),
	aPos.y,
	(aPos.z + (multiplier / (baseValue/squareSize))),
	1.0);

	}
	
	}
	*/


	
	
	vec2 offset = offsets[gl_InstanceID];


	
	gl_Position = camMatrix * model * vec4(aPos.x + (2 * gl_InstanceID), aPos.y + testVector, aPos.z, 1.0);





	// Assigns the colors from the Vertex Data to "color"
	color = aColor;
	// Assigns the texture coordinates from the Vertex Data to "texCoord"
	texCoord = aTex;
}