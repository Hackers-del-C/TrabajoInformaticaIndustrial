#pragma once

#define MAX_EXP 100
#include "Explosiones.h"


class ListaExplosiones {

public:
	ListaExplosiones();
	~ListaExplosiones();
	bool agregar(Explosiones* v);
	void dibuja();
	void mueve(float t);
	//void rebote(Limites caja);
	//void rebote(Pared p);
	//void rebote();
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Explosiones* e);

	Explosiones* operator [](int i);
	int getNumero() { return numero; }

private:
	Explosiones* lista[MAX_EXP];
	int numero;

};