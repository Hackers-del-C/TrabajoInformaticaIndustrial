#pragma once
#pragma once
#include "ETSIDI.h"
//#include "Vector2D.h"
using namespace ETSIDI;
class Misil {
	int explota = 0;
public:
	ETSIDI::Vector2D posicion;
	ETSIDI::Vector2D velocidad;
	float anchura = 2;
	float altura = 2;
	

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
	//void Explota() { explota = 1; }
	Sprite* misil;
	ETSIDI::SpriteSequence* misilexplota;
};