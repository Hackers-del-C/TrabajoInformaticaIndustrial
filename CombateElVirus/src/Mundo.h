#pragma once
#include "Esfera.h"
#include "Caja.h"
#include "Hombre.h"
#include "Esfera.h"
#include "Bonus.h"
#include "Disparo.h" 
#include "ListaDisparos.h"
#include "ETSIDI.h"
#include "Entorno.h"

class Mundo
{
public: 
	//generales
	void Tecla(unsigned char key);
	void Inicializa();
	void Mueve();
	void Dibuja();
	void teclaEspecial(unsigned char key);
	//ojo:
	void RotarOjo();
	void Setojo(float ox, float oy, float oz);

private:

	
	Disparo disparo;
	Esfera esfera, esfera2;
	Hombre hombre;
	Caja caja, plataforma1;
	
	Bonus bonus;
	Pared plataforma;
	Entorno entorno;
	ListaDisparos disparos;
	//ojo
	float x_ojo;
	float y_ojo;
	float z_ojo;

};
