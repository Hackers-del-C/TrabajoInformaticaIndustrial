#pragma once
#include <Windows.h>
#include <stdio.h>
#include "Mundo.h"
#include "Interaccion.h"
#include "ListaDisparos.h"
#include "ListaExplosiones.h"
#include "ListaBonus.h"
#include <math.h>
#include "glut.h"
#include <fstream>
#include<sstream>
#include<iostream>

#define NUM_MAX_RANKING 100


Mundo::Mundo(){
	
}
void Mundo::Setojo(float ox, float oy, float oz) { 	//Set del del ojo. Separado para llamarle comodamente desde el coordinador

	x_ojo = ox;
	y_ojo = oy;
	z_ojo = oz;

}
void Mundo::InicioDibuja() { //para que funcione bien los dibujas llamados desde el coordinador, tiene que estar primero el ojo
	/*Se ha decido dejar el ojo en Mundo.cpp porque va conectado con la posicion del hombre en la gran mayoría del tiempo*/
	gluLookAt(x_ojo, y_ojo, z_ojo,
		x_ojo, y_ojo, 0.0, //NOTESE QUE HEMOS CAMBIADO ESTO
		0.0, 5.0, 0.0); //PARA MIRAR AL CENTRO DE LA ESCENA

}
void Mundo::fichero(int level) { //	Fichero para guardar el numero de tests y el tiempo tardado
	ifstream fichero("resultado_final.txt");
	int k = 0;

	struct jugador {
		string nombre, texto1, texto2, texto3, texto4, texto5;
		int nivel = 0, test = 0, segundos = 0, posicion = 0;
	};
	jugador lista[NUM_MAX_RANKING];
	while (!fichero.eof()) {

		fichero >> lista[k].posicion >> lista[k].nombre;
		fichero >> lista[k].texto1 >> lista[k].nivel;
		fichero >> lista[k].texto2 >> lista[k].test >> lista[k].texto3;
		fichero >> lista[k].texto4 >> lista[k].segundos >> lista[k].texto5;
		k++;
	}

	lista[k].nombre = "david";
	lista[k].nivel = level;
	lista[k].test = hombre.GetMonedas();
	lista[k++].segundos = ((clock() - tiempo) / 1000);

	fichero.close();
	remove("resultado_final.txt");
	ofstream fichero1("resultado_final.txt");
	fichero.open("resultado_final.txt");

	//ordenar por puntuacion

	for (int m = 0; m < (k - 1); m++) {

		for (int n = 0; n < (k - 1); n++) {

			jugador aux;
			if (lista[n + 1].nivel > lista[n].nivel) {

				aux = lista[n + 1];
				lista[n + 1] = lista[n];
				lista[n] = aux;
			}
		}
	}
	for (int m = 0; m < (k - 1); m++) {

		for (int n = 0; n < (k - 1); n++) {

			jugador aux;
			if ((lista[n + 1].nivel == lista[n].nivel) && (lista[n + 1].test > lista[n].test)) {

				aux = lista[n + 1];
				lista[n + 1] = lista[n];
				lista[n] = aux;
			}
		}
	}

	for (int m = 0; m < (k - 1); m++) {

		for (int n = 0; n < (k - 1); n++) {

			jugador aux;
			if ((lista[n + 1].nivel == lista[n].nivel) && (lista[n + 1].test == lista[n].test) && (lista[n + 1].segundos < lista[n].segundos)) {

				aux = lista[n + 1];
				lista[n + 1] = lista[n];
				lista[n] = aux;
			}
		}
	}
	for (int m = 0; m < (k - 1); m++) {

		fichero1 << m + 1 << " " << lista[m].nombre << endl;
		fichero1 << lista[0].texto1 << " " << lista[m].nivel << " " << endl;
		fichero1 << lista[0].texto2 << " " << lista[m].test << " " << lista[0].texto3 << endl;
		fichero1 << lista[0].texto4 << " " << lista[m].segundos << " " << lista[0].texto5 << endl << endl;


		auxetsidim.Texto("david", 0, 0, 0, 0, 0, 20);
	}
}

