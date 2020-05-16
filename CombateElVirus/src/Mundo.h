#pragma once
#include "ETSIDI.h"
#include"time.h"

#include "Limites.h"
#include "Personajes.h"
#include "Hombre.h"
#include "ListaLanzamisiles.h"
#include "Virus.h"
#include "Vidas.h"
#include "Bonus.h"
#include "BonusTest.h"
#include "BonusMascarilla.h"

//LISTAS
#include "ListaPlatafomas.h"
#include "ListaVirus.h"
#include "ListaDisparos.h"
#include "Listamisiles.h"
#include "ListaBonus.h"

//borrar en un futuro: WHYYYY???
#include "VirusSeta.h"
#include "VirusBaba.h"
#include "VirusMosca.h"
#include "Slime.h"
#include "ListaSlime.h"
#include "VirusSlime.h"
#include "ListaExplosiones.h"
#include "Explosiones.h"
#include "DisparoEspecial.h"

class Mundo
{

public: 
	
	
	int mascarillas = 5;
	//generales
	Mundo();
	void Tecla(unsigned char key);
	void Inicializa(int level);
	void InicializaFondo(int nivel);
	void fichero(int level);
	void Mueve(int level);
	void MueveHombre();
	void Dibuja(int level);
	void DibujaBasico();
	void InicioDibuja();
	void teclaEspecial(unsigned char key);
	void teclaEspecialsuelta(unsigned char key);
	int Muerte();
	int Ganar();
	
	//ojo:

	void Setojo(float ox, float oy, float oz);
	void RecargarNivel(int level);
	//void Interaccion();
		//void RotarOjo();
	ETSIDI::Vector2D GetHombrePos();

private:
	// constantes para el salto
	int distancia=0;
	int salto =0;
	long tiempo;//
	Disparo disparo;
	Personajes personajes;
	Hombre hombre;
	Limites limites;//plataforma1;
	Virus virus;
	
	//VirusSeta virus1;
	VirusBaba virus2;
	//VirusMosca virus3;
	//VirusSlime virus4;
	Slime slime;
	//LISTAS
	ListaDisparos disparos;
	ListaLanzamisiles listalanzamisiles;
	ListaMisil misiles;	
	Vidas vidas;
	Plataformas plataformaprueba;
	ListaPlataformas plataformas;
	ListaSlime listaslime;
	ListaVirus listavirus;
	ListaBonus listabonus;

	ListaExplosiones listaexplosiones;
	Explosiones exptest;
	
	//ojo
	float x_ojo;
	float y_ojo;
	float z_ojo;

};
