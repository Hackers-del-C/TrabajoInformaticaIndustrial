#pragma once
#include "Virus.h"
#define MAX_VIRUS 100
#include "Hombre.h"
//#include "Interaccion.h"
//#include "Limites.h"

class ListaVirus {

public:
	ListaVirus();
	virtual ~ListaVirus();
	bool agregar(Virus* v);
	void dibuja();
	void mueve(float t, Hombre h);
	//void rebote(Limites caja);
	//void rebote(Pared p);
	//void rebote();
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Virus* e);
	//Virus* colision(Hombre& h);
	Virus* operator [](int i);
	int getNumero() { return numero; }

private:
	Virus* lista[MAX_VIRUS];
	int numero;

};