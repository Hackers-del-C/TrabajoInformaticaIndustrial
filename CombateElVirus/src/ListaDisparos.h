#pragma once
#include <vector>
#define NUM_MAX_DISPAROS 20
#include "Disparo.h"
#include "Virus.h"

class ListaDisparos {

public:
	ListaDisparos();
	~ListaDisparos();

	bool Agregar(Disparo* d);
	void DestruirContenido(int ind);
	void Mueve(float t);
	void Dibuja();
	int getNumero() { return numero; }
	Disparo* operator [](int i);
	void eliminar(int index);
	bool Colision(Virus& h);
	void eliminar(Disparo* e);
private:

	std::vector<Disparo*>lista;
	int numero;
	//Disparo* lista[NUM_MAX_DISPAROS];
	//int numero;
	
};