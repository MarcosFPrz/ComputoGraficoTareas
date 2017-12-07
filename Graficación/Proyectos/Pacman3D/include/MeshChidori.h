#pragma once
#include <string>
#include <vector>
#include "GL\glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>


class MeshChidori {
public:
	MeshChidori();
	MeshChidori(std::string file);
	MeshChidori(std::vector<GLfloat> vertices, std::vector<GLuint>* indexes);
	void LoadFile(std::string file);
	void LoadFromMesh(std::vector<GLfloat> vertices, std::vector<GLuint>* indexes);
	void ActivateMesh();
	size_t getVertexNum();
	size_t getIndexSize();
	bool getIsIndexed();
private:
	GLuint	vao, //Vertex Array Object
			vbo,
			ibo; //Vertex Buffer Object
	size_t  vertexNum,
			indexSize;
	bool isIndexed = false;
};