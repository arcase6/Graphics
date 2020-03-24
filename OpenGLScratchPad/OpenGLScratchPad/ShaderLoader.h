#pragma once

#include <glew.h>

class ShaderLoader {
public:
	GLuint GenerateProgramUsingShaders();
	const GLuint& LinkShaderIntoProgram(const GLuint& vertexShader, const GLuint& fragmentShader);
protected:
	const char * LoadVertexShaderRaw();
	const char * LoadFragmentShaderRaw();
	GLuint CreateShader(GLenum shaderType, const char* shaderCodeRaw);
};