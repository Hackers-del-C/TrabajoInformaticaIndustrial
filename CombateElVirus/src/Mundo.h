#pragma once

#include "Limites.h"
#include "Personajes.h"
#include "Hombre.h"
#include "Bonus.h"
#include "Disparo.h" 
#include "ListaDisparos.h"
#include "ETSIDI.h"
#include "Entorno.h"
#include "Lanzamisiles.h"
#include "Misil.h"
class Mundo
{

public: 
	int level;

	//generales
	Mundo();
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
	// constantes para el salto

	int distancia=0;
	int salto = 1;
	//
	Disparo disparo;
	Personajes personajes;
	Hombre hombre;
	Limites limites, plataforma1;
	Menu menu;
	
	Bonus bonus;
	Pared plataforma;
	Entorno entorno;
	ListaDisparos disparos;
	Lanzamisiles lanzamisiles1;
	Misil misilder;
	Misil misilizq;

	//ojo
	float x_ojo;
	float y_ojo;
	float z_ojo;

};
