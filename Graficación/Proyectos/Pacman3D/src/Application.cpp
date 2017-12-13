
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

Application::Application()
{

}

Application::~Application()
{}

void Application::update()
{

	camera = glm::lookAt(eye,target, glm::vec3(1.0f, 1.0f, 1.0f)) * rotateY * rotateX;
	transformP = glm::translate(glm::mat4(1.0f), glm::vec3(angles.x, 0.0f, angles.z));

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
	pildora.SetColor(glm::vec3(1.0, 1.0, 1.0));

	pacman.setShaders("shaders\\vertex.vs", "shaders\\fragment.fs");
	pacman.setUp(vertexPositions, NULL);
	pacman.SetColor(glm::vec3(1.0, 1.0, 0.0));

	fantasma.setShaders("shaders\\vertex.vs", "shaders\\fragment.fs");
	fantasma.setUp(vertexPositions, NULL);
	fantasma.SetColor(glm::vec3(1.5, 0.5, 0.0));

}

void Application::displayMiniMap()
{
	eye = glm::vec3(21.0f, -8.0f, 18.0f);
	target = glm::vec3(20.0f, 16.0f, 18.0f);

	for (int i = 0; i < Mapa.size(); ++i)
		for (int j = 0; j < Mapa[i].size(); ++j)
		{
			//Muros
			muro.SetScale(glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f)));
			muro.SetTranslation(glm::translate(glm::mat4(1.0f), glm::vec3(i * 2, 10.0f, j * 2)));
			muro.SetPerspective(glm::perspective(42.0f, 1.0f, 0.2f, 150.0f));
			muro.SetCamera(glm::lookAt(eye, target, glm::vec3(0.0f, 1.0f, 0.0f)));

			//Pildoras
			pildora.SetScale(glm::scale(glm::mat4(1.0f), glm::vec3(0.2f, 0.2f, 0.2f)));
			pildora.SetTranslation(glm::translate(glm::mat4(1.0f), glm::vec3(i * 2, 10.0f, j * 2)));
			pildora.SetPerspective(glm::perspective(42.0f, 1.0f, 0.2f, 150.0f));
			pildora.SetCamera(glm::lookAt(eye, target, glm::vec3(0.0f, 1.0f, 0.0f)));

			//Piso
			piso.SetScale(glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 0.0f, 1.0f)));
			piso.SetTranslation(glm::translate(glm::mat4(1.0f), glm::vec3(i * 2, 10.0f, j * 2)));
			piso.SetPerspective(glm::perspective(42.0f, 1.0f, 0.2f, 150.0f));
			piso.SetCamera(glm::lookAt(eye, target, glm::vec3(0.0f, 1.0f, 0.0f)));

			//Pacman
			pacman.SetScale(glm::scale(glm::mat4(1.0f), glm::vec3(0.5f, 0.5f, 0.5f)));
			pacman.SetTranslation(glm::translate(transformP, glm::vec3(i * 2, 10.0f, j * 2)));
			pacman.SetPerspective(glm::perspective(42.0f, 1.0f, 0.2f, 150.0f));
			pacman.SetCamera(glm::lookAt(eye, target, glm::vec3(0.0f, 1.0f, 0.0f)));

			//Fantasma
			fantasma.SetScale(glm::scale(glm::mat4(1.0f), glm::vec3(0.4f, 0.4f, 0.4f)));
			fantasma.SetTranslation(glm::translate(glm::mat4(1.0f), glm::vec3(i * 2, 10.0f, j * 2)));
			fantasma.SetPerspective(glm::perspective(42.0f, 1.0f, 0.2f, 150.0f));
			fantasma.SetCamera(glm::lookAt(eye, target, glm::vec3(0.0f, 1.0f, 0.0f)));

			piso.draw();

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

			if (Mapa[i].at(j) == Fantasmita)
			{
				fantasma.draw();
			}

		}
}

void Application::cursor_position(double xpos, double ypos)
{
	std::cout << xpos << ", " << ypos << "\n";
	rotateY = glm::rotate(glm::mat4(1.0f), glm::radians((float)xpos / 2.84f), glm::vec3(0.0f, 1.0f, 0.0f));
	rotateX = glm::rotate(glm::mat4(1.0f), glm::radians((float)ypos / 2.02f), glm::vec3(1.0f, 0.0f, 0.0f));
}

