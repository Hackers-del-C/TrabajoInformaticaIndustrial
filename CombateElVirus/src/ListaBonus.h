#pragma once
#include "Bonus.h"
#define BONUS 100
#include "Hombre.h"
#include "Limites.h"
#include "Plataformas.h"
//#include "Interaccion.h"
//#include "Limites.h"

class ListaBonus {

public:
	ListaBonus();
	virtual ~ListaBonus();
	bool agregar(Bonus* b);
	void dibuja();
	void mueve(float t);
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Bonus* e);
	//Virus* colision(Hombre& h);
	Bonus* operator [](int i);
	int getNumero() { return numero; }

	void colision(Hombre& h);

	void Colision(Limites l);
	void Colision(Plataformas p);
	
	friend class VirusMosca;

protected:
	Bonus* lista[BONUS];
	int numero;

};




