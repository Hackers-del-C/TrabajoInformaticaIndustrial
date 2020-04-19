#pragma once
#include "Menu.h"
#include "ETSIDI.h"

using namespace ETSIDI;
using ETSIDI::getTexture;
using ETSIDI::playMusica;
using ETSIDI::play;

class Fondo {
private:

public:
	Menu menu;
	void Escenario(int nivel);
	void Titulo(int nivel);
	void Musica(int nivel);//No funciona

};