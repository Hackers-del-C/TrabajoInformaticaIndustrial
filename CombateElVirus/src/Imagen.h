#pragma once
#include "Menu.h"
#include "ETSIDI.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace ETSIDI;
using ETSIDI::getTexture;
using ETSIDI::playMusica;
using ETSIDI::play;

class Imagen {
private:

public:

	void Dibuja(string nombre, float limx1, float limx2, float limy1, float limy2);
	Sprite* templo;
};