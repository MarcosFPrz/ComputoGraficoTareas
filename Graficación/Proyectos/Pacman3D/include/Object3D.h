#pragma once

#include <iostream>
#include <vector>
#include "GL\glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "ShaderFuncs.h"
#include "Shader.h"
#include "MeshChidori.h"
#include "glm\matrix.hpp"




class Object3D{
public:

	void setUp(std::vector<GLfloat> vertex, std::vector<GLuint> * index);
	void draw();
	void setShaders(std::string vertexShader, std::string fragmentShader);
	void setMesh(MeshChidori mesh);
	void setShader(Shader shader);
	void LoadFromFile(std::string file);
	void SetTranslation(glm::mat4);
	void SetScale(glm::mat4 sc);
	void SetRotation(glm::mat4 rot);
	void SetColor(glm::vec3 col);
	void SetCamera(glm::mat4 cam);
	void SetPerspective(glm::mat4 pers);
private:
	Shader shader;
	MeshChidori mesh;
	glm::mat4 translation,
		scale,
		rotation,
		camera,
		perspective;
	glm::vec3 color;
	//Object3D();

};

