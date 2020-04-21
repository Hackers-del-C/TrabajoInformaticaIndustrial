#pragma once
#include "ETSIDI.h"
using namespace ETSIDI;
using ETSIDI::getTexture;
class Menu {
public:

	int level=0;


	//Menu() :level(0) {};

	void Dibuja();
	void Tecla(unsigned char key);
	void Texto();

	int GetLevel() { return level; }

	//friend class Backgroud;
};