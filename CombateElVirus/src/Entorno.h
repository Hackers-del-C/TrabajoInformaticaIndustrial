#pragma once
#include "ETSIDI.h"
#include "AuxEtsidi.h"


using namespace ETSIDI;
using ETSIDI::playMusica;
using ETSIDI::play;
class Entorno {
public:
	
	void Musica(int nivel);
	void DibujaMenu(int xraton, int yraton);
	void DibujaJuego(int nivel);
	void Fin(int pantalla);
	void Aviso(int pantalla, int x, int y);
	
	
private:
	AuxEtsidi auxetsidi;
	int gl1 = 0; //color letras menu
	int gl2 = 0;
	int gl3 = 0;
	int rd1 = 1;// color avisos 
	int rd2 = 1;
};