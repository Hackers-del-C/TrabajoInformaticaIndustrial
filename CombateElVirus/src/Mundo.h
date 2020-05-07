#pragma once
#include "ETSIDI.h"

#include "Limites.h"
#include "Personajes.h"
#include "Hombre.h"
#include "Entorno.h"
#include "ListaLanzamisiles.h"
#include "Virus.h"
#include "Vidas.h"
//LISTAS
#include "ListaPlatafomas.h"
#include "ListaVirus.h"
#include "ListaBordesSube.h"
#include "ListaDisparos.h"
#include "Listamisiles.h"
#include "ListaBonusMascarilla.h"
#include "ListaBonusTest.h"

//borrar en un futuro:
#include "VirusSeta.h"
#include "Zapatos.h"
//#include "BonusMascarilla.h"

class Mundo
{

public: 
	int level;//SE CAMBIA DESDE MENU.H 
	
	int mascarillas = 5;
	//generales
	Mundo();
	void Tecla(unsigned char key);
	void Inicializa();
	void fichero();
	void Mueve();
	void Dibuja();
	void teclaEspecial(unsigned char key);
	void MyMouse(int button, int state, int x, int y);
	//ojo:

	void Setojo(float ox, float oy, float oz);
	void SetLevel(int nivel) { level = nivel; }	

		//void RotarOjo();

private:
	// constantes para el salto
	int distancia=0;
	int salto =0;
	int pantalla=0;//aux
	//
	//Disparo disparo;
	Personajes personajes;
	Hombre hombre;
	Limites limites;//plataforma1;
	//Virus virus;
	
	VirusSeta virus1;
	Entorno entorno;
	//LISTAS
	ListaDisparos disparos;
	ListaLanzamisiles listalanzamisiles;
	ListaMisil misiles;	
	Vidas vidas;
	Plataformas plataformaprueba;
	ListaPlataformas plataformas;
	ListaBordesSube bordessube;
	ListaVirus listavirus;
	ListaBonusMascarilla listabonusmascarilla;
	ListaBonusTest listabonustest;
	Zapatos zapatos;
	//BonusMascarilla bonus1;
	//Bonus bonus;
	// Misil misilizq;
	//Pared plataforma;
	//ojo
	float x_ojo;
	float y_ojo;
	float z_ojo;

};
