#pragma once

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
	int GetNumero() { return numero; }
	/*void Explota();*/
	void Eliminar(Misil* m);
	void limpiar();
	void Eliminar(int index);
	
	Misil* colision(Hombre& h);
private:
	int numero;
	//Disparo* lista[NUM_MAX_misiles];
	 Misil*lista[NUM_MAX_misiles];
	//Disparo* lista[NUM_MAX_DISPAROS];
	//int numero;

};