#pragma once
#include "ETSIDI.h"
#include "BordesSube.h"
class Plataformas {
public:
	Plataformas();
	Plataformas(float x1, float y1, float x2, float y2);
	//~Plataformas();
	void Dibuja();
	void SetPos(ETSIDI::Vector2D l1,ETSIDI::Vector2D l2) {
		limite1 = l1;
		limite2 = l2;
	}
	void Inicializa(float x, float y, float w, float h);
	float aux;
	float distancia(ETSIDI::Vector2D punto, ETSIDI::Vector2D* direccion);
	ETSIDI::Vector2D posicion;
	float anchura, altura;
private:
	ETSIDI::Vector2D limite1, limite2;
};