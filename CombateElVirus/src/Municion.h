#pragma once
#include"Bonus.h"

class Municion :public Bonus {

public:
	Municion();
	virtual ~Municion();
	Municion(int x, int y, int w, int h);
	Municion(int x, int y, int vy,  int w, int h);
	void Mueve(float t);
	bool colision(Hombre& h);

};