void Application::displayEditor()
{
	eye = glm::vec3(21.0f, -8.0f, 18.0f);
	target = glm::vec3(20.0f, 16.0f, 18.0f);

	int x, y, objeto;

	if (type)
	{ 
		system("cls");
		for (int i = 0; i < Mapa.size(); ++i)
		{
			for (int j = 0; j < Mapa.at(i).size(); ++j)
			{
				std::cout << Mapa.at(i).at(j);
			}

			std::cout << "\n";
		}

		std::cout << "Escriba que posicion desea modificar\n";
		std::cout << "i = fila\n";
		std::cin >> x;
		std::cout << "j = columna\n";
		std::cin >> y;
		std::cout << "Que desea colocar?\n";
		std::cout << "0 = piso, 1 = Muro\n";
		std::cin >> objeto;

		if (objeto < 0 && objeto > 1)
		{
			std::cout << "Ingrese un numero entre 0 y 2\n";
		}
		else
		{
			Mapa[x].at(y) = objeto;
		}

		type = false;
	}

	for (int i = 0; i < Mapa.size(); ++i)
		for (int j = 0; j < Mapa[i].size(); ++j)
		{
			//Muros
			muro.SetScale(glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f)));
			muro.SetTranslation(glm::translate(glm::mat4(1.0f), glm::vec3(i * 2, 10.0f, j * 2)));
			muro.SetPerspective(glm::perspective(42.0f, 1.0f, 0.2f, 150.0f));
			muro.SetCamera(glm::lookAt(eye, target, glm::vec3(0.0f, 1.0f, 0.0f)));

			//Pildoras
			pildora.SetScale(glm::scale(glm::mat4(1.0f), glm::vec3(0.2f, 0.2f, 0.2f)));
			pildora.SetTranslation(glm::translate(glm::mat4(1.0f), glm::vec3(i * 2, 10.0f, j * 2)));
			pildora.SetPerspective(glm::perspective(42.0f, 1.0f, 0.2f, 150.0f));
			pildora.SetCamera(glm::lookAt(eye, target, glm::vec3(0.0f, 1.0f, 0.0f)));

			//Piso
			piso.SetScale(glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 0.0f, 1.0f)));
			piso.SetTranslation(glm::translate(glm::mat4(1.0f), glm::vec3(i * 2, 10.0f, j * 2)));
			piso.SetPerspective(glm::perspective(42.0f, 1.0f, 0.2f, 150.0f));
			piso.SetCamera(glm::lookAt(eye, target, glm::vec3(0.0f, 1.0f, 0.0f)));

			//Pacman
			pacman.SetScale(glm::scale(glm::mat4(1.0f), glm::vec3(0.5f, 0.5f, 0.5f)));
			pacman.SetTranslation(glm::translate(transformP, glm::vec3(i * 2, 10.0f, j * 2)));
			pacman.SetPerspective(glm::perspective(42.0f, 1.0f, 0.2f, 150.0f));
			pacman.SetCamera(glm::lookAt(eye, target, glm::vec3(0.0f, 1.0f, 0.0f)));

			//Fantasma
			fantasma.SetScale(glm::scale(glm::mat4(1.0f), glm::vec3(0.4f, 0.4f, 0.4f)));
			fantasma.SetTranslation(glm::translate(glm::mat4(1.0f), glm::vec3(i * 2, 10.0f, j * 2)));
			fantasma.SetPerspective(glm::perspective(42.0f, 1.0f, 0.2f, 150.0f));
			fantasma.SetCamera(glm::lookAt(eye, target, glm::vec3(0.0f, 1.0f, 0.0f)));

			piso.draw();

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

			if (Mapa[i].at(j) == Fantasmita)
			{
				fantasma.draw();
			}

		}
}

