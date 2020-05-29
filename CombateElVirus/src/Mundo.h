#pragma once
#include "ETSIDI.h"
#include"AuxEtsidi.h"
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
#include "Billete.h"
//LISTAS
#include "ListaPlatafomas.h"
#include "ListaVirus.h"
#include "ListaDisparos.h"
#include "Listamisiles.h"
#include "ListaBonus.h"


#include "VirusSeta.h"
#include "VirusBaba.h"
#include "VirusMosca.h"
#include "Slime.h"
#include "ListaSlime.h"
#include "VirusSlime.h"
#include "ListaExplosiones.h"
#include "Explosiones.h"
#include "DisparoEspecial.h"
#include"Municion.h"




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
	int Muerte();
	int Ganar();
	void SetFinalLevel(int f) { finaldenivel = 1; }
	long gettiempo() { return tiempo; }
	
	//ojo:

	void Setojo(float ox, float oy, float oz);
	void RecargarNivel(int level);
	//void Interaccion();
		//void RotarOjo();
	ETSIDI::Vector2D GetHombrePos();

private:
	// constantes para el salto
	int finaldenivel;
	int distancia=0;
	int salto =0;
	long tiempo = -1000;//
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
	ListaSlime listaslime2;
	ListaSlime disparobaba;
	ListaVirus listavirus;
	ListaBonus listabonus;

	ListaExplosiones listaexplosiones;
	Explosiones exptest;
	AuxEtsidi auxetsidim;
	
	//ojo
	float x_ojo;
	float y_ojo;
	float z_ojo;
	ETSIDI::Sprite* avion;
};
