#pragma once
#include "ETSIDI.h"
#include "Virus.h"
#include "Hombre.h"
#include "Amigo.h"
class Personajes {
public:
	Personajes();
	virtual ~Personajes();
	void Inicializa(Hombre h);
	void Dibuja(int nivel,Hombre h);
	void Mueve(float t);
	void Tecla(unsigned char key);
	void TeclaEspecial(unsigned char key);
	
private:
	Virus virus; 
	Hombre hombre;
	Amigo amigo;
};