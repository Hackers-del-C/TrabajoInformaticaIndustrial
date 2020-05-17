#pragma once
#include <Windows.h>
#include <stdio.h>
#include "Mundo.h"
#include "Interaccion.h"
#include "ListaDisparos.h"
#include "ListaExplosiones.h"
#include <math.h>
#include "glut.h"
#include <fstream>
#define NUM_MAX_RANKING 100


Mundo::Mundo(){
	
}
void Mundo::Setojo(float ox, float oy, float oz) { //Set del deojo

	x_ojo = ox;
	y_ojo = oy;
	z_ojo = oz;

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
		
		fichero >>lista[k].posicion>> lista[k].nombre;
		fichero >> lista[k].texto1 >> lista[k].nivel;
		fichero >> lista[k].texto2 >> lista[k].test >> lista[k].texto3;
		fichero >> lista[k].texto4 >> lista[k].segundos >> lista[k].texto5;
		k++;
	}
	
	
	lista[k].nombre = "david";
	lista[k].nivel = level;
	lista[k].test =  hombre.GetMonedas();
	lista[k++].segundos =  ((clock() - tiempo) / 1000);
	

	fichero.close();
	remove("resultado_final.txt");
	ofstream fichero1("resultado_final.txt");
	fichero.open("resultado_final.txt");

	//ordenar

	for (int m = 0; m < (k - 1); m++) {

		for (int n = 0; n < (k - 1); n++){

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
			if ((lista[n + 1].nivel == lista[n].nivel)&&(lista[n + 1].test > lista[n].test)) {

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
	for (int m = 0; m < (k -1); m++) {
	
		fichero1 << m+1 <<" " << lista[m].nombre << endl;
		fichero1 << lista[0].texto1 << " " << lista[m].nivel << " " << endl;
		fichero1 << lista[0].texto2 << " " << lista[m].test << " " << lista[0].texto3 << endl;
		fichero1 << lista[0].texto4 << " " << lista[m].segundos << " " << lista[0].texto5 << endl << endl;
	
	
	}


	 
}

void Mundo::InicializaFondo(int nivel) { //agregar cosas
	int j = 5;
	hombre.caida((Interaccion::caida(hombre, limites)), nivel);
	if(nivel==1){	
		///lanzamisiles2
		//plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 70, 8, 4, 1.5));
		
		/// lanzamisiles
			listalanzamisiles.Agregar(new Lanzamisiles("imagenes/lanzamisiles.png", 30, -3)); ///L1
			listalanzamisiles.Agregar(new Lanzamisiles("imagenes/lanzamisiles.png", 70,5.75));  ///L2
		
		////suelo
		for (int y = -6; y < 29; y++) {
			if (y != 3 && y != 4 && y != 10 && y !=11 && y != 12 && y != 13 && y != 14&& y != 15 && y != 16 && y != 21 && y != 22 && y != 26 && y != 27 && y != 28 ) {
				plataformas.Agregar(new Plataformas(Plataformas::SUELO, j * y, -5.5, 5, 1.5));
			}
		}
		for (int y = 40; y < 50; y++) {
				plataformas.Agregar(new Plataformas(Plataformas::SUELO, j * y, -5.5, 5, 1.5));
		
		}

		///aereas

		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 15,  3, 4, 1.5));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 40, 2, 4, 1.5));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 50, 4, 4, 1.5));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 60, 6, 4, 1.5));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 70, 3, 4, 1.5));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 70, 10, 4, 1.5));
		//plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 80, 6, 4, 1.5));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 90, 2, 4, 1.5));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 100, 4, 4, 1.5));
		//plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 110, 2, 4, 1.5));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 130, 3, 4, 1.5));
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 140, 2, 4, 1.5));

		///moviles
		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_MUEVE, 140, 10, 3, 1.5, 140, 200));

		////caen

		if (hombre.GetPos().x > 90 && hombre.GetPos().x < 100) {
			/*if (plataformas.ColisionSube(hombre) != 0) {
				Plataformas* auxPLAT = plataformas.ColisionSube(hombre);*/

			if (plataformas.ColisionSube(hombre) != 0 && plataformas.ColisionSube(hombre)->GetTipo() != plataformas.ColisionSube(hombre)->PLATAFORMA_CHOCA)
				plataformas.Eliminar(plataformas.ColisionSube(hombre));
		}

		//A�adimos Virus
		//VirusSeta y virus slime
		listavirus.agregar(new VirusSlime(35, -3, 9));
		listavirus.agregar(new VirusSeta(94, -3, 7));
		listavirus.agregar(new VirusSeta(122, -3, 5));
		listavirus.agregar(new VirusSlime(122, -3, 7));
		
		listavirus.agregar(new VirusMosca(230, 15));

		/*	float max;
			for (int i = 0; i < 200; i++) {
				if (plataformas[i]->GetPos().x <= hombre.GetPos().x) {
					max = plataformas[i]->GetPos().x;
				}
			}*/
		
			//if (Interaccion::caida(hombre, limites) == 1) {

			//	//hombre.SetPos(max, hombre.GetPos().y + 10);
			//	//hombre.SetPos(auxPLAT->GetPos().x/2, auxPLAT->GetPos().y + 4);
			//	if (hombre.GetControl() == 0) {
			//		hombre.SetPos(0, 2);
			//		hombre.SetVidas(hombre.GetVidas() - 1);
			//		hombre.SetVel(0, 0);
			//	}
			//	else {
			//		hombre.SetPos(70, 12);
			//		hombre.SetVidas(hombre.GetVidas() - 1);
			//		hombre.SetVel(0, 0);
			//	}
			//}
	}
		/*for (int x = 0; x < 20; x++) {
			if (x < 5) {
				plataformas.Agregar(new Plataformas(Plataformas::SUELO, 10 * x - x / 2, x + 2, 4, 1.5));
			}
			else {
				plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 10 * x - x / 2, x - 2, 4, 1.5));
			}
		}*/
	
	else if (nivel == 2) {

		plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_MUEVE, 5, 10, 4, 1.5));
		for (int y = -6; y < 50; y++) {
			if (y != 2 && y != 3 && y != 4 && y != 8 && y !=9 && y != 10 && y != 20 && y != 21) {
				plataformas.Agregar(new Plataformas(Plataformas::SUELO, j * y, -5.5, 5, 1.5));
			}
		}
		for (int x = 0; x < 20; x++) {
			if (x < 5) {
				plataformas.Agregar(new Plataformas(Plataformas::SUELO, 10 * x/2, x + 2, 4, 1.5));
			}
			else {
				plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 10 * x /2, x - 2, 4, 1.5));
			}
		}
	}
	else if (nivel == 3) {

	}
	
}
void Mundo::Inicializa(int level) {

	hombre.Inicializa();
	personajes.Inicializa(hombre);
	virus2.Inicializa(-5, 1);
	//virus3.Inicializa(-10, 15);
	limites.SetLimites(-20, 500, -10, 30); //Son los bordes del juego que el jugador no puede pasar	
	vidas.Inicializa(hombre);
	

	/*for (int i = 0; i < 1; i++) {
		listavirus.agregar(new VirusSeta(0, -3, 5));
	}
	for (int i = 0; i < 1; i++) {
		listavirus.agregar(new VirusSlime(30 + 30 * i, -3));
	}*/
	for (int i = 0; i < 20; i++) {
		listabonus.agregar(new BonusTest(lanzaDado(180), lanzaDado(6), 2, 2));
	}

	
	//slime.Inicializa(-10, 10);
	//listaexplosiones.agregar(new Explosiones(0, 0));
	/* AGREGA VIRUS
	for (int i = 0; i < 5; i++)
	{
		Virus* aux = new Virus("trump", 6, 1, 4 + 2 * i, 4, 3, 3, 1, 0);
		//aux->Inicializa("trump", 6, 1, 4 + 2 * i, 4, 3, 3, 1, 0);
		listavirus.agregar(aux);
	}

	for (int i = 0; i < 5; i++)
	{
		Virus* aux = new Virus("virusseta", 8, 1, -15 + 2 * i, 4, 1, 1, 0, 0);
		//aux->Inicializa("trump", 6, 1, 4 + 2 * i, 4, 3, 3, 1, 0);
		listavirus.agregar(aux);
	}
	*/
	//for (int i = 0; i < 5; i++)
	//{
	//	Virus* aux = new Virus();
	//	aux->Inicializa("virusseta", 8, 1, -10 + 2.5 * i, 4, 2, 2, 0, 0);
	//	listavirus.agregar(aux);
	//}}
}

