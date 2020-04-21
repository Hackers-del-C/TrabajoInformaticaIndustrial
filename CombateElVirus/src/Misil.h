#pragma once
#pragma once
#include "ETSIDI.h"
using namespace ETSIDI;
class Misil {

public:
	ETSIDI::Vector2D posicion;
	ETSIDI::Vector2D velocidad;

	/*Misil();
	~Misil();*/
	void Inicializader();
	void Inicializaizq();
	void Dibujader();
	void Dibujaizq();
	void Mueveder(float t);
	void Mueveizq(float t);
	void SetVel(float v);
	Sprite* misilder;

	Sprite* misilizq;
};