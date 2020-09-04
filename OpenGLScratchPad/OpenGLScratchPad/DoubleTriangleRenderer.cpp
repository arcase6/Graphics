#include <pch.h>
#include "DoubleTriangleRenderer.h"


#define POSITION_DATA_SIZE 3
#define COLOR_DATA_SIZE 3

#define TRIANGLE_COUNT 2


#define RAINBOW_TRIANGLE_Z -0.5f
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

void DoubleTriangleRenderer::PassVertexData()
{
	GenerateAndBindBuffer(GL_ARRAY_BUFFER);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

	int stride = sizeof(GLfloat) * (POSITION_DATA_SIZE + COLOR_DATA_SIZE);

	//Position Attribute
	glEnableVertexAttribArray(0); //attribute 0 is assumed by opengl to be position
	glVertexAttribPointer(0, POSITION_DATA_SIZE, GL_FLOAT, GL_FALSE, stride, 0);

	//Color Attributes
	glEnableVertexAttribArray(1); //attribute 1 is not assumed to be anything
	glVertexAttribPointer(1, COLOR_DATA_SIZE, GL_FLOAT, GL_FALSE, stride, (GLbyte*)(sizeof(GLfloat) * POSITION_DATA_SIZE));
}

void DoubleTriangleRenderer::RenderFrame()
{
	glClear(GL_DEPTH_BUFFER_BIT);

	int pointCount = 3 * TRIANGLE_COUNT;

	//draw 6 triangles, with indices from the element array buffer
	//the indices are unsigned shorts. the offset into the index array is 0
	glDrawElements(GL_TRIANGLES, pointCount, GL_UNSIGNED_SHORT, 0);
}

void DoubleTriangleRenderer::PassIndicesData()
{
	GenerateAndBindBuffer(GL_ELEMENT_ARRAY_BUFFER);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