void Application::displayGame()
{
	eye = glm::vec3(23.0f, 9.0f, 18.0f);
	target = glm::vec3(22.0f, 9.0f, 18.0f);

	for (i = 0; i < Mapa.size(); ++i)
	{
		for (j = 0; j < Mapa[i].size(); ++j)
		{

			//Muros
			muro.SetScale(glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f)));
			muro.SetTranslation(glm::translate(glm::mat4(1.0f), glm::vec3(i * 2, 10.0f, j * 2)));
			muro.SetPerspective(glm::perspective(42.0f, 1.0f, 0.2f, 150.0f));
			muro.SetCamera(glm::lookAt(eye, target, glm::vec3(0.0f, 1.0f, 0.0f)));

			//Pildoras
			pildora.SetScale(glm::scale(glm::mat4(1.0f), glm::vec3(0.2f, 0.2f, 0.2f)));
			pildora.SetTranslation(glm::translate(glm::mat4(1.0f), glm::vec3(i * 2, 10.0f, j * 2)));
			pildora.SetPerspective(glm::perspective(42.0f, 1.0f, 0.2f, 150.0f));
			pildora.SetCamera(glm::lookAt(eye, target, glm::vec3(0.0f, 1.0f, 0.0f)));

			//Piso
			piso.SetScale(glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 0.0f, 1.0f)));
			piso.SetTranslation(glm::translate(glm::mat4(1.0f), glm::vec3(i * 2, 10.0f, j * 2)));
			piso.SetPerspective(glm::perspective(42.0f, 1.0f, 0.2f, 150.0f));
			piso.SetCamera(glm::lookAt(eye, target, glm::vec3(0.0f, 1.0f, 0.0f)));

			//Pacman
			pacman.SetScale(glm::scale(glm::mat4(1.0f), glm::vec3(0.5f, 0.5f, 0.5f)));
			pacman.SetTranslation(glm::translate(transformP, glm::vec3(i * 2, 10.0f, j * 2)));
			pacman.SetPerspective(glm::perspective(42.0f, 1.0f, 0.2f, 150.0f));
			pacman.SetCamera(glm::lookAt(eye, target, glm::vec3(0.0f, 1.0f, 0.0f)));

			//Fantasma
			fantasma.SetScale(glm::scale(glm::mat4(1.0f), glm::vec3(0.4f, 0.4f, 0.4f)));
			fantasma.SetTranslation(glm::translate(glm::mat4(1.0f), glm::vec3(i * 2, 10.0f, j * 2)));
			fantasma.SetPerspective(glm::perspective(42.0f, 1.0f, 0.2f, 150.0f));
			fantasma.SetCamera(glm::lookAt(eye, target, glm::vec3(0.0f, 1.0f, 0.0f)));

			piso.draw();

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

				if ((Mapa[i].at(j - 1) == Pildorita || Mapa[i].at(j - 1) == Vacio) && moveZmenos == true)
				{
					Mapa[i].at(j) = Vacio;
					Mapa[i].at(j - 1) = Pacman;
					moveZmenos = false;
				}

				else if ((Mapa[i].at(j + 1) == Pildorita || Mapa[i].at(j + 1) == Vacio) && moveZmas == true)
				{
					Mapa[i].at(j) = Vacio;
					Mapa[i].at(j + 1) = Pacman;
					moveZmas = false;
				}

				else if ((Mapa[i - 1].at(j) == Pildorita || Mapa[i - 1].at(j) == Vacio) && moveXmenos == true)
				{
					Mapa[i].at(j) = Vacio;
					Mapa[i - 1].at(j) = Pacman;
					moveXmenos = false;
				}

				else if ((Mapa[i + 1].at(j) == Pildorita || Mapa[i + 1].at(j) == Vacio) && moveXmas == true)
				{
					Mapa[i].at(j) = Vacio;
					Mapa[i + 1].at(j) = Pacman;
					moveXmas = false;
				}

				pacman.draw();

			}

			if (Mapa[i].at(j) == Fantasmita)
			{
				fantasma.draw();
			}

			if (Mapa[i].at(j) == Vacio)
			{
				piso.draw();
			}
		}
	}
}

void Application::IAfantasmas()
{

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

		case GLFW_KEY_A:
			moveZmenos = true;
			break;

		case GLFW_KEY_D:
			moveZmas = true;
			break;

		case GLFW_KEY_W:
			moveXmenos = true;
			break;

		case GLFW_KEY_S:
			moveXmas = true;
			break;

		case GLFW_KEY_T:
			type = true;
			break;

		case GLFW_KEY_SPACE:
			edit = true;
			game = false;
			break;

		case GLFW_KEY_ENTER:
			edit = false;
			game = true;
			break;
		} 
	}
}

void Application::display()
{
	if (game)
	{
		displayGame();
	}
	else if (edit)
	{
		displayEditor();
	}
}

void Application::display2()
{
	displayMiniMap();
}

void Application::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}



