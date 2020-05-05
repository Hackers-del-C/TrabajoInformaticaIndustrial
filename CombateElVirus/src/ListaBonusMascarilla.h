#pragma once
#include "BonusMascarilla.h"
#define BONUS 100
#include "Hombre.h"
#include "Limites.h"
#include "Plataformas.h"
//#include "Interaccion.h"
//#include "Limites.h"

class ListaBonusMascarilla {

public:
	ListaBonusMascarilla();
	virtual ~ListaBonusMascarilla();
	bool agregar(BonusMascarilla* v);
	void dibuja();
	void mueve(float t);

	void destruirContenido();
	void eliminar(int index);
	void eliminar(BonusMascarilla* e);
	//Virus* colision(Hombre& h);
	BonusMascarilla* operator [](int i);
	int getNumero() { return numero; }

	void colision(Hombre& h);
	void Colision(Limites l);
	void Colision(Plataformas p);
private:
	BonusMascarilla* lista[BONUS];
	int numero;

};