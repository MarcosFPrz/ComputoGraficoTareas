#include "Shader.h"

Shader::Shader(std::string vertexShader, std::string fragmentShader)
{
	LoadShaders(vertexShader, fragmentShader);
}

Shader::Shader()
{
}

Shader::~Shader()
{
}

void Shader::LoadShaders(std::string vertexShader, std::string fragmentShader)
{
	std::string strVertexShader = loadTextFile(vertexShader);
	std::string strFragmentShader = loadTextFile(fragmentShader);
	InitializeProgram(shader, strVertexShader, strFragmentShader);
	transformID = glGetUniformLocation(shader, "transform");
	colorID = glGetUniformLocation(shader, "vColor");
}

void Shader::ApplyTransformation(glm::mat4 transform)
{
	glUniformMatrix4fv(transformID, 1, GL_FALSE, glm::value_ptr(transform));

}

void Shader::ApplyColor(glm::vec3 color)
{
	glUniform4fv(colorID, 1, glm::value_ptr(color));
}

void Shader::ActivateShader()
{
	glUseProgram(shader);
}
