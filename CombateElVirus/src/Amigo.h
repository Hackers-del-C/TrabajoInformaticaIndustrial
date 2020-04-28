#pragma once

#include "ETSIDI.h"

class Amigo {
public:
	ETSIDI::SpriteSequence* companionder;
	ETSIDI::SpriteSequence* companionizq;
	void Dibuja(float posx, float posy, int dir);
	void Inicializa();
	void SetVel(float vx, float vy);
	void Mueve();
private:
	ETSIDI::Vector2D posicion, velocidad;
};
