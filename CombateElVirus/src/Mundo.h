#pragma once
#include "Esfera.h"
#include "Caja.h"
#include "Hombre.h"
#include "Esfera.h"
#include "Bonus.h"
#include "Disparo.h" 
#include "ListaDisparos.h"
#include "ETSIDI.h"
#include "Background.h"

class Mundo
{
public: 
	void Tecla(unsigned char key);
	void Inicializa();
	void RotarOjo();
	void Mueve();
	void Dibuja();
	void teclaEspecial(unsigned char key);
	void Setojo(float ox, float oy, float oz);

private:
	float x_ojo;
	float y_ojo;
	float z_ojo;
	Disparo disparo;
	Esfera esfera, esfera2;
	Hombre hombre;
	Caja caja;
	Bonus bonus;
	Pared plataforma;
	Background background;
	ListaDisparos disparos;
};
