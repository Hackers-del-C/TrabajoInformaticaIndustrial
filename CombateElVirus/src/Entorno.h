#pragma once
#include "ETSIDI.h"
#include "AuxEtsidi.h"


using namespace ETSIDI;
using ETSIDI::playMusica;
using ETSIDI::play;
class Entorno {
public:
	
	void Inicializa(int nivel);
	void Dibuja(int nivel);
	void Tecla(unsigned char key);
	//friend class Mundo;
	
private:
	AuxEtsidi auxetsidi;

	
};