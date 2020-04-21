#pragma once
#include "ETSIDI.h"
using namespace ETSIDI;

class Lanzamisiles {
public:
	ETSIDI::Vector2D posicion;
	Lanzamisiles();
	Lanzamisiles(ETSIDI::Vector2D pos);
	~Lanzamisiles();

	void Dibuja();
	void Inicializa();
	Sprite* lanzamisiles1;
};