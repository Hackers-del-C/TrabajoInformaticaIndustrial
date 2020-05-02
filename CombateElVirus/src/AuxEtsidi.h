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

class AuxEtsidi {
private:

public:

	void Imagen(string nombre, float limx1, float limx2, float limy1, float limy2);
	void Texto(string nombre, float x, float y, float red, float verde, float azul, float tamanio);
	

};