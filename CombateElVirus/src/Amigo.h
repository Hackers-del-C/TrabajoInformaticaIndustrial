#pragma once

#include "ETSIDI.h"
#include "Hombre.h"
#include "AuxEtsidi.h"
using namespace ETSIDI;
using ETSIDI::getTexture;
class Amigo {
public:
	ETSIDI::SpriteSequence* companionder;
	ETSIDI::SpriteSequence* companionizq;
	ETSIDI::SpriteSequence* companion;

	void Dibuja(Hombre h);
	void Inicializa();
	void SetVel(float vx); //, float vy
	void Mueve(float t);
	void SetAceleracion(float ax) { //, float ay
		aceleracion.x = ax;
		//aceleracion.y = ay;
	}
	void Mensajes(int level);
private:
	int izqder;
	AuxEtsidi auxetsidi;
	ETSIDI::Vector2D posicion, velocidad,aceleracion;
};
