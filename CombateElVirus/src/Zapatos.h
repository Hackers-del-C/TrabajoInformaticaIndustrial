#pragma once
#include "Hombre.h"
#include"ETSIDI.h"
class Zapatos {
	float radio=0.09;
	ETSIDI::Vector2D posicion;
public:
	Zapatos();
	~Zapatos();
	ETSIDI::Vector2D GetPos() {
		return posicion;
	}
	void Inicializa(Hombre& h);
	void Dibuja(Hombre& h);
	
	//void Mueve(float t, Hombre &h);
};
