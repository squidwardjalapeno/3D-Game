#version 330 core
/*
// Positions/Coordinates
layout (location = 0) in vec3 aPos;
// Colors
layout (location = 1) in vec3 aColor;
// Texture Coordinates
layout (location = 2) in vec2 aTex;
*/

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord; // This matches the 1 above!


/*
// Block Positions/Coordinates
layout (location = 3) in vec3 aBlockPos;
// Block Type
layout (location = 4) in int aBlockType;
*/


// Outputs the color for the Fragment Shader
out vec3 color;
// Outputs the texture coordinates to the fragment shader
out vec2 TexCoord;

// Imports the camera matrix from the main function
uniform mat4 camMatrix;
uniform mat4 model;
uniform float number;
uniform float newBlock_data[16];
//uniform vec2 offsets[];
//uniform float testVector;




void main()
{

	/*
	int baseValue = int(sqrt(number));
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

	
	/*
	//vec2 offset = offsets[gl_InstanceID];
	int depthValue = int(pow(number, 1.0 / 3.0));
	int xPosition = 0;
	int yPosition = 0;
	

	//int depthValue = int(sqrt(baseValue));
	float multiplier = 0.0f;
	
	


	
	for ( int j = -1; j < (depthValue * depthValue); j = j + depthValue){
	float greatMultiplier = (j + 1);
	
	
	

	if ( gl_InstanceID >= depthValue * (j + 1)){
	

	for ( int i = -1; i < (depthValue * depthValue * depthValue); i = i + depthValue){
	multiplier = (i + 1);
	

	if ( gl_InstanceID > i){

	gl_Position = camMatrix * model * vec4(
	
	aPos.x + (2 * gl_InstanceID) - (2 * multiplier), 
	aPos.y + (greatMultiplier / (depthValue / 2)), 
	aPos.z + (2 * multiplier / depthValue) - (2 * greatMultiplier), 1.0);

	}

	}

	}

	}
	*/

	
	/*
	
	if ( gl_InstanceID < baseValue) {
	
	gl_Position = camMatrix * model * vec4(aPos.x + (4 * gl_InstanceID), aPos.y, aPos.z, 1.0);

	}
	 else {

	 gl_Position = camMatrix * model * vec4(aPos.x + (4 * gl_InstanceID) - (2 * number), aPos.y, aPos.z + number, 1.0);

	 }
	 */


	 /*
		int depthValue = int(pow(number, 1.0 / 2.0));

		int yPosition = int(gl_InstanceID / depthValue);
		int xPosition = gl_InstanceID - (yPosition * depthValue);









	 if( aBlockType == 0){
		 gl_Position = camMatrix * model * vec4(aPos.x + 70000, aPos.y + yPosition, aPos.z, 1.0);
	 }
	 else {
		 gl_Position = camMatrix * model * vec4(aPos.x + xPosition, aPos.y + yPosition, aPos.z, 1.0);
	 }
	 
	 */
	
	gl_Position = camMatrix * model * vec4(aPos.x, aPos.y, aPos.z, 1.0);

	TexCoord = aTexCoord; 

	


	// Assigns the colors from the Vertex Data to "color"
	//color = aColor;
	// Assigns the texture coordinates from the Vertex Data to "texCoord"
	//texCoord = aTex;
}