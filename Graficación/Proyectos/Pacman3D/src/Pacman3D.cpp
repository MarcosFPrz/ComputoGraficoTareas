
#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "Application.h"

Application app;

//Se tiene que llamar despues de inicializar la ventana y el OpenGL, pero antes del main loop
void setup(){
	app.setup();
}

//Se ejecuta siempre que se necesite actualizar la imagen
void display(){
	app.display();
}

//Se ejecuta cuando la ventana cambia de tamaño. Parámetros en pixeles.
//(ojo: En otros programas se debe ejecutar glViewport)
void reshape(int w, int h){
	app.reshape(w, h);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	app.keyboard(key, scancode, action, mods);
}

void cursor_position(GLFWwindow* window, double xpos, double ypos)
{
	app.cursor_position(xpos, ypos);
}

int main(int argc, char *argv[]){
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(1080, 1080, "Hello Texture", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE; 
	glewInit();
	app.setup();

	// get version info 
	const GLubyte* renderer = glGetString (GL_RENDERER); 
	const GLubyte* version = glGetString (GL_VERSION); 
	printf (" Renderer: %s\ n", renderer); 
	printf (" OpenGL version supported %s\ n", version); 
	
	// tell GL to only draw onto a pixel if the shape is closer to the viewer 
	//glEnable (GL_DEPTH_TEST); // enable depth-testing 	
	//glDepthFunc (GL_LESS); // depth-testing interprets a smaller value as "closer" 

	glEnable(GL_DEPTH_TEST); //Z-buffer
	glEnable(GL_BLEND);
	glfwSetKeyCallback(window, key_callback);
	
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    
		glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
		glDepthRange(0.1, 1.0);
		/* update other events like input handling */
		glfwPollEvents();
		app.update();
		/* put the stuff we've been drawing onto the display */
		glViewport(0, 0, (GLsizei)1080, (GLsizei)1080);
		app.display();

		glDepthRange(0.0, 0.1);
		glViewport(0, 0, (GLsizei)1080/4, (GLsizei)1080/4);
		app.display2();
		glfwSwapBuffers(window);
	}
	
	/* close GL context and any other GLFW resources */
	glfwTerminate();
	return 0;

}
