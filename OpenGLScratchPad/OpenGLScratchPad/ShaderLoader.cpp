#include <pch.h>
#include <ShaderLoader.h>
#include <vector>

const char* vertexShaderCode = 
"#version 430\r\n"
""
"in layout(location=0) vec2 position;"
"in layout(location=1) vec3 vertexColor;"
""
"out vec3 theColor;"
""
"void main(){"
"	gl_Position = vec4(position,0.0,1.0);"
"	theColor = vertexColor;"
"}"
;

const char* fragmentShaderCode =
"#version 430\r\n"
""
"in vec3 theColor;"
""
"out vec4 daColor;"
""
"void main(){"
"	daColor = vec4(theColor,1.0);"
"}"
;

GLuint ShaderLoader::GenerateProgramUsingShaders()
{
	GLuint vertexShader = CreateShader(GL_VERTEX_SHADER, LoadVertexShaderRaw());
	GLuint fragmentShader = CreateShader(GL_FRAGMENT_SHADER, LoadFragmentShaderRaw());
	
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

const char * ShaderLoader::LoadVertexShaderRaw()
{
	return vertexShaderCode;
}

const char * ShaderLoader::LoadFragmentShaderRaw()
{
	return fragmentShaderCode;
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
