#pragma once

#include "ETSIDI.h"

class Amigo {
public:
	ETSIDI::SpriteSequence* companionder;
	ETSIDI::SpriteSequence* companionizq;
	void Dibuja(float posx, float posy, int dir);
	void Inicializa();
	void SetVel(float vx); //, float vy
	void Mueve(float t);
	void SetAceleracion(float ax) { //, float ay
		aceleracion.x = ax;
		//aceleracion.y = ay;
	}
private:
	ETSIDI::Vector2D posicion, velocidad,aceleracion;
};