void Mundo::InicializaFondo(int nivel) { //Inicializa con todas las plataformas y virus
	int j = 5; //auxiliar para crear  respecto una frecuencia las pltaformas
	 // Se separa en 3 partes dependiendo del nivel

	/////NIVEL 1////
	if (nivel == 1) {

	/// lanzamisiles
		listalanzamisiles.Agregar(new Lanzamisiles("imagenes/lanzamisiles.png", 30, -3)); ///L1
		listalanzamisiles.Agregar(new Lanzamisiles("imagenes/lanzamisiles.png", 70, 5.75));  ///L2

	////plataformas del suelo
		for (int y = -6; y < 29; y++) {
			if (y != 3 && y != 4 && y != 10 && y != 11 && y != 12 && y != 13 && y != 14 && y != 15 && y != 16 && y != 21 && y != 22 && y != 26 && y != 27 && y != 28) {
				plataformas.Agregar(new Plataformas(Plataformas::SUELO, j * y, -5.5, 5, 1.5));
			}
		}
		for (int y = 40; y < 50; y++) {
			plataformas.Agregar(new Plataformas(Plataformas::SUELO, j * y, -5.5, 5, 1.5));

		}

	///plataformas aereas

		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 15, 3, 4, 1.5));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 40, 2, 4, 1.5));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 50, 4, 4, 1.5));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 60, 6, 4, 1.5));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 70, 3, 4, 1.5));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 70, 10, 4, 1.5));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 90, 2, 4, 1.5));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 100, 4, 4, 1.5));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 130, 3, 4, 1.5));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 140, 2, 4, 1.5));

	/// plataformas moviles
		

		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_MUEVE, 140, 10, 3, 1.5, 140, 160));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_MUEVE, 180, 6, 3, 1.5, 160, 180));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_MUEVE, 180, 12, 3, 1.5, 180, 200));	////caen	

	//Añadimos Virus: slime, seta y mosca 

		listavirus.agregar(new VirusSlime(35, -3, 9));		
		listavirus.agregar(new VirusSeta(122, -3, 5));
		listavirus.agregar(new VirusSlime(122, -3, 7));
		listavirus.agregar(new VirusMosca(230, 15,15)); //MALO FINAL DEL NIVEL 1
		listavirus.agregar(new VirusSeta(230, -3, 5));
	
	/// tests (son simplemente para la puntuacion)	
		listabonus.agregar(new BonusTest(10, -2, 2, 2));
		listabonus.agregar(new BonusTest(25, -2, 2, 2));
		listabonus.agregar(new BonusTest(30, -2, 2, 2));
		listabonus.agregar(new BonusTest(40, -2, 2, 2));
		listabonus.agregar(new BonusTest(60, -2, 2, 2));
		listabonus.agregar(new BonusTest(70, -2, 2, 2));
		listabonus.agregar(new BonusTest(85, -2, 2, 2));
		listabonus.agregar(new BonusTest(90, -2, 2, 2));
		listabonus.agregar(new BonusTest(100, -2, 2, 2));
		listabonus.agregar(new BonusTest(130, -2, 2, 2));
		listabonus.agregar(new BonusTest(140, -2, 2, 2));
		listabonus.agregar(new BonusTest(150, -2, 2, 2));
		listabonus.agregar(new BonusTest(170, -2, 2, 2));
		listabonus.agregar(new BonusTest(180, -2, 2, 2));
		listabonus.agregar(new BonusTest(190, -2, 2, 2));
			
	}
	////NIVEL 2///
	else if (nivel == 2) {
		listalanzamisiles.DestruirContenido();
		

		for (int y = -6; y < 3; y++) {
			plataformas.Agregar(new Plataformas(Plataformas::SUELO, j * y, -5.5, 5, 1.5));

		}//escalera
		for (int i = -4; i < 8; i++) {
			plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 2 * i, i+5, 5, 1.5));
		}

		//oasillo
		for (int i = 4; i < 14; i++) {
			if (i % 2) {
				plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 5 * i, 13, 5, 1.5));
				plataformas.Agregar(new Plataformas(Plataformas::SUELO, 5 * i + 5, 13, 5, 1.5));
			}
		}
		
		for (int x = 6; x < 20; x++) {

				plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 5 * x, -5.5,5, 1.5));
				
			
		}
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 100,2.5, 5, 1.5));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 110, 5, 5, 1.5));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 120, 8, 5, 1.5));

		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 130, 10, 1, 1));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 140, 12, 1, 1));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 150, 8, 1, 1));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 160, 12, 1, 1));

		/*for (int x = 10; x> -5; x--) {

			plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 130, x, 1, 1));


		}*/

		/*for (int y = 6; y < 20; y++) {
			if (y % 2) {
				plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 0, 2 * y+2, 4, 1.5));
				
			}*/
		
		

	//Añadimos virus: slime seta y mosca
		listavirus.agregar(new VirusSlime(50, -3, 9));		
		listavirus.agregar(new VirusSeta(50, -3, 15));
		listavirus.agregar(new VirusSeta(80, -3, 15));
		listavirus.agregar(new VirusSeta(80, -3, 13));
		listavirus.agregar(new VirusSlime(110, -3, 16));
		listavirus.agregar(new VirusSlime(110, -3, 10));
		listavirus.agregar(new VirusSlime(110, -3, 8));
		listavirus.agregar(new VirusMosca(80, 12, 15));
		listavirus.agregar(new VirusSeta(200, -3, 13));
		listavirus.agregar(new VirusSlime(200, -3, 10));
		listavirus.agregar(new VirusSeta(200, -3, 18));
	}
	
	else if (nivel == 3) {


		//plataformas suelo
		for (int y = -2; y < 15; y++) {
			plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 25, y * 1.5, 5, 1.5));

		}
		for (int y = 40; y < 50; y++) {
			plataformas.Agregar(new Plataformas(Plataformas::SUELO, j * y, -5.5, 5, 1.5));

		}
		for (int y = -6; y < 6; y++) {
			plataformas.Agregar(new Plataformas(Plataformas::SUELO, j * y, -5.5, 5, 1.5));

		}
		//plataformas moviles
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_MUEVE, 30, 22.5, 3, 1.5, 30, 40));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_MUEVE, 55, 4, 3, 1.5, 45, 55));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_MUEVE, 60, 2, 3, 1.5, 60, 70));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_MUEVE, 85, -2, 3, 1.5, 75, 85));

		//plataformas suelo 		

		plataformas.Agregar(new Plataformas(Plataformas::SUELO, 95, -5.5, 5, 1.5));
		plataformas.Agregar(new Plataformas(Plataformas::SUELO, 100, -5.5, 5, 1.5));
		plataformas.Agregar(new Plataformas(Plataformas::SUELO, 105, -5.5, 5, 1.5));
		plataformas.Agregar(new Plataformas(Plataformas::SUELO, 110, -5.5, 5, 1.5));
		plataformas.Agregar(new Plataformas(Plataformas::SUELO, 115, -5.5, 5, 1.5));
		plataformas.Agregar(new Plataformas(Plataformas::SUELO, 120, -5.5, 5, 1.5));

		//plataformas aereas		
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 130, 1, 5, 1.5));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 120, 6, 5, 1.5));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 115, 6, 5, 1.5));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 110, 6, 5, 1.5));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 130, 18, 5, 1.5));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 100, 10, 5, 1.5));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 125, 18, 5, 1.5));


		for (int i = 0; i < 6; i++) {

			plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 95 + 5 * i, 18, 5, 1.5));
		}
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 100, 10, 5, 1.5));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_MUEVE, 80, 8, 5, 1.5, 80, 90));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_MUEVE, 75, 13, 2, 1.5, 65, 75));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_MUEVE, 75, 18, 2, 1.5, 80, 90));


		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_MUEVE, 135, 14, 5, 1.5, 135, 145));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_MUEVE, 160, 10, 5, 1.5, 150, 160));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_MUEVE, 165, 6, 5, 1.5, 165, 175));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_MUEVE, 190, 6, 5, 1.5, 180, 190));

		for (int i = 0; i < 10; i++) {

			plataformas.Agregar(new Plataformas(Plataformas::SUELO, 135 + 5 * i, -5.5, 5, 1.5));
		}
		///////plataformas malo final
		for (int i = 1; i < 4; i++) {
			plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 200, i * 5 + i, 5, 1.5));
		}
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 220, 15, 5, 1.5));
		for (int i = 1; i < 4; i++) {
			plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 240, i * 5 + i, 5, 1.5));
		}
		// tests (son simplemente para la puntuacion)	
		listabonus.agregar(new BonusTest(10, -2, 2, 2));		
		listabonus.agregar(new BonusTest(30, -2, 2, 2));
		listabonus.agregar(new BonusTest(40, -2, 2, 2));
		listabonus.agregar(new BonusTest(60, -2, 2, 2));
		listabonus.agregar(new BonusTest(90, -2, 2, 2));
		listabonus.agregar(new BonusTest(100, -2, 2, 2));
		listabonus.agregar(new BonusTest(130, -2, 2, 2));
		listabonus.agregar(new BonusTest(140, -2, 2, 2));
		listabonus.agregar(new BonusTest(150, -2, 2, 2));
		listabonus.agregar(new BonusTest(170, -2, 2, 2));
		listabonus.agregar(new BonusTest(190, -2, 2, 2));
	}
}
void Mundo::Inicializa(int level) { //Inicializa principal
	finaldenivel = 0;   //para tener en cuenta si se acaba el nivel
	hombre.Inicializa();
	personajes.Inicializa(hombre);
	virus2.Inicializa(-5, 1);
	limites.SetLimites(-20, 500, -10, 30); //Son los bordes del juego que el jugador no puede pasar	
	vidas.Inicializa(hombre);
}