ETSIDI::Vector2D Mundo::GetHombrePos(){ //en principio es para sacar el cuadrado negro que te dice que has perdido, es un mini menu vaya
	ETSIDI::Vector2D pos;
	pos.x = hombre.GetPos().x;
	pos.y = hombre.GetPos().y;
	return pos;
}
void Mundo::InicioDibuja() { //para que funcione bien los dibujas llamados desde el coordinador, tiene que estar primero el ojo
	/*Se ha decido dejar el ojo en Mundo.cpp porque va conectado con la posicion del hombre en la gran mayor�a del tiempo*/
	gluLookAt(x_ojo, y_ojo, z_ojo,
		x_ojo, y_ojo, 0.0, //NOTESE QUE HEMOS CAMBIADO ESTO
		0.0, 5.0, 0.0); //PARA MIRAR AL CENTRO DE LA ESCENA
	
}
void Mundo::DibujaBasico() {
	hombre.Dibuja();
	limites.Dibuja();
	vidas.Dibuja(hombre, hombre.GetVidas());
	plataformas.Dibuja();
}
void Mundo::Dibuja(int level) {
	
	
	personajes.Dibuja(level, hombre);
	disparos.Dibuja();
	misiles.Dibuja();
	listalanzamisiles.Dibuja();
	virus2.Dibuja(level);	
	listaexplosiones.dibuja();
	listavirus.dibuja();
	listaslime.dibuja();	
	listabonus.dibuja();
	

	
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
	}
		
}

