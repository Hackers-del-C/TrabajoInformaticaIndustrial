#pragma once
//#include <vector>
#define NUM_MAX_DISPAROS 20
#include "Disparo.h"
#include "Virus.h"
#include "Explosiones.h"
#include "ListaExplosiones.h"

class ListaDisparos {

public:
	ListaDisparos();
	~ListaDisparos();

	bool Agregar(Disparo* d);
	void DestruirContenido();
	void Mueve(float t);
	void Dibuja();
	int getNumero() { return numero; }
	Disparo* operator [](int i);
	void eliminar(int index);
	void eliminar(Disparo* e);
	bool Colision(Virus& h, ListaExplosiones &l);
	
private:
	Disparo* lista[NUM_MAX_DISPAROS];
	//std::vector<Disparo*>lista;
	int numero;
	
	
};