ETSIDI::Vector2D Mundo::GetHombrePos(){ //Necesario para poder gestionar el aviso al final del nivel o al perder
	ETSIDI::Vector2D pos;
	pos.x = hombre.GetPos().x;
	pos.y = hombre.GetPos().y;
	return pos;
}

void Mundo::DibujaBasico() {
	hombre.Dibuja();
	limites.Dibuja();
	vidas.Dibuja(hombre, hombre.GetVidas());
	plataformas.Dibuja();
}
void Mundo::Dibuja(int level) {
	///Dibuja general
	personajes.Dibuja(level, hombre);
	disparos.Dibuja();
	misiles.Dibuja();
	listalanzamisiles.Dibuja();
	virus2.Dibuja(level);
	listaexplosiones.dibuja();
	listavirus.dibuja();
	listaslime.dibuja();
	listaslime2.dibuja();
	disparobaba.dibuja();
	listabonus.dibuja();

	//gestion del movimiento de bonus, misiles especificos del nivel.
	//Tambien se gestiona las plataformas que desaparecen
	if (level == 1) {
		float naleatorio = lanzaDado(800.0);
		if (naleatorio < 10) {
			misiles.Agregar(new Misil("imagenes/misilizq.png", 29, -2, -5.0f, 0.0f));
		}
		 if (naleatorio < 5) {

			misiles.Agregar(new Misil("imagenes/misilizq.png", 69, 6.55, -5.0f, 0.0f));
		}
		 if (naleatorio < 1) {

			listabonus.agregar(new BonusMascarilla(hombre.GetPosX() + naleatorio * 10, 25, 1.5, 1.5));

		}
		 else if (naleatorio < 4) {
			listabonus.agregar(new Municion(hombre.GetPosX() + naleatorio * 8, 25, 2, 2));

		}
		if (hombre.GetPos().x > 90 && hombre.GetPos().x < 100) {
			/*if (plataformas.ColisionSube(hombre) != 0) {
				Plataformas* auxPLAT = plataformas.ColisionSube(hombre);*/

			if (plataformas.ColisionSube(hombre) != 0 && plataformas.ColisionSube(hombre)->GetTipo() != plataformas.ColisionSube(hombre)->PLATAFORMA_CHOCA)
				plataformas.Eliminar(plataformas.ColisionSube(hombre));
		}

	}
	if (level == 2) {
		if (hombre.GetPos().x > 35){
			if (plataformas.ColisionSube(hombre) != 0 && plataformas.ColisionSube(hombre)->GetTipo() == plataformas.ColisionSube(hombre)->SUELO)
				plataformas.Eliminar(plataformas.ColisionSube(hombre));
		}
	}
	if (level == 3) {

		if (hombre.GetPos().x > 122 && hombre.GetPos().x < 125) {
			if (plataformas.ColisionSube(hombre) != 0 && plataformas.ColisionSube(hombre)->GetTipo() == plataformas.ColisionSube(hombre)->PLATAFORMA_CHOCA)
				plataformas.Eliminar(plataformas.ColisionSube(hombre));
		}
		if (hombre.GetPos().x > 135 && hombre.GetPos().x < 190) {
			if (plataformas.ColisionSube(hombre) != 0 && plataformas.ColisionSube(hombre)->GetTipo() == plataformas.ColisionSube(hombre)->SUELO)
				plataformas.Eliminar(plataformas.ColisionSube(hombre));
		}
	}
}

