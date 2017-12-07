
#include "Application.h"
#include <iostream>
#include <vector>

#include "GL\glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"


#include "ShaderFuncs.h"

std::vector<GLfloat> vertexPositions = {
	//Quad1
		-1.0f, 1.0f, -1.0f, 1.0f, //h
		1.0f, -1.0f, -1.0f, 1.0f, //n
		1.0f, 1.0f,	-1.0f, 1.0f, //g
		-1.0f, 1.0f, -1.0f, 1.0f, //h
		1.0f, -1.0f, -1.0f, 1.0f, //n
		-1.0f, -1.0f, -1.0f, 1.0f, //m

	//Quad2
		-1.0f, 1.0f, -1.0f, 1.0f, //h
		1.0f, 1.0f,	-1.0f, 1.0f, //g
		-1.0f, 1.0f, 1.0f, 1.0f, //d
		1.0f, 1.0f,	-1.0f, 1.0f, //g
		-1.0f, 1.0f, 1.0f, 1.0f, //d
		1.0f, 1.0f, 1.0f, 1.0f, //c

	//Quad3
		-1.0f, 1.0f, 1.0f, 1.0f, //d
		1.0f, 1.0f, 1.0f, 1.0f, //c
		-1.0f, -1.0f, 1.0, 1.0, //a
		1.0f, 1.0f, 1.0f, 1.0f, //c
		-1.0f, -1.0f, 1.0, 1.0, //a
		1.0f, -1.0f, 1.0f, 1.0f, //b

	//Quad4
		1.0f, 1.0f, 1.0f, 1.0f, //c
		1.0f, -1.0f, 1.0f, 1.0f, //b
		1.0f, 1.0f, -1.0f, 1.0f, //i
		1.0f, -1.0f, 1.0f, 1.0f, //b
		1.0f, 1.0f, -1.0f, 1.0f, //i
		1.0f, -1.0f, -1.0f, 1.0f, //j

	//Quad5
		-1.0f, 1.0f, 1.0f, 1.0f, //d
		-1.0f, -1.0f, 1.0, 1.0, //a
		-1.0f, 1.0f, -1.0f, 1.0f, //h
		-1.0f, -1.0f, 1.0, 1.0, //a
		-1.0f, 1.0f, -1.0f, 1.0f, //h
		-1.0f, -1.0f, -1.0f, 1.0f, //m

	//Quad6
		1.0f, -1.0f, 1.0f, 1.0f, //b
		-1.0f, -1.0f, 1.0, 1.0, //a
		-1.0f, -1.0f, -1.0f, 1.0f, //m
		1.0f, -1.0f, 1.0f, 1.0f, //b
		-1.0f, -1.0f, -1.0f, 1.0f, //m
		1.0f, -1.0f, -1.0f, 1.0f, //n
};

Application::Application() : /*eye(1.0f, -7.0f, 1.0f), 
							target (10.0f, 10.0f, 1.0f), 
							angles(0.0f, 0.0f, 0.0f)*/
	eye(0.0f, -7.0f, 6.0f),
	target(0.0f, 0.0f, 0.0f),
	angles(0.0f, 0.0f, 0.0f)
{

}

Application::~Application() 
{}
glm::mat4 trans2;
void Application::update()
{
	angles.x += 0.05f;
	angles.y += 0.05f;

	camera = glm::lookAt(eye, target, glm::vec3(1.0f, 1.0f, 0.0f));
	transformR = glm::rotate(glm::mat4(1.0f), glm::radians(angles.x), glm::vec3(1.0f, 0.0f, 0.0f));
	/*transform = glm::rotate(transform, glm::radians(angles.y), glm::vec3(0.0f, 1.0f, 0.0f));
	transform = glm::perspective(45.0f, 1.0f, 0.1f, 10.0f) * 
				camera * transform;
	trans2 = glm::perspective(45.0f, 1.0f, 0.1f, 10.0f) *
		camera * glm::translate(glm::mat4(1),glm::vec3(1,1,1)) * glm::scale(glm::mat4(1),glm::vec3(0.5f,0.5f,0.5f));*/
}

