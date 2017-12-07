#pragma once
#include <string>
#include "ShaderFuncs.h"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/vec4.hpp"
#include "glm/vec3.hpp"
#include "GLFW\glfw3.h"

class Shader
{
public:
	Shader(std::string vertexShader, std::string fragmentShader);
	Shader();
	~Shader();
	void LoadShaders(std::string vertexShader, std::string fragmentShader);
	void ApplyTransformation(glm::mat4 transform);
	void ApplyColor(glm::vec3 color);
	void ActivateShader();
private:
	GLuint transformID, colorID;
	GLuint shader; 
};