//Fin partida para avisar al coordinador
int Mundo::Muerte() { //FIN PARTID:muerte
	
	if (hombre.GetVidas() > 0) {return 0;}
	else { return 1; hombre.SetDir(0); }
		
}
int Mundo::Ganar() {//FIN DE PARTIDA: Ganador	
	if (hombre.GetFinNivel() == 1) {
		if (hombre.posicion.x < 225) {//HABRÁ QUE AMPLIARLO			
			return 0;		
		}
		else {
			return 1;
			hombre.Victoria(); //doesnt work :c sadly
		}
	}
}
void Mundo::MueveHombre() { //Solo para en caso de muerte o ganar se necesita en el coordinador
	hombre.SetVel(0, -10);
	hombre.SetDir(0);
	hombre.Mueve(0.025f);
	float max;
	if (plataformas.ColisionSube(hombre) != 0) {
		hombre.SetVel(hombre.GetVel().x, 0.0);
	}
}
void Mundo::Mueve(int level)
{
	hombre.caida((Interaccion::caida(hombre, limites)), level);
	
	//OJO//

	if (hombre.posicion.x > 0 && level != 0) Setojo(hombre.posicion.x, 10, 53);		
	else Setojo(0, 10, 53);		

	//.Mueve//
	
	personajes.Mueve(0.025f);
	virus2.Mueve(0.025f,disparobaba, hombre);	
	hombre.Mueve(0.025f);
	disparos.Mueve(0.025f,hombre);
	misiles.Mueve(0.025f);
	vidas.Mueve(x_ojo);

	listavirus.mueve(0.025f, hombre);
	listavirus.Sigue(hombre);	
	listaslime.mueve(0.025f, hombre);
	disparobaba.mueve(0.025f, hombre);
	listabonus.mueve(0.025f);	
	listaexplosiones.mueve(0.025f);
	plataformas.Mueve(0.025f);

	////INTERACCIONES////	
	listavirus.Colision(disparos, listaexplosiones, listabonus);
	listavirus.Colision(hombre);
	plataformas.Colision(slime);
	listaslime.Colision(limites);
	listaslime.Colision(plataformas);
	listaslime.Colision(hombre);
	disparobaba.Colision(limites);
	disparobaba.Colision(plataformas);
	disparobaba.Colision(hombre);
	listabonus.Colision(limites);
	listabonus.Colision(plataformaprueba);
	listabonus.colision(hombre);

	if(lanzaDado(90)<2)	listavirus.Dispara(listaslime);	

	//posibles interacciones del hombre con plataformas:
	if (Interaccion::caida(hombre, limites) == 1)	salto = 0;		
	if (plataformas.ColisionChoca(hombre) != 0) {
		hombre.SetVel(hombre.GetVel().x, -10.0);
	}
	if (plataformas.ColisionSube(hombre) != 0) {
		hombre.SetVel(hombre.GetVel().x, 0.0);
		salto = 1;
	}
	if (plataformas.ColisionChocaLado(hombre) != 0) {
		hombre.SetVel(hombre.GetVel().x, -10.0);
	}

	//misiles vs Hombre
	Misil* aux = misiles.colision(hombre);
	if (aux != 0) {
		if (hombre.GetVidas() >= 1) {
			hombre.Dañar();
			misiles.Eliminar(aux);
		}
	}
	//bonus vs plataformas
	for (int t = 0; t < plataformas.GetNumero(); t++) {
		listabonus.Colision(*plataformas[t]);
	}
	}
