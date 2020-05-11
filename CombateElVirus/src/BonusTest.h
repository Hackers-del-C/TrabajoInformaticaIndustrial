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
	BonusTest(int x, int y, int w, int h);
	void Inicializa( int x, int y, int w, int h);

};