#pragma once
#include "ETSIDI.h"
using namespace ETSIDI;

class Lanzamisiles {
public:
	ETSIDI::Vector2D posicion;
	Lanzamisiles(char nombre[20], float x, float y);
	Lanzamisiles(ETSIDI::Vector2D pos);
	~Lanzamisiles();

	void Dibuja();
	void Inicializa();
	Sprite* lanzamisiles;
};