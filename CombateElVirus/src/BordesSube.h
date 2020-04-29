#pragma once
#include "ETSIDI.h"

class BordesSube {
private:
	//ETSIDI::Vector2D posicion; //solo y
	//float x1, x2;
	ETSIDI::Vector2D limite1, limite2;
public:
	BordesSube(float x1, float y1, float x2, float y2);
	BordesSube(float x1, float x2);
	BordesSube(ETSIDI::Vector2D l1, ETSIDI::Vector2D l2);
	void Dibuja();
	float distancia(ETSIDI::Vector2D punto, ETSIDI::Vector2D* direccion);
};