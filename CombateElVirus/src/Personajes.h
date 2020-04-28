#pragma once
#include "ETSIDI.h"
#include "Virus.h"
#include "Hombre.h"
#include "Amigo.h"
class Personajes {
public:
	Personajes();
	virtual ~Personajes();
	void Inicializa(float ax, float vx);
	void Dibuja(int nivel,float posx,float posy, int dir);
	void Mueve(float t);
	void Tecla(unsigned char key);
	void TeclaEspecial(unsigned char key);
private:
	Virus virus; 
	Hombre hombre;
	Amigo amigo;
};