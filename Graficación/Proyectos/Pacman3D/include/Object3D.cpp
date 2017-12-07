#include "Object3D.h"

void Object3D::setUp(std::vector<GLfloat> vertex, std::vector<GLuint> * index)
{
	mesh.LoadFromMesh(vertex, index);
}
void Object3D::draw()
{
	shader.ActivateShader();
	shader.ApplyColor(color);
	shader.ApplyTransformation(perspective * camera* translation*rotation*scale);
	mesh.ActivateMesh();
	if (!mesh.getIsIndexed())
		glDrawArrays(GL_TRIANGLES, 0, mesh.getVertexNum());
	else
	{
		glDrawElements(GL_TRIANGLES, mesh.getIndexSize(), GL_UNSIGNED_INT, (void*)0);
	}
}
void Object3D::setShaders(std::string vS, std::string fS)
{
	shader.LoadShaders(vS, fS);
}

void Object3D::setMesh(MeshChidori mesha)
{
	mesh = mesha;
}

void Object3D::setShader(Shader shadera)
{
	shader = shadera;
}

void Object3D::LoadFromFile(std::string file)
{
	mesh.LoadFile(file);
}

void Object3D::SetTranslation(glm::mat4 trans)
{
	translation = trans;
}

void Object3D::SetScale(glm::mat4 sc)
{
	scale = sc;
}

void Object3D::SetRotation(glm::mat4 rot)
{
	rotation = rot;
}

void Object3D::SetColor(glm::vec3 col)
{
	color = col;
}

void Object3D::SetCamera(glm::mat4 cam)
{
	camera = cam;
}

void Object3D::SetPerspective(glm::mat4 pers)
{
	perspective = pers;
}
