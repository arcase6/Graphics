#include <pch.h>
#include <CustomRenderer.h>
#include <glew.h>

void CustomRenderer::Initialize()
{
	GLfloat verts[] = 
	{
		+0.0f, 1.0f,
		-1.0f,-1.0f,
		+1.0f,-1.0f,
	};
	GLuint myBufferID;
	
	//set up buffer and send vertex array to the array buffer
	glGenBuffers(1, &myBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, myBufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts),verts, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

	//glClearColor(1, 0, 0, 1);
	//glClear(GL_COLOR_BUFFER_BIT);


}

void CustomRenderer::RenderFrame()
{
	//glViewport(0, 0,);
	glDrawArrays(GL_TRIANGLES,0,3);
}
