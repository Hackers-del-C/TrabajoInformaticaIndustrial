#pragma once
#include "ETSIDI.h"
#include "AuxEtsidi.h"


using namespace ETSIDI;
using ETSIDI::playMusica;
using ETSIDI::play;
class Entorno {
public:
	
	void Inicializa(int nivel);
	void Dibuja(int nivel,int xraton, int yraton);
	void Fin(int pantalla);
	void Aviso(int pantalla, int x, int y,int xraton, int yraton);
	void Tecla(unsigned char key);
	//friend class Mundo;
	
private:
	AuxEtsidi auxetsidi;
	int gl1 = 0; //color letras menu
	int gl2 = 0;
	int gl3 = 0;

};