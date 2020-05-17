
#pragma once
#include"Bonus.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include"Interaccion.h"

class Billete : public Bonus {

public:

	Billete();
	virtual ~Billete();
	Billete(int x, int y, int w, int h);
	void mueve(float t);
	bool colision(Hombre& h);
	



};

