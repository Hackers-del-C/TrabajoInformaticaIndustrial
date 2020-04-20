#pragma once

#include "Limites.h"
#include "Hombre.h"
#include "Bonus.h"
#include "Disparo.h" 
#include "ListaDisparos.h"
#include "ETSIDI.h"
#include "Entorno.h"

class Mundo
{

public: 
	int level = 1; 

	//generales
	void Tecla(unsigned char key);
	void Inicializa();
	void Mueve();
	void Dibuja();
	void teclaEspecial(unsigned char key);
	//ojo:
	void RotarOjo();
	void Setojo(float ox, float oy, float oz);
	void SetLevel(int nivel) { level = nivel; }

private:

	
	Disparo disparo;
	Hombre hombre;
	Limites limites, plataforma1;
	
	Bonus bonus;
	Pared plataforma;
	Entorno entorno;
	ListaDisparos disparos;
	//ojo
	float x_ojo;
	float y_ojo;
	float z_ojo;

};
