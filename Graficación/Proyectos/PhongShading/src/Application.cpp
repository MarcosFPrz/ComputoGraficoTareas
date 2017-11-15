
#include "Application.h"
#include <iostream>
#include <vector>
#include "GL\glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "ShaderFuncs.h"

GLfloat vertexPositions[] = {

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


GLfloat vertexColors[] = {
	//Quad1 RED
	1.0f, 0.0f, 0.0f, 0.5f,
	1.0f, 0.0f, 0.0f, 0.5f,
	1.0f, 0.0f, 0.0f, 0.5f,
	1.0f, 0.0f, 0.0f, 0.5f,
	1.0f, 0.0f, 0.0f, 0.5f,
	1.0f, 0.0f, 0.0f, 0.5f,

	//Quad2 GREEN
	0.0f, 1.0f, 0.0f, 0.5f,
	0.0f, 1.0f, 0.0f, 0.5f,
	0.0f, 1.0f, 0.0f, 0.5f,
	0.0f, 1.0f, 0.0f, 0.5f,
	0.0f, 1.0f, 0.0f, 0.5f,
	0.0f, 1.0f, 0.0f, 0.5f,

	//Quad3 BLUE
	0.0f, 0.0f, 1.0f, 0.5f,
	0.0f, 0.0f, 1.0f, 0.5f,
	0.0f, 0.0f, 1.0f, 0.5f,
	0.0f, 0.0f, 1.0f, 0.5f,
	0.0f, 0.0f, 1.0f, 0.5f,
	0.0f, 0.0f, 1.0f, 0.5f,

	//Quad4 WHITE
	1.0f, 1.0f, 1.1f, 1.0f,
	1.0f, 1.0f, 1.1f, 1.0f,
	1.0f, 1.0f, 1.1f, 1.0f,
	1.0f, 1.0f, 1.1f, 1.0f,
	1.0f, 1.0f, 1.1f, 1.0f,
	1.0f, 1.0f, 1.1f, 1.0f,

	//Quad5 YELLOW
	1.0f, 1.0f, 0.0f, 0.0f,
	1.0f, 1.0f, 0.0f, 0.0f,
	1.0f, 1.0f, 0.0f, 0.0f,
	1.0f, 1.0f, 0.0f, 0.0f,
	1.0f, 1.0f, 0.0f, 0.0f,
	1.0f, 1.0f, 0.0f, 0.0f,

	//Quad6 ORANGE
	1.0f, 0.65f, 0.0f, 0.0f,
	1.0f, 0.65f, 0.0f, 0.0f,
	1.0f, 0.65f, 0.0f, 0.0f,
	1.0f, 0.65f, 0.0f, 0.0f,
	1.0f, 0.65f, 0.0f, 0.0f,
	1.0f, 0.65f, 0.0f, 0.0f,
};

Application::Application():oPlane() {
	eye = glm::vec3(0.0f, 100.0f, 100.0f);
	target = glm::vec3(0.0f, 0.0f, 0.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	time = 0;
	myLightPosition = glm::vec3(0.0f, 50.0f, -50.0f);
}

Application::~Application() {}

void Application::update(){
	time += 0.2f;

	angles.x += 0.05f;
	angles.y += 0.05f;
	lookAt = glm::lookAt(eye, target, up);
	scaleCube = glm::scale(glm::mat4(1.0f), glm::vec3(10.0f, 10.0f, 10.0f));
	moveCube = glm::translate(glm::mat4(1.0f), glm::vec3(myLightPosition));
	transformCube = glm::rotate(glm::mat4(1.0f), glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	transformCube = glm::rotate(glm::mat4(1.0f), glm::radians(angles.y), glm::vec3(0.0f, 1.0f, 0.0f)) *transformCube;
	perspective = glm::perspective(45.0f, 1024.0f / 768.0f, 0.1f, 300.0f);
	transformCube = perspective * lookAt * moveCube * transformCube * scaleCube;
	transform = perspective * lookAt * rotateX * rotateY;
}

void Application::setup(){
	oPlane.createPlane(10);

	//Plano(Gourund Shading)
	std::string strVertexShader = loadTextFile("Shaders/gouradShading.v");
	std::string strFragmentShader = loadTextFile("Shaders/PhongShading.f");

	//Cube
	std::string strVertexShaderCube = loadTextFile("Shaders\\vertex.vs");
	std::string strFragmentShaderCube = loadTextFile("Shaders\\fragment.fs");

	//Plano
	InitializeProgram(oPlane.shader[0], strVertexShader, strFragmentShader);
	
	//Cube
	InitializeProgram(triangle.shader[0], strVertexShaderCube, strFragmentShaderCube);

	//Plano
	mTransformID[0] = glGetUniformLocation(oPlane.shader[0], "mTransform");
	cameraID[0] = glGetUniformLocation(oPlane.shader[0], "camera");
	perspectiveID[0] = glGetUniformLocation(oPlane.shader[0], "perspective");
	fTimeID[0] = glGetUniformLocation(oPlane.shader[0], "fTime");
	eyeID[0] = glGetUniformLocation(oPlane.shader[0], "vEye");
	myLightPositionID[0] = glGetUniformLocation(oPlane.shader[0], "myLightPosition");

	idTransformCube[0] = glGetUniformLocation(triangle.shader[0], "transformCube");

	//Cube
	triangle.numVertex = 36; //Numero de vertices
	glGenVertexArrays(1, &triangle.vao);
	glBindVertexArray(triangle.vao);
	glGenBuffers(1, &triangle.vbo);
	glBindBuffer(GL_ARRAY_BUFFER, triangle.vbo);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions) + sizeof(vertexColors), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0/*offset*/, sizeof(vertexPositions), vertexPositions);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertexPositions), sizeof(vertexColors), vertexColors);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)sizeof(vertexPositions));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	//Plano
	glGenVertexArrays(1, &oPlane.vao);
	glBindVertexArray(oPlane.vao);
	glGenBuffers(1, &oPlane.vbo);
	glBindBuffer(GL_ARRAY_BUFFER, oPlane.vbo);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, oPlane.getVertexSizeInBytes() + oPlane.getTextureCoordsSizeInBytes(), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, oPlane.getVertexSizeInBytes(), oPlane.plane);
	glBufferSubData(GL_ARRAY_BUFFER, oPlane.getVertexSizeInBytes(), oPlane.getTextureCoordsSizeInBytes(), oPlane.textureCoords);
	oPlane.cleanMemory();

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	//glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)(oPlane.getVertexSizeInBytes-

	glEnableVertexAttribArray(0);
	//glEnableVertexAttribArray(1);
	//glEnable(GL_DEPTH_TEST);
}

