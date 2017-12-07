#include "MeshCHidori.h"
#include "OBJ_Loader.h"
void MeshChidori::LoadFile(std::string file)
{
	objl::Loader loader;
	std::vector<GLfloat> vertex;
	std::vector<GLuint> indexes;
	objl::Mesh mesh;
	int indexOffset = 0;
	bool result = loader.LoadFile(file);
	if (result)
	{
		for (int k = 0; k < loader.LoadedMeshes.size(); ++k)
		{
			mesh = loader.LoadedMeshes.at(k);
			for (int i = 0; i < mesh.Vertices.size(); ++i)
			{
				vertex.push_back(mesh.Vertices.at(i).Position.X);
				vertex.push_back(mesh.Vertices.at(i).Position.Y);
				vertex.push_back(mesh.Vertices.at(i).Position.Z);
				vertex.push_back(1);
			}
			indexOffset = 0;
			for (int i = 0; i < k; ++i)
				indexOffset += loader.LoadedMeshes.at(0).Vertices.size();
			for (int i = 0; i < mesh.Indices.size(); ++i)
			{
				indexes.push_back(indexOffset + mesh.Indices.at(i));
			}
		}
	}
	LoadFromMesh(vertex, &indexes);
}

void MeshChidori::LoadFromMesh(std::vector<GLfloat> vertices, std::vector<GLuint>* indexes)
{
	vertexNum = vertices.size() / 4;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	if (indexes != nullptr)
	{
		indexSize = indexes->size();
		glGenBuffers(1, &ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexes->size() * sizeof(GLuint), &indexes->at(0), GL_STATIC_DRAW);
		isIndexed = true;
	}
	glBufferData(GL_ARRAY_BUFFER, (sizeof(GLfloat) * vertices.size()), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat) * vertices.size(), vertices.data());
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
}

void MeshChidori::ActivateMesh()
{
	//activamos el vertex array object y dibujamos
	glBindVertexArray(vao);
	if (isIndexed)
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glEnableVertexAttribArray(0);
}

size_t MeshChidori::getVertexNum()
{
	return vertexNum;
}

size_t MeshChidori::getIndexSize()
{
	return indexSize;
}

bool MeshChidori::getIsIndexed()
{
	return isIndexed;
}

MeshChidori::MeshChidori()
{
}

MeshChidori::MeshChidori(std::string file)
{
	LoadFile(file);
}

MeshChidori::MeshChidori(std::vector<GLfloat> vertices, std::vector<GLuint>* indexes)
{
	LoadFromMesh(vertices, indexes);
}
