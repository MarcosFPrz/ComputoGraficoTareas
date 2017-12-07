#pragma once

#include <vector>
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/vec4.hpp"
#include "glm/vec3.hpp"
#include "Object3D.h"


//Apoco no krnal?
enum TilesChidoris
{
	Vacio = 0,
	Muro,
	Pildorita,
	Pacman,
	Fantasmita
};

class MapaLocochon {
public:
	MapaLocochon(std::string shaderV, std::string shaderF, int mapaLargo, int mapaAncho);

	void SetMeshes(MeshChidori muroM, MeshChidori pacmanM, MeshChidori pildoraM, MeshChidori fantasmaM, MeshChidori sueloM);
	void SetNumObjs(int numMur, int numPil);
	void SetupMapa();
	~MapaLocochon();

	void DibujarBienVergas(glm::mat4 camera, int anchoVent, int largoVent);
private:
	MapaLocochon() = delete;
	std::vector<std::vector<TilesChidoris>> mapa;
	Object3D pacman, suelo;
	std::vector<Object3D> muros, fantasmas, pildoras;
	int largo, ancho;
	int numMuros, numPildoras;
};