int Mundo::Muerte() { 
	//fin de partida :muerte
	if (hombre.GetVidas() > 0) {
		return 0;
	}
	else {
		return 1;
		
		
	}
		
}
int Mundo::Ganar() {//tiene problemas
	//FIN DE PARTIRA: Ganador
	if (hombre.posicion.x < 225) {//HABR� QUE AMPLIARLO
		
		return 0;
		//musica de ganador va aqui
	}
	else {
		return 1;
	
	
	}
}
void Mundo::MueveHombre() { //Solo para en caso de muerte o ganar se necesita en el coordinador
	hombre.SetVel(0, -10);
	hombre.SetDir(0);
	hombre.Mueve(0.025f);
	float max;
	//if (Interaccion::caida(hombre, limites) == 1) {
	//	for (int i = 0; i < plataformas.GetNumero(); i++) {
	//		if (plataformas[i]->GetPos().x < hombre.GetPos().x) {
	//		max = plataformas[i]->GetPos().x;
	//		}
	//	}
	//	hombre.SetPos(max, hombre.GetPos().y + 10);
	//	//hombre.SetPos(auxPLAT->GetPos().x/2, auxPLAT->GetPos().y + 4);
	//	hombre.SetVel(0, 0);
	//}
	if (plataformas.ColisionSube(hombre) != 0) {
		hombre.SetVel(hombre.GetVel().x, 0.0);
	}
}
void Mundo::Mueve(int level)
{

	//OJO//

	if (hombre.posicion.x > 0 && level != 0) 
		Setojo(hombre.posicion.x, 10, 53);
	else
		Setojo(0, 10, 53);


	//.Mueve//
	
	personajes.Mueve(0.025f);
	virus2.Mueve(0.025f);	
	hombre.Mueve(0.025f);
	disparos.Mueve(0.025f,hombre);
	misiles.Mueve(0.025f);
	vidas.Mueve(x_ojo);

	listavirus.mueve(0.025f, hombre);
	listavirus.Sigue(hombre);	
	listaslime.mueve(0.025f, hombre);
	listabonus.mueve(0.025f);	
	listaexplosiones.mueve(0.025f);
	plataformas.Mueve(0.025f);

	////INTERACCIONES////

	
	listavirus.Colision(disparos, listaexplosiones);
	listavirus.Colision(hombre);
	plataformas.Colision(slime);
	listaslime.Colision(limites);
	listaslime.Colision(plataformas);
	listaslime.Colision(hombre);
	listabonus.Colision(limites);
	listabonus.Colision(plataformaprueba);
	listabonus.colision(hombre);

	//Disparos virus aleatorios

	if (hombre.GetPos().x > 170) { //Podria ponerse mejor
		if(lanzaDado(60)<2)
		listavirus.Dispara(listaslime);
	}



	//Interaccion::Colision(bonus1, limites);
	//Interaccion::Colision(slime, limites);
	//Interaccion::reboteinterior(hombre, limites);

	if (Interaccion::caida(hombre, limites) == 1)
		salto = 0;

	//if (Interaccion::Colision(hombre, virus1)) {
	//	if (virus1.GetMuerto() == 0) {
	//		hombre.SetVidas(hombre.GetVidas() - 1);
	//	}
	//}


	/*if (Interaccion::colision(hombre, bonus1)) {
		hombre.SetVidas(hombre.GetVidas() + 1);
	}*/

	//////HOMBRE-PLATAFORMA

	//if (Interaccion::colision(hombre, limites)) {
	//	//|| Interaccion::ColisionSube(hombre, plataformaprueba)) {
	//	salto = 1;
	//}

	//////plataforma-hombre funciona: ---- NO BORRAR
	/*
	if (Interaccion::ColisionSube(hombre, plataformaprueba)) {
		hombre.SetVel(hombre.GetVel().x, 0.0);
		plataformaprueba.aux = 1;
		salto = 1;
	}
	else {

		plataformaprueba.aux = 0;
	}

	if (Interaccion::ColisionChoca(hombre, plataformaprueba)) {
		hombre.SetVel(hombre.GetVel().x, -10.0);


		//plataformaprueba.aux = 1;

	}
	if (Interaccion::ColisionChocaLado(hombre, plataformaprueba)) {
		hombre.SetVel(0.0, -10.0);

		//plataformaprueba.aux = 1;

	}
	*/
	//////////


	if (plataformas.ColisionSube(hombre) != 0) {
		hombre.SetVel(hombre.GetVel().x, 0.0);
		salto = 1;
	}
	if (plataformas.ColisionChoca(hombre) != 0) {
		hombre.SetVel(hombre.GetVel().x, -10.0);

	}
	if (plataformas.ColisionChocaLado(hombre) != 0) {
		hombre.SetVel(hombre.GetVel().x, -10.0);
	}

	//Colision virus con disp	
		//disparo.eliminar(aux7);	

	///////// misil-hombre
	Misil* aux = misiles.colision(hombre);
	if (aux != 0) {
		if (hombre.GetVidas() >= 1) {
			hombre.Da�ar();
			misiles.Eliminar(aux);
		}
		//misiles.Eliminar(aux);

	//misiles.Explota();
	}
	for (int t = 0; t < plataformas.GetNumero(); t++) {
		listabonus.Colision(*plataformas[t]);
	}


	//ETSIDI::Vector2D poscaida = auxPLAT->GetLim2();
	//if (Interaccion::caida(hombre, limites) == 1) {
	//	if (hombre.GetPos().x > auxPLAT->GetLim2().x) {
	//		hombre.SetPos(auxPLAT->GetLim2().x-2, auxPLAT->GetLim2().y+4);
	//	}
	//}
	//Plataformas* auxPLAT = plataformas.ColisionSube(hombre);
	//plataformas.Eliminar(plataformas.ColisionSube(hombre));

	
	//float pos1= auxPLAT->GetPos().x;
	//float pos2 = auxPLAT->GetPos().y;

	//plataformas.Eliminar(auxPLAT);
	//if (plataformas.ColisionSube(hombre) != 0) {
		//	Plataformas* auxPLAT = plataformas.ColisionSube(hombre);
		//if (Interaccion::caida(hombre, limites) == 1) {

		//	hombre.SetPos(hombre.GetPos().x - 10, hombre.GetPos().y + 10);
		//	//hombre.SetPos(auxPLAT->GetPos().x / 2, auxPLAT->GetPos().y + 4);
		//	hombre.SetVel(0, 0);
		//	hombre.SetVidas(hombre.GetVidas() - 1);
		//}
	//    }

	misiles.limpiar();

}



