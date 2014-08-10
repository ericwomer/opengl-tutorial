#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h>

class Shader
{
public:
	Shader(const std::string& fileName);
	virtual ~Shader();

	void Bind();

	static std::string LoadShader(const std::string& fileName);
	static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
	static GLuint CreateShader(const std::string& text, GLenum shaderType);

private:
	Shader(const Shader& other) {}
	void operator=(const Shader& rhs) {}

	static const unsigned int NUM_SHADERS = 2;

	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];

};

#endif // SHADER_H
