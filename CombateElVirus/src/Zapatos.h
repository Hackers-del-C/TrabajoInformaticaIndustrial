#pragma once
#include "Hombre.h"
#include"ETSIDI.h"
class Zapatos {
	float radio=0.25;
	ETSIDI::Vector2D posicion;
public:
	Zapatos();
	~Zapatos();
	ETSIDI::Vector2D GetPos() {
		return posicion;
	}
	void Inicializa(Hombre& h);
	void Dibuja(Hombre& h);
	float GetRadio() { return radio; }
	void SetPos(float x, float y) {
		posicion.x = x;
		posicion.y = y;
	}
	//void Mueve(float t, Hombre &h);
};
