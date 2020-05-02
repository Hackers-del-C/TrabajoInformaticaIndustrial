#pragma once
#include "ETSIDI.h"
using namespace ETSIDI;
using ETSIDI::getTexture;
class Menu {
public:
	Menu();
	int level;
	//void Dibuja();
	void Tecla(unsigned char key);
	void Texto();

	int GetLevel() {return level;};

	//friend class Backgroud;
};