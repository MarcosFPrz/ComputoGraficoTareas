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
	void display2();
	void displayEditor();
	void displayGame();
	void displayMiniMap();
	void reshape(int w, int h);
	void cursor_position(double xpos, double ypos);
	void IAfantasmas();

private:
	GLuint angleID, transformID;
	Object3D camino, piso, muro, pildora, pacman, fantasma;

	std::vector<std::vector<int>> Mapa
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,2,1},
		{1,2,1,2,1,2,1,2,1,1,2,1,2,1,2,1,2,1},
		{1,2,1,2,1,2,1,2,1,1,2,1,2,1,2,1,2,1},
		{1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1},
		{1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1},
		{1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1},
		{1,2,1,1,2,1,2,1,2,2,1,2,1,2,1,1,2,1},
		{1,2,2,1,2,1,2,1,4,4,1,2,1,2,1,2,2,1},
		{1,1,2,1,2,1,2,1,4,4,1,2,1,2,1,2,1,1},
		{1,1,2,1,2,1,2,1,1,1,1,2,1,2,1,2,1,1},
		{1,2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,1},
		{1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1},
		{1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1},
		{1,2,1,2,1,2,1,2,1,1,2,1,2,1,2,1,2,1},
		{1,2,1,2,1,2,1,2,1,1,2,1,2,1,2,1,2,1},
		{1,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,2,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}

	};

	bool moveZmenos = false;
	bool moveZmas = false;
	bool moveXmenos = false;
	bool moveXmas = false;
	bool edit = false;
	bool game = false;
	bool type = false;

	int x, y, iPac, jPac;	
	int i, j;
	
	glm::mat4 camera, rotateY, rotateX;
	glm::mat4 transformP;
	glm::vec3 eye, target, angles;
};

