#pragma once
#include "Plataformas.h"
//#include "Interaccion.h"
#include <vector>
#define NUM_MAX_PLATAFORMAS 100
class ListaPlataformas{

public:
	ListaPlataformas();
	
	~ListaPlataformas();

	bool Agregar(Plataformas* p);
	void DestruirContenido(int ind);
	void Dibuja();



private:
	std::vector<Plataformas*>lista;
	//Disparo* lista[NUM_MAX_DISPAROS];
	//int numero;

};