void Mundo::Tecla(unsigned char key)
{
	switch (key) {

//disparos
	case 'w': //disparo hacia arriba
		if (hombre.Poderdisparar()) { 
			disparos.Agregar(new Disparo(0.5, hombre.posicion.x, hombre.posicion.y, 0.0f, 22.0f));			
		}
		break;		
	case 's': //disparo hacia abajo
		if (hombre.Poderdisparar()) {
			disparos.Agregar(new Disparo(0.5, hombre.posicion.x, hombre.posicion.y, 0.0f, -22.0f)); /// radio, x , y, vx, vy				
			
		}
		break;	
	case 'a': //disparo hacia la izda
		if (hombre.Poderdisparar()) {
			disparos.Agregar(new Disparo(0.5, hombre.posicion.x, hombre.posicion.y, -22.0f, 0.0f));
			
		}
		break;
	case 'd': //disparo hacia la derecha
		if (hombre.Poderdisparar()) {
			disparos.Agregar(new Disparo(0.5, hombre.posicion.x, hombre.posicion.y, 22.0f, 0.0f));

		}
		break;		
	case 'f': //disparo especial
		if (hombre.Poderdispararespecial()) {
			disparos.Agregar(new DisparoEspecial(0.5, hombre.posicion.x, hombre.posicion.y, 22.0f, 0.0f));
			
		}
		break;
	case ' ': //dejar quieto el personaje
		hombre.SetVel(0, hombre.velocidad.y);
		hombre.SetDir(0);

		break;
//hacks y tests:
	case 'm':
		virus2.Ataca();
		break;
	case 'n':
		//virus3.dispara(listaslime);
		break;
	case 'j':
		listabonus.agregar(new BonusMascarilla(hombre.GetPos().x, 25, 1.5, 1.5));
		break;
	case 'x':
		
		misiles.Agregar(new Misil("imagenes/misilizq.png", 29, -2.0f, -5.0f, 0.0f));
		break;
		
	case 't':	
		hombre.Dañar();
		break;
	case 'y':
		if (hombre.GetVidas() > 0) {			
			hombre.SetVidas(hombre.GetVidas() - 1);
		}
		break;
	case 'v': //IMPORTANTE: AVANZAR EN EL NIVEL AUTOMATICAMENTE
		hombre.SetPos(90, 20);
		break;
	case 'b': //IMPORTANTE: AVANZAR EN EL NIVEL AUTOMATICAMENTE
		hombre.SetPos(190, 20);
		break;
	}	
}

