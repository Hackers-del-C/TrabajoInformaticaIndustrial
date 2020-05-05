
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
	BonusMascarilla(string nombre, int x, int y, int w, int h);
	void Inicializa(string nombre, int x, int y, int w, int h);

};