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

//borrar en un futuro: WHYYYY???
#include "VirusSeta.h"
#include "VirusBaba.h"

enum { MOUSE_LEFT_BUTTON, MOUSE_MIDDLE_BUTTON, MOUSE_RIGHT_BUTTON };

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
	void ClickMouse(int b, int state, int x, int y);
	void MyMouse(int x, int y);
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
	VirusBaba virus2;
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
	//mouse	
	int xmouse, ymouse;			//
	float width = 0.15; //borrar 100% en un futuro
	//mouse+special-keys combination state events 

	bool leftButton;
	bool rightButton;
	bool midButton;
	 //para el mouse:
	void world2cell(double x, double y, int& cell_x, int& cell_y) {
		//world coordinates to cell
		cell_x = (int)(abs(y / width));
		cell_y = (int)(x / width);
	}
	//ojo
	float x_ojo;
	float y_ojo;
	float z_ojo;

};
