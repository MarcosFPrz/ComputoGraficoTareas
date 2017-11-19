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


Application::Application() :oPlane() {
	eye = glm::vec3(0.0f, 120.0f, 110.0f);
	target = glm::vec3(0.0f, 0.0f, 0.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	time = 0;
	myLightPosition = glm::vec3(0.0f, 50.0f, -50.0f);
	lA = glm::vec3(0.2, 0.2, 0.2);
	lD = glm::vec3(0.4, 0.4, 0.4);
	lS = glm::vec3(1.0);
	mA = glm::vec3(1.0);
	mD = glm::vec3(1.0);
	mS = glm::vec3(1.0);
}

Application::~Application() {}

void Application::update() {
	time += 0.9f;

	angles.x += 0.05f;
	angles.y += 0.05f;
	lookAt = glm::lookAt(eye, target, up);
	scaleCube = glm::scale(glm::mat4(1.0f), glm::vec3(10.0f, 10.0f, 10.0f));
	moveCube = glm::translate(glm::mat4(1.0f), glm::vec3(myLightPosition));
	transformCube = glm::rotate(glm::mat4(1.0f), glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	transformCube = glm::rotate(glm::mat4(1.0f), glm::radians(angles.y), glm::vec3(0.0f, 1.0f, 0.0f)) *transformCube;
	perspective = glm::perspective(45.0f, 1024.0f / 768.0f, 0.1f, 300.0f);
	
	transformCube = perspective * lookAt * moveCube * transformCube * scaleCube;
	transform = perspective * lookAt * rotateY * rotateX;
}

void Application::setup() {
	oPlane.createPlane(10);

	//PlanoGouraud
	std::string strVertexShaderGourand = loadTextFile("Shaders/gouradPlane.v");
	std::string strFragmentShaderGourand = loadTextFile("Shaders/passThru.f");

	//Cube
	std::string strVertexShaderCube = loadTextFile("Shaders\\vertex.vs");
	std::string strFragmentShaderCube = loadTextFile("Shaders\\fragment.fs");

	//PlanoPhong
	std::string strVertexShaderPhong = loadTextFile("Shaders/PhongShading.v");
	std::string strFragmentShaderPhong = loadTextFile("Shaders/PhongShading.f");
	
	//PlanoGourand
	InitializeProgram(oPlane.shader, strVertexShaderGourand, strFragmentShaderGourand);

	//Cube
	InitializeProgram(triangle.shader, strVertexShaderCube, strFragmentShaderCube);

	//PlanoPhong
	InitializeProgram(oPlane.shader, strVertexShaderPhong, strFragmentShaderPhong);

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

	//PlanoPhong
	mTransformID = glGetUniformLocation(oPlane.shader, "mTransform");
	cameraID = glGetUniformLocation(oPlane.shader, "camera");
	perspectiveID = glGetUniformLocation(oPlane.shader, "perspective");

	fTimeID = glGetUniformLocation(oPlane.shader, "fTime");
	eyeID = glGetUniformLocation(oPlane.shader, "vEye");
	myLightPositionID = glGetUniformLocation(oPlane.shader, "myLightPosition");

	laID = glGetUniformLocation(oPlane.shader, "lA");
	lsID = glGetUniformLocation(oPlane.shader, "lS");
	ldID = glGetUniformLocation(oPlane.shader, "lD");
	maID = glGetUniformLocation(oPlane.shader, "mA");
	mdID = glGetUniformLocation(oPlane.shader, "mD");
	msID = glGetUniformLocation(oPlane.shader, "mS");

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
	glEnableVertexAttribArray(1);
	//glEnable(GL_DEPTH_TEST);
}

void Application::display() {
	//Borramos el buffer de color
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	displayPlane();
	
	displayCubo();
	
}

void Application::displayCubo()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//Seleccionamos los shaders a usar
	glUseProgram(triangle.shader);
	glUniformMatrix4fv(idTransformCube, 1, GL_FALSE, glm::value_ptr(transformCube));

	//activamos el vertex array object y dibujamos
	glBindVertexArray(triangle.vao);

	glDrawArrays(GL_TRIANGLES, 0, triangle.numVertex);
}

void Application::displayPlane()
{
	//Seleccionamos los shaders a usar
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glUseProgram(oPlane.shader);

	//activamos el vertex array object y dibujamos
	glBindVertexArray(oPlane.vao);
	lookAt = glm::lookAt(eye, target, up);
	perspective = glm::perspective(45.0f, 1024.0f / 760.0f, 0.1f, 200.0f);
	transform = glm::mat4(1.0f);

	//transformaciones del modelo
	glUniformMatrix4fv(mTransformID, 1, false, glm::value_ptr(transform));

	//transformacion de camara
	glUniformMatrix4fv(cameraID, 1, false, glm::value_ptr(lookAt));

	//transformacion de proyeccion
	glUniformMatrix4fv(perspectiveID, 1, false, glm::value_ptr(perspective));


	//parametro de fase para shaders
	glUniform1f(fTimeID, glm::radians(time));
	glUniform3fv(eyeID, 1, glm::value_ptr(eye));
	glm::vec3 newLight = myLightPosition;
	newLight.z = myLightPosition.z * cos(glm::radians(time));
	glUniform3fv(myLightPositionID, 1, glm::value_ptr(newLight));



	glUniform3fv(laID, 1, glm::value_ptr(lA));
	glUniform3fv(ldID, 1, glm::value_ptr(lD));
	glUniform3fv(lsID, 1, glm::value_ptr(lS));
	glUniform3fv(maID, 1, glm::value_ptr(mA));
	glUniform3fv(msID, 1, glm::value_ptr(mS));
	glUniform3fv(mdID, 1, glm::value_ptr(mD));


	//glUniform3fv(oPlane.uEye, 1, glm::value_ptr(eye));
	glDrawArrays(GL_TRIANGLES, 0, oPlane.getNumVertex());
}

void Application::reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

void Application::cursor_position(double xpos, double ypos)
{
	rotateY = glm::rotate(glm::mat4(1.0f), glm::radians((float)xpos / 2.84f), glm::vec3(0.0f, 1.0f, 0.0f));
	rotateX = glm::rotate(glm::mat4(1.0f), glm::radians((float)ypos / 2.02f), glm::vec3(1.0f, 0.0f, 0.0f));
}

void Application::keyboard(int key, int scancode, int action, int mods) {
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

		case GLFW_KEY_A:
			lA += glm::vec3(0.2);
			break;

		case GLFW_KEY_S:
			lS += glm::vec3(0.2);
			break;

		case GLFW_KEY_D:
			lD += glm::vec3(0.2);
			break;

		case GLFW_KEY_M:
			mA += glm::vec3(2.0);
			break;

		case GLFW_KEY_N:
			mS += glm::vec3(2.0);
			break;

		case GLFW_KEY_B:
			mD += glm::vec3(2.0);
			break;

		case GLFW_KEY_SPACE:
			lA = glm::vec3(1.0, 1.0, 1.0);
			lS = glm::vec3(5.0, 5.0, 5.0);
			lD = glm::vec3(1.0, 1.0, 1.0);
			mA = glm::vec3(0.0, 0.0, 0.0);
			mS = glm::vec3(2.0, 2.0, 2.0);
			mD = glm::vec3(1.0, 0.5, 1.0);
			break;

		}
		return;
	}

}