void Application::keyboard(int key, int scancode, int actions, int mods)
{
	if (key == GLFW_KEY_ESCAPE && actions == GLFW_PRESS) {
		exit(0);
	}
	if (actions == GLFW_RELEASE)
	{
		switch (key)
		{

		case GLFW_KEY_Y:
			++angles.y;
			break;

		case GLFW_KEY_X:
			++angles.x;
			break;
		}
	}
	else if (actions == GLFW_REPEAT)
	{
		switch (key)
		{
		case GLFW_KEY_Y:
			angles.y += 1.0f;
			break;

		case GLFW_KEY_X:
			angles.x += 1.0f;
			break;

		case GLFW_KEY_LEFT:
			angles.y -= 1.0f;
			break;

		case GLFW_KEY_RIGHT:
			angles.y += 1.0f;
			break;

		case GLFW_KEY_UP:
			angles.x -= 1.0f;
			break;

		case GLFW_KEY_DOWN:
			angles.x += 1.0f;
			break;
		}
	}
}

void Application::setup()
{
	piso.setShaders("shaders\\vertex.vs", "shaders\\fragment.fs");
	piso.setUp(vertexPositions, NULL);
	piso.SetColor(glm::vec3(0.0, 0.0, 0.0));

	muro.setShaders("shaders\\vertex.vs", "shaders\\fragment.fs");
	muro.setUp(vertexPositions, NULL);
	muro.SetColor(glm::vec3(0.0, 0.0, 1.0));

	pildora.setShaders("shaders\\vertex.vs", "shaders\\fragment.fs");
	pildora.setUp(vertexPositions, NULL);
	pildora.SetColor(glm::vec3(1.0, 1.0, 0.0));

	pacman.setShaders("shaders\\vertex.vs", "shaders\\fragment.fs");
	pacman.setUp(vertexPositions, NULL);
	pacman.SetColor(glm::vec3(1.0, 1.0, 0.0));

}

void Application::display()
{
	glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Piso
	piso.SetScale(glm::scale(glm::mat4(1.0f), glm::vec3(10.0f, 0.0f, 10.0f)));
	piso.SetPerspective(glm::perspective(42.0f, 1.0f, 0.2f, 10.0f));
	piso.SetCamera(glm::lookAt(eye, target, glm::vec3(0.0f, 1.0f, 0.0f)));
	piso.draw();

	//Pacman
	pacman.SetScale(glm::scale(glm::mat4(1.0f), glm::vec3(0.2f, 0.2f, 0.2f)));
	//pacman.SetTranslation(glm::translate(glm::mat4(1.0f), glm::vec3(i * 2, 0.0f, j * 2)));
	pacman.SetPerspective(glm::perspective(42.0f, 1.0f, 0.2f, 10.0f));
	pacman.SetCamera(glm::lookAt(eye, target, glm::vec3(0.0f, 1.0f, 0.0f)));
	pacman.draw();

	for (int i = 0; i < Mapa.size(); ++i)
		for (int j = 0; j < Mapa[i].size(); ++j)
		{
			//Muros
			muro.SetScale(glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f)));
			muro.SetTranslation(glm::translate(glm::mat4(1.0f), glm::vec3(i * 2, 0.0f, j * 2)));
			muro.SetPerspective(glm::perspective(42.0f, 1.0f, 0.2f, 10.0f));
			muro.SetCamera(glm::lookAt(eye, target, glm::vec3(0.0f, 1.0f, 0.0f)));

			//Pildoras
			pildora.SetScale(glm::scale(glm::mat4(1.0f), glm::vec3(0.2f, 0.2f, 0.2f)));
			pildora.SetTranslation(glm::translate(glm::mat4(1.0f), glm::vec3(i * 2, 0.0f, j * 2)));
			pildora.SetPerspective(glm::perspective(42.0f, 1.0f, 0.2f, 10.0f));
			pildora.SetCamera(glm::lookAt(eye, target, glm::vec3(0.0f, 1.0f, 0.0f)));

			if (Mapa[i].at(j) == Muro)
			{
				muro.draw();
			}

			if (Mapa[i].at(j) == Pildorita)
			{
				pildora.draw();
			}
			
			if (Mapa[i].at(j) == Pacman)
			{
				pacman.draw();
			}
		}
}


void Application::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}
