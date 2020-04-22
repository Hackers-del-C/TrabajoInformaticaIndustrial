#pragma once
#include <vector>
#define NUM_MAX_lanzamisiles 200
#include "Lanzamisiles.h"
class ListaLanzamisiles {

public:
	ListaLanzamisiles();
	~ListaLanzamisiles();

	bool Agregar(Lanzamisiles* d);
	void DestruirContenido(int ind);
	//void Mueve(float t);
	void Dibuja();

private:

	std::vector<Lanzamisiles*>lista;
	//Disparo* lista[NUM_MAX_DISPAROS];
	//int numero;

};