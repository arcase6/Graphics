#include <pch.h>
#include <CustomRenderer.h>
#include <glew.h>
#include <ShaderLoader.h>


void CustomRenderer::Initialize()
{
	glEnable(GL_DEPTH_TEST);
	PassVertexData();
	PassIndicesData();

	InitializeShaders();
}

void CustomRenderer::InitializeShaders()
{
	ShaderLoader loader(GetVertexShaderPath(), GetFragmentShaderPath());
	GLuint programID = loader.GenerateProgramUsingShaders();
	glUseProgram(programID);
}

std::string CustomRenderer::GetVertexShaderPath()
{
	return "VertexShader.glsl";
}

std::string CustomRenderer::GetFragmentShaderPath()
{
	return "FragmentShader.glsl";
}

GLuint CustomRenderer::GenerateAndBindBuffer(GLenum targetBuffer)
{
	GLuint bufferID;

	//set up buffer and send vertex array to the array buffer
	glGenBuffers(1, &bufferID);

	glBindBuffer(targetBuffer, bufferID);
	return bufferID;
}
