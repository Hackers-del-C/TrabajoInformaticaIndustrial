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
#include "Virus.h"
#include "Listamisiles.h"
#include "Vidas.h"
#include "ListaPlatafomas.h"
#include "Plataformas.h"
#include "ListaVirus.h"
#include "ListaBordesSube.h"
#include "Zapatos.h"
//#include "Misil.h"
class Mundo
{

public: 
	int level;//SE CAMBIA DESDE MENU.H 
	int mascarillas = 5;
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
	int salto =0;
	//
	Disparo disparo;
	Personajes personajes;
	Hombre hombre;
	Limites limites, plataforma1;
	Virus virus;
	Bonus bonus;
	Pared plataforma;
	Entorno entorno;
	ListaDisparos disparos;
	Lanzamisiles lanzamisiles1;
	ListaMisil misiles;
	
	Vidas vidas;
	ListaPlataformas plataformas;
	ListaBordesSube bordessube;
	//Misil misilizq;
	ListaVirus listavirus;
	Zapatos zapatos;
	//ojo
	float x_ojo;
	float y_ojo;
	float z_ojo;

};
