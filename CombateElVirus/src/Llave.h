#pragma once
#include "Bonus.h"

class Llave :public Bonus {

public:
	Llave();
	~Llave();
	Llave(int x, int y, int w, int h);
	//void Inicializa(int x, int y, int w, int h);
	void Mueve(float t);
	bool colision(Hombre& h);
};