#pragma once
#include "Hombre.h"
#include "ETSIDI.h"
#include"AuxEtsidi.h"
 
using namespace ETSIDI;
class Vidas {
	ETSIDI::Vector2D posicion;
public:
	void Dibuja(Hombre& h, int vidas);
	void Inicializa(Hombre h);
	void Mueve(float xojo);

	ETSIDI::Sprite* vida1;
	ETSIDI::Sprite* vida2;
	ETSIDI::Sprite* vida3;
	ETSIDI::Sprite* vida4;
	ETSIDI::Sprite* vida5;
	ETSIDI::Sprite* monedas;
	AuxEtsidi auxetsidi;
};