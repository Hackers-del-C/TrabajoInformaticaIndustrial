#pragma once
#include"Bonus.h"
#include "ETSIDI.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace ETSIDI;


class BonusTest : public Bonus {

public:
	BonusTest();
	~BonusTest() {};
	BonusTest(string nombre, int x, int y, int w, int h);
	void Inicializa(string nombre, int x, int y, int w, int h);

};