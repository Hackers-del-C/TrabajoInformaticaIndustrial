#include "Esfera.h"
#include "Caja.h"
#include "Hombre.h"
#include "Esfera.h"
#include "Bonus.h"
#include "Disparo.h" 
#pragma once
class Mundo
{
public: 
	void Tecla(unsigned char key);
	void Inicializa();
	void RotarOjo();
	void Mueve();
	void Dibuja();

	float x_ojo;
	float y_ojo;
	float z_ojo;
	Disparo disparo;
	Esfera esfera;
	Hombre hombre;
	Caja caja;
	Bonus bonus;
	Pared plataforma;
};
