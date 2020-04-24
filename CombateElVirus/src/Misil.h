#pragma once
#pragma once
#include "ETSIDI.h"
using namespace ETSIDI;
class Misil {

public:
	ETSIDI::Vector2D posicion;
	ETSIDI::Vector2D velocidad;
	Misil();
	Misil(char nombre[20], float x,float y,float vx,float vy);
	//~Misil();*/
	//void Inicializader();

	void Inicializa();
	//void Dibujader();
	void Dibuja();
	//void Mueveder(float t);
	void Mueve(float t);
	void SetVel(float v);
	Sprite* misilder;
	Sprite* misil;
	Sprite* misilizq;
};