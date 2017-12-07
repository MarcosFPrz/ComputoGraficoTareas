#include "..\include\MapaLocochon.h"

MapaLocochon::MapaLocochon(std::string shaderV, std::string shaderF, int mapaLargo, int mapaAncho)
{
	Shader basicShader;
	basicShader.LoadShaders(shaderV, shaderF);
	largo = mapaLargo;
	ancho = mapaAncho;
	for (int i = largo; largo--;)
	{
		mapa.push_back(std::vector<TilesChidoris>());
		for (int j = ancho; ancho--;)
		{
			mapa.at(i).push_back(TilesChidoris::Vacio);
		}
	}
	fantasmas.resize(4);
	for (int i = 4; i--;)
	{
		fantasmas.at(i).setShader(basicShader);
	}
	pacman.setShader(basicShader);
	suelo.setShader(basicShader);
	//pildora.setShaders(shaderV, shaderF);
	//suelo.setShaders(shaderV, shaderF);
	//pacman.setShaders(shaderV, shaderF);

}

void MapaLocochon::SetMeshes(MeshChidori muroM, MeshChidori pacmanM, MeshChidori pildoraM, MeshChidori fantasmaM, MeshChidori sueloM)
{
	for (int i = muros.size(); i--;)
		muros.at(i).setMesh(muroM);
	for (int i = pildoras.size(); i--;)
		pildoras.at(i).setMesh(pildoraM);
	for (int i = fantasmas.size(); i--;)
		fantasmas.at(i).setMesh(fantasmaM);
	pacman.setMesh(pacmanM);
	suelo.setMesh(sueloM);
}

void MapaLocochon::SetNumObjs(int numMur, int numPil)
{
	//TODO: GUARDAR LOS NUMEROS DE COSAS, SETEAR SHADERS A LOS QUE NO LOS TENGAN (PILDORAS Y MUROS)
}

void MapaLocochon::SetupMapa()
{
	//TODO: SETTEAR TODAS LAS TRANSFORMACIONES DE TODOS LOS OBJETOS
}

MapaLocochon::~MapaLocochon()
{
}

void MapaLocochon::DibujarBienVergas(glm::mat4 camera, int anchoVent, int largoVent)
{
	//LLAMAR AL METODO DRAW DE TODOS LOS OBJETOS Y LLAMAR ANTES A SETCAMERA PARA DECIRLES DONDE ESTA LA CAMARA
}
