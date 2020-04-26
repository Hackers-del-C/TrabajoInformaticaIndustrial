#pragma once
#include "Plataformas.h"
#include <vector>
#define NUM_MAX_PLATAFORMAS 100
class ListaPlataformas{

public:
	ListaPlataformas::ListaPlataformas();
	
	~ListaPlataformas();

	bool Agregar(Plataformas* p);
	void DestruirContenido(int ind);
	void Dibuja(float x1, float y1, float x2, float y2);

private:
	std::vector<Plataformas*>lista;
	//Disparo* lista[NUM_MAX_DISPAROS];
	//int numero;

};