void Mundo::teclaEspecial(unsigned char key) {
	hombre.Setagachado(key);
	switch (key){
		//DIRECCIONES 
		case GLUT_KEY_LEFT:
			hombre.SetVel(-6, hombre.GetVel().y);
			//HAY QUE PONER QUE CUANDO ESTE EN EL AIRE NO VAYA HACIA LA DERECHA
			hombre.SetDir(2);
			break;
		case GLUT_KEY_RIGHT:
			hombre.SetVel(6, hombre.GetVel().y);

			hombre.SetDir(1);
			break;
		case GLUT_KEY_DOWN: 
			hombre.Agacha();
			break;
		case GLUT_KEY_UP:
			if (salto == 1) {
				hombre.SetVel(hombre.GetVel().x, +18);
		
				salto = 0;
				ETSIDI::play("mis_sonidos/salto.wav");
			}
	
			break;
		}
	}



void Mundo::RecargarNivel(int level) { //REINICIAR 
	Setojo(0, 10, 53);
	tiempo = clock(); //para el tiempo

	hombre.FinPartida();//REINICIA TODO LO DEL HOMBRE	
	disparos.DestruirContenido();	
	plataformas.DestruirContenido(plataformas.GetNumero());
	listavirus.destruirContenido();
	InicializaFondo(level);
	misiles.limpiar();
	listaslime.destruirContenido();
	personajes.Inicializa(hombre);
	
 //	listabonus.destruirContenido(); desaparecen los test???
	
	
}



