#pragma once


#define MAX_SLIME 100
#include "Hombre.h"
#include "Slime.h"
#include "ListaPlatafomas.h"
#include "Limites.h"
//#include "Interaccion.h"
//#include "Limites.h"

class ListaSlime {

public:
	ListaSlime();
	virtual ~ListaSlime();
	bool agregar(Slime* v);
	void dibuja();
	void mueve(float t, Hombre h);
	//void rebote(Limites caja);
	//void rebote(Pared p);
	//void rebote();
	void Colision(Hombre &h);
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Slime* e);
	void Colision(ListaPlataformas p);
	void Colision(Limites l);
	//Virus* colision(Hombre& h);
	Slime* operator [](int i);
	int getNumero() { return numero; }

	//Slime* Colision(Hombre& h);
private:
	Slime* lista[MAX_SLIME];
	int numero;

};