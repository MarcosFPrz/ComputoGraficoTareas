#pragma once

#include <iostream>
#include "Object3D.h"
#include "MapaLocochon.h"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/vec4.hpp"
#include "glm/vec3.hpp"
#include "GLFW\glfw3.h"

class Application {
public:
	Application();
	~Application();

	GLFWwindow* window;

	void keyboard(int key, int scancode, int actions, int mods);
	void setup();
	void update();
	void display();
	void reshape(int w, int h);

private:
	GLuint angleID, transformID;
	Object3D camino,piso, muro, pildora, pacman;

	std::vector<std::vector<int>> Mapa
	{
		{1,1,1,1,1},
		{1,2,2,2,1},
		{1,2,1,2,1},
		{1,2,2,2,1},
		{1,1,1,1,1}
	};

	int xi;
	int yi;

	glm::mat4 camera;
	glm::mat4 transformR;
	glm::vec3 eye, target, angles;

};