void Mundo::Tecla(unsigned char key)
{
	
	switch (key) {
	case 'm':
		virus2.Ataca();

		break;
	case 'n':
		//virus3.dispara(listaslime);

		break;
	case 'w':
		disparos.Agregar(new Disparo(0.5, hombre.posicion.x, hombre.posicion.y, 0.0f, 22.0f));

		break;
	case 's':

		disparos.Agregar(new Disparo(0.5, hombre.posicion.x, hombre.posicion.y, 0.0f, -22.0f)); /// radio, x , y, vx, vy			
		break;

	case 'a':
		disparos.Agregar(new Disparo(0.5, hombre.posicion.x, hombre.posicion.y, -22.0f, 0.0f));
		break;

	case 'd':
		disparos.Agregar(new Disparo(0.5, hombre.posicion.x, hombre.posicion.y, 22.0f, 0.0f));
		break;
	case 'f':
		disparos.Agregar(new DisparoEspecial(0.5, hombre.posicion.x, hombre.posicion.y, 22.0f, 0.0f));
		break;

	case 'j':

		listabonus.agregar(new BonusMascarilla(hombre.GetPos().x, 25, 1.5, 1.5));
		break;
	case 'x':
		//virus.Muere();
		misiles.Agregar(new Misil("imagenes/misilizq.png", 29, -2.0f, -5.0f, 0.0f));
		break;
		///////// TESTS DE VIDAS
	case 't':
	
			hombre.Da�ar();
		

		break;
	case 'y':
		if (hombre.GetVidas() > 0) {
			//hombre.vidas--; /// radio, x , y, vx, vy
			hombre.SetVidas(hombre.GetVidas() - 1);
		}
		break;
	case 'v':
		hombre.SetPos(70, 20);
		break;
		///test
	/*case 'p':
		return 10;
		break;*/
	case ' ':
		hombre.SetVel(0, hombre.velocidad.y);
		hombre.SetDir(0);

		break;

	}
	
}

void Mundo::teclaEspecial(unsigned char key) {
	hombre.Setagachado(key);
	switch (key){
		
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
				
				//virus3.dispara(listaslime);
				//hombre.SetAceleracion(0.0, -20);
				salto = 0;
				ETSIDI::play("mis_sonidos/salto.wav");
			}
			/*if(Interaccion::colision(hombre, limites) || Interaccion::ColisionSube(hombre, plataformaprueba)){
				salto = 1;
				ETSIDI::play("mis_sonidos/salto.wav");
				break;
			}*/
			break;
		}
	}



void Mundo::teclaEspecialsuelta(unsigned char key) {


	switch (key)
	{
	case GLUT_KEY_LEFT:
		hombre.Stop();
		break;
	case GLUT_KEY_RIGHT:
		hombre.Stop();
		break;
	case GLUT_KEY_UP:


		break;
	}


}


void Mundo::RecargarNivel(int level) { //REINICIAR 
	hombre.FinPartida();//REINICIA TODO LO DEL HOMBRE
	Setojo(0, 10, 53);
	disparos.DestruirContenido();
	tiempo = clock(); //para el tiempo
	plataformas.DestruirContenido(plataformas.GetNumero());
	listavirus.destruirContenido();
	InicializaFondo(level);
}



