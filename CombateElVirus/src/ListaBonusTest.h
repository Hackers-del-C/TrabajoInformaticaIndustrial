#pragma once
#include "BonusTest.h"
#define BONUSTEST 20
#include "Hombre.h"
#include "Limites.h"
#include "Plataformas.h"
//#include "Interaccion.h"
//#include "Limites.h"

class ListaBonusTest {

public:
	ListaBonusTest();
	virtual ~ListaBonusTest();
	bool agregar(BonusTest* v);
	void dibuja();

	void destruirContenido();
	void eliminar(int index);
	void eliminar(BonusTest* e);
	//Virus* colision(Hombre& h);
	BonusTest* operator [](int i);
	int getNumero() { return numero; }

	void colision(Hombre& h);


private:
	BonusTest* lista[BONUSTEST];
	int numero;

};