void Application::display(){
	//Borramos el buffer de color
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	//Plano
	displayPlane();

	//Cubo
	displayCubo();

	
}

void Application::displayCubo()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//Seleccionamos los shaders a usar
	glUseProgram(triangle[0].shader);
	glUniformMatrix4fv(idTransformCube[0], 1, GL_FALSE, glm::value_ptr(transformCube));

	//activamos el vertex array object y dibujamos
	glBindVertexArray(triangle.vao);

	glDrawArrays(GL_TRIANGLES, 0, triangle.numVertex);
}

void Application::displayPlane()
{
	//Seleccionamos los shaders a usar
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glUseProgram(oPlane[0].shader);

	//activamos el vertex array object y dibujamos
	glBindVertexArray(oPlane[0].vao);
	//lookAt = glm::lookAt(eye, target, up);
	//perspective = glm::perspective(45.0f, 1024.0f / 768.0f, 0.1f, 300.0f);
	transform = glm::mat4(1.0f);

	//Tranformacion del modelo
	glUniformMatrix4fv(mTransformID[0], 1, false, glm::value_ptr(transform));

	//Transformacion de camera
	glUniformMatrix4fv(cameraID[0], 1, false, glm::value_ptr(lookAt));

	//Trandformacion de proyeccion
	glUniformMatrix4fv(perspectiveID[0], 1, false, glm::value_ptr(perspective));

	//parametro de fase para shaders
	glUniform1f(fTimeID[0], glm::radians(time));
	glUniform3fv(eyeID[0], 1, glm::value_ptr(eye));
	glm::vec3 newLight = myLightPosition;
	newLight.z = myLightPosition.z * cos(glm::radians(time));
	glUniform3fv(myLightPositionID[0], 1, glm::value_ptr(newLight));


	//glUniform3fv(oPlane.uEye, 1, glm::value_ptr(eye));
	glDrawArrays(GL_TRIANGLES, 0, oPlane.getNumVertex());
}

void Application::reshape(int w, int h){
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

void Application::cursor_position(double xpos, double ypos)
{
	rotateY = glm::rotate(glm::mat4(1.0f), glm::radians((float)xpos/2.84f), glm::vec3(0.0f, 1.0f, 0.0f));
	rotateX = glm::rotate(glm::mat4(1.0f), glm::radians((float)ypos/2.02f), glm::vec3(1.0f, 0.0f, 0.0f));
}

void Application::keyboard(int key, int scancode, int action, int mods){
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		exit(0);
	}
	if (action == GLFW_RELEASE) 
	{
		switch (key)
		{
		case GLFW_KEY_RIGHT:
			myLightPosition.x += 5.0f;
			break;

		case GLFW_KEY_LEFT:
			myLightPosition.x -= 5.0f;
			break;

		case GLFW_KEY_DOWN:
			myLightPosition.y -= 5.0f;
			break;

		case GLFW_KEY_UP:
			myLightPosition.y += 5.0f;
			break;

		case GLFW_KEY_Z:
			myLightPosition.z += 5.0f;
			break;

		case GLFW_KEY_X:
			myLightPosition.z -= 5.0f;
			break;
		}
		return;
	}
}
