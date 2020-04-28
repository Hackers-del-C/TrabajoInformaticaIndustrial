#pragma once

#include <vector>
#define NUM_MAX_misiles 200
#include "Misil.h"
#include "Hombre.h"
class ListaMisil {

public:
	ListaMisil();
	~ListaMisil();

	bool Agregar(Misil* d);
	void DestruirContenido(int ind);
	void Mueve(float t);
	void Dibuja();
	void Inicializa();

	Misil* colision(Hombre& h);
	std::vector<Misil*>lista;
	//Disparo* lista[NUM_MAX_DISPAROS];
	//int numero;

};