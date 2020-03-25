#pragma once

#include <glew.h>
#include <string>

class ShaderLoader {
public:
	GLuint GenerateProgramUsingShaders();
	const GLuint& LinkShaderIntoProgram(const GLuint& vertexShader, const GLuint& fragmentShader);
protected:
	std::string LoadVertexShaderRaw();
	std::string LoadFragmentShaderRaw();
	std::string LoadFromFile(std::string filename);
	GLuint CreateShader(GLenum shaderType, const char* shaderCodeRaw);
};