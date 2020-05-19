#pragma once

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
	void Inicializa();
	/*void Explota();*/
	void Eliminar(Lanzamisiles* m);
	void Eliminar(int index);
	int GetNumero() { return numero; }

private:
	int numero;
	Lanzamisiles*lista [NUM_MAX_lanzamisiles];
	//int numero;
	//Lanzamisiles* lista[NUM_MAX_lanzamisiles];
	//Disparo* lista[NUM_MAX_DISPAROS];
	//int numero;

};