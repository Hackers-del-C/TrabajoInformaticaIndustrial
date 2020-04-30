#pragma once
#include "Hombre.h"
#include "ETSIDI.h"

 
using namespace ETSIDI;
class Vidas {
	ETSIDI::Vector2D posicion;
public:
	void Dibuja(int vidas);
	void Inicializa(Hombre h);
	void Mueve(float x_ojo, Hombre h);

	ETSIDI::Sprite* vida1;
	ETSIDI::Sprite* vida2;
	ETSIDI::Sprite* vida3;
	ETSIDI::Sprite* vida4;
	ETSIDI::Sprite* vida5;
	
};