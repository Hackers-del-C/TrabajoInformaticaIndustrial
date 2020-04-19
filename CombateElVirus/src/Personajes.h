#pragma once
#include "ETSIDI.h"

#include "Jugador.h"
class Personajes {
public:
	Personajes();
	virtual ~Personajes();
	void Inicializa();
	void Dibuja(int level);
	void Mueve(int level);
	void Tecla(unsigned char key);
	void TeclaEspecial(unsigned char key);
private:
	Jugador jugador;
};