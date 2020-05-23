
#include "Bonus.h"
#include "ETSIDI.h"
#include <iostream>
#pragma once
#include <fstream>
#include <sstream>
#include <string>
using namespace ETSIDI;


class BonusMascarilla : public Bonus {

public:
	BonusMascarilla();
	~BonusMascarilla();
	BonusMascarilla( int x, int y, int w, int h);
	BonusMascarilla(int x, int y, int vx, int w, int h);
	void Inicializa( int x, int y, int w, int h);
	void Mueve(float t);
	bool colision(Hombre& h);
};