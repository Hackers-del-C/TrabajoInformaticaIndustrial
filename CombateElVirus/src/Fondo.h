#pragma once
#include "ETSIDI.h"
using namespace ETSIDI;
using ETSIDI::getTexture;
using ETSIDI::playMusica;
using ETSIDI::play;

class Fondo {
private:

public:
	void Escenario(int nivel);
	void Titulo(int nivel);
	void Musica(int nivel);//No funciona
};