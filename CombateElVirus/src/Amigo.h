#pragma once

#include "ETSIDI.h"
#include "Hombre.h"
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
private:
	int izqder;
	ETSIDI::Vector2D posicion, velocidad,aceleracion;
};
