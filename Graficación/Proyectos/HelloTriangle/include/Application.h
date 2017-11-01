#pragma once

#include <iostream>
#include "Object3D.h"

class Application {
public:
	Application();
	~Application();

	void setup();
	void update();
	void display();
	void reshape(int w, int h);


private:
	GLfloat angle;
	GLint angleID;
	Object3D triangle;
};

