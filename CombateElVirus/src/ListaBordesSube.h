#pragma once
#include "BordesSube.h"
//#include "Interaccion.h"
#include "Hombre.h"
//#include <vector>
#define NUM_MAX_PLATAFORMAS 100

class ListaBordesSube {

public:
	ListaBordesSube();
   ~ListaBordesSube();
	bool Agregar(BordesSube* b);
	void DestruirContenido(int ind);
	void Dibuja();
	int GetNumero() { return numero; }
	void Eliminar(int index);
	void Eliminar(BordesSube* b);
	// bool Colision(Hombre h);

private:
	int numero;
	BordesSube* lista[NUM_MAX_PLATAFORMAS];

	//std::vector<Plataformas*>lista;

	//Disparo* lista[NUM_MAX_DISPAROS];
	//int numero;

};