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
	float anchura = 0.5;
	float altura = 0.5;
	

	Misil();

	Misil(char nombre[20], float x,float y,float vx,float vy);
	//~Misil();*/

	void Dibuja();
	void Mueve(float t);
	void SetVel(float v);
	//void Explota() { explota = 1; }
	Sprite* misil;
	ETSIDI::SpriteSequence* misilexplota;
};