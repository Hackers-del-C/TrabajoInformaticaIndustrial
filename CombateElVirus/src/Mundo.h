#pragma once
#include "ETSIDI.h"
#include"time.h"

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
#include "VirusMosca.h"
#include "Slime.h"
#include "ListaSlime.h"
#include "VirusSlime.h"
#include "ListaExplosiones.h"
#include "Explosiones.h"

enum { MOUSE_LEFT_BUTTON, MOUSE_MIDDLE_BUTTON, MOUSE_RIGHT_BUTTON };

class Mundo
{

public: 
	int level;//SE CAMBIA DESDE MENU.H 
	
	int mascarillas = 5;
	//generales
	Mundo();
	int Tecla(unsigned char key);
	void Inicializa();
	void InicializaFondo();
	void fichero();
	void Mueve();
	void Dibuja();
	void teclaEspecial(unsigned char key);
	void teclaEspecialsuelta(unsigned char key);
	int ClickMouse(int b, int state,int x, int y);
	
	void CargarNivel();
	//ojo:

	void Setojo(float ox, float oy, float oz);
	void SetLevel(int nivel) { level = nivel; }	
	//void Interaccion();
		//void RotarOjo();

private:
	// constantes para el salto
	int distancia=0;
	int salto =0;
	int pantalla=0;//aux
	long tiempo;//
	//Disparo disparo;
	Personajes personajes;
	Hombre hombre;
	Limites limites;//plataforma1;
	//Virus virus;
	
	VirusSeta virus1;
	VirusBaba virus2;
	VirusMosca virus3;
	VirusSlime virus4;
	//Slime slime;
	Entorno entorno;
	//LISTAS
	ListaDisparos disparos;
	ListaLanzamisiles listalanzamisiles;
	ListaMisil misiles;	
	Vidas vidas;
	Plataformas plataformaprueba;
	ListaPlataformas plataformas;
	ListaSlime listaslime;
	ListaBordesSube bordessube;
	ListaVirus listavirus;
	ListaBonusMascarilla listabonusmascarilla;
	ListaBonusTest listabonustest;
	ListaExplosiones listaexplosiones;
	Explosiones exptest;
	
	//ojo
	float x_ojo;
	float y_ojo;
	float z_ojo;

};
