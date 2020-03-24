#include <pch.h>
#include <CustomRenderer.h>
#include <glew.h>

void CustomRenderer::Initialize()
{
	GLfloat verts[] =
	{
		+0.0f, 0.0f, //position
		1.0f,0.0f,0.0f, //color
		
		+1.0f,1.0f,
		1.0f,0.0f,0.0f,
		
		-1.0f,1.0f,
		1.0f,0.0f,0.0f,

		-1.0f,-1.0f,
		1.0f,0.0f,0.0f,
		
		+1.0f,-1.0f,
		1.0f,0.0f,0.0f,
	};
	GLuint vertexBufferID;

	//set up buffer and send vertex array to the array buffer
	glGenBuffers(1, &vertexBufferID);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0); //attribute 0 is assumed by opengl to be position
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 5, 0);

	glEnableVertexAttribArray(1); //attribute 1 is not assumed to be anything
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 5, (char *)(sizeof(GLfloat) * 2));

	GLushort indices[] =
	{
		3,1,2,
		0,3,4
	};

	GLuint indexBufferID;

	//set up buffer and send vertex array to the array buffer
	glGenBuffers(1, &indexBufferID);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


	//glClearColor(1, 0, 0, 1);
	//glClear(GL_COLOR_BUFFER_BIT);


}

void CustomRenderer::RenderFrame()
{
	//glViewport(0, 0,);
	//glDrawArrays(GL_TRIANGLES,0,6);

	//draw 6 triangles, with indices from the element array buffer
	//the indices are unsigned shorts. the offset into the index array is 0
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);
}
