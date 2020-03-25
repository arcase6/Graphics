#include <pch.h>
#include <CustomRenderer.h>
#include <glew.h>
#include <ShaderLoader.h>

#define POSITION_DATA_SIZE 3
#define COLOR_DATA_SIZE 3

#define TRIANGLE_COUNT 2


#define RAINBOW_TRIANGLE_Z 0.0f
#define RED_TRIANGLE_Z 0.5f
GLfloat verts[] =
{
	+0.0f, 1.0f, RAINBOW_TRIANGLE_Z, //position
	1.0f,0.0f,0.0f, //color

	1.0f, -1.0f,RAINBOW_TRIANGLE_Z,
	0.0f,1.0f,0.0f,

	-1.0f,-1.0f,RAINBOW_TRIANGLE_Z,
	0.0f,0.0f,1.0f,

	+0.0f, -1.0f,RED_TRIANGLE_Z, //position
	1.0f,0.0f,0.0f, //color

	1.0f, 1.0f, RED_TRIANGLE_Z,
	1.0f,0.0f,0.0f,

	-1.0f,1.0f, RED_TRIANGLE_Z,
	1.0f,0.0f,0.0f,
};

GLushort indices[] =
{
	0,2,1, //triangle 1
	3,4,5 //triangle 2
};

void CustomRenderer::Initialize()
{
	glEnable(GL_DEPTH_TEST);
	PassVertexData();
	PassIndicesData();

	InitializeShaders();
}

void CustomRenderer::InitializeShaders()
{
	ShaderLoader loader;
	GLuint programID = loader.GenerateProgramUsingShaders();
	glUseProgram(programID);
}

void CustomRenderer::PassVertexData()
{
	GenerateAndBindBuffer(GL_ARRAY_BUFFER);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

	int stride = POSITION_DATA_SIZE + COLOR_DATA_SIZE;

	glEnableVertexAttribArray(0); //attribute 0 is assumed by opengl to be position
	glVertexAttribPointer(0, POSITION_DATA_SIZE, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * stride, 0);

	glEnableVertexAttribArray(1); //attribute 1 is not assumed to be anything
	glVertexAttribPointer(1, COLOR_DATA_SIZE, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * stride, (char*)(sizeof(GLfloat) * POSITION_DATA_SIZE));
}

void CustomRenderer::PassIndicesData()
{
	GenerateAndBindBuffer(GL_ELEMENT_ARRAY_BUFFER);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

void CustomRenderer::GenerateAndBindBuffer(GLenum targetBuffer)
{
	GLuint bufferID;

	//set up buffer and send vertex array to the array buffer
	glGenBuffers(1, &bufferID);

	glBindBuffer(targetBuffer, bufferID);
}

void CustomRenderer::RenderFrame()
{

	glClear(GL_DEPTH_BUFFER_BIT);

	int pointCount = 3 * TRIANGLE_COUNT;

	//draw 6 triangles, with indices from the element array buffer
	//the indices are unsigned shorts. the offset into the index array is 0
	glDrawElements(GL_TRIANGLES, pointCount, GL_UNSIGNED_SHORT, 0);
}
