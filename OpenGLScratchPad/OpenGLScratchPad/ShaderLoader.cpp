#include <pch.h>
#include <ShaderLoader.h>
#include <vector>
#include <fstream>
#include <iostream>

ShaderLoader::ShaderLoader(std::string vertShaderPath, std::string fragShaderPath):
	vertexShaderPath(vertShaderPath), fragmentShaderPath(fragShaderPath)
{
}

GLuint ShaderLoader::GenerateProgramUsingShaders()
{
	std::string vertexString = LoadVertexShaderRaw();
	std::string fragmentString = LoadFragmentShaderRaw();

	GLuint vertexShader = CreateShader(GL_VERTEX_SHADER, vertexString.c_str());
	GLuint fragmentShader = CreateShader(GL_FRAGMENT_SHADER, fragmentString.c_str());
	
	return LinkShaderIntoProgram(vertexShader, fragmentShader);
}

const GLuint& ShaderLoader::LinkShaderIntoProgram(const GLuint& vertexShader, const GLuint& fragmentShader)
{
	GLuint programID = glCreateProgram();
	glAttachShader(programID, vertexShader);
	glAttachShader(programID, fragmentShader);
	glLinkProgram(programID);

	GLint result;
	GLint infoLogLength;
	glGetProgramiv(programID, GL_LINK_STATUS, &result);
	glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);

	if (!result && infoLogLength > 0) {
		std::vector<char> programErrorMessage(infoLogLength + 1);
		glGetProgramInfoLog(programID, infoLogLength, 0, &programErrorMessage[0]);
		printf("%s\n", &programErrorMessage[0]);
	}

	return programID;
}

std::string ShaderLoader::LoadVertexShaderRaw()
{
	return LoadFromFile(vertexShaderPath);
}

std::string ShaderLoader::LoadFragmentShaderRaw()
{
	return LoadFromFile(fragmentShaderPath);
}


std::string ShaderLoader::LoadFromFile(std::string filename) {
	std::ifstream meInput(filename);
	if (!meInput.good()) {
		std::cout << "The file failed to load" << std::endl;
		exit(1);
	}
	return std::string(std::istreambuf_iterator<char>(meInput), std::istreambuf_iterator<char>());
	
}

GLuint ShaderLoader::CreateShader(GLenum shaderType, const char* shaderCodeRaw)
{
	const char* adapter[1];
	adapter[0] = shaderCodeRaw;
	
	//create a shader and store the id
	GLuint shaderID = glCreateShader(shaderType);
	//store the source code in the created shader
	//(source is copied and local objects can be reused)
	glShaderSource(shaderID, 1, adapter, 0);
	//compile the shader
	glCompileShader(shaderID);
	
	//check if the compile operation succeeded
	GLint compileResult;
	GLint infoLogLength;

	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compileResult);
	glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);

	if (!compileResult && !infoLogLength) {
		std::vector<char> shaderErrorMessage(infoLogLength + 1);
		glGetShaderInfoLog(shaderID, infoLogLength, 0, &shaderErrorMessage[0]);
		printf("%s\n", &shaderErrorMessage[0]);
	}

	return shaderID;
}
