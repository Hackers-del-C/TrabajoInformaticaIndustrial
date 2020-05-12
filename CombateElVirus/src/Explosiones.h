#pragma once
#include "ETSIDI.h"

class Explosiones {

public:
	Explosiones();
	~Explosiones();
	Explosiones(float x, float y);
	void Mueve(float t);
	void Dibuja();
	void Inicializa(float x, float y);
	ETSIDI::SpriteSequence* sprite;
	ETSIDI::Vector2D posicion;
};