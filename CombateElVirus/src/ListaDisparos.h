#pragma once
#include <vector>
#define NUM_MAX_DISPAROS 20
#include "Disparo.h"
class ListaDisparos {

public:
	ListaDisparos();
	~ListaDisparos();

	bool Agregar(Disparo* d);
	void DestruirContenido(int ind);
	void Mueve(float t);
	void Dibuja();
	
private:

	std::vector<Disparo*>lista;
	//Disparo* lista[NUM_MAX_DISPAROS];
	//int numero;
	
};