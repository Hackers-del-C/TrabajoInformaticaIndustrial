#pragma once
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include "Mundo.h"
#include "Interaccion.h"
#include "ListaDisparos.h"
//#include "ListaExplosiones.h"
#include <math.h>
#include "glut.h"
#include <fstream>


Mundo::Mundo(){
	
}
void Mundo::Setojo(float ox, float oy, float oz) {

	x_ojo = ox;
	y_ojo = oy;
	z_ojo = oz;

}

void Mundo::fichero() {

	ofstream fichero("resultado_final.txt",ofstream::out || ofstream::in ||ios::app);
	
	string datos_previos;

	

	/*while (!fichero.eof()) {

		fichero << datos_previos;
	}*/
	
	//fichero << datos_previos;
	//fichero << "Nombre: " << nombre << endl; 
	fichero << "Has cogido: " << hombre.GetMonedas() << " test" << endl;
	fichero << "Has tardado: " << (clock() - tiempo)/1000 << " segundos" << endl; // esta donde el mouse el empizo del temporizador
	

	fichero.close();


}
void Mundo::InicializaFondo() {
	int j = 5;
	///lanzamisiles2
	plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 70, 8, 4, 1.5));

	plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_MUEVE, 0, 10, 4, 1.5));

	for (int y = -6; y < 50; y++) {
		if (y != 2 && y != 3 && y != 7 && y != 8 && y != 9 && y != 10 && y != 20 && y != 21) {
			plataformas.Agregar(new Plataformas(Plataformas::SUELO, j * y, -5.5, 5, 1.5));
		}
	}
	for (int x = 0; x < 10; x++) {
		if (x < 5) {
			plataformas.Agregar(new Plataformas(Plataformas::SUELO, 10 * x - x / 2, x + 2, 4, 1.5));
		}
		else {
			plataformas.Agregar(new Plataformas(Plataformas::PLATAFORMA_CHOCA, 10 * x - x / 2, x - 2, 4, 1.5));
		}
	}
}
void Mundo::Inicializa()
{

	hombre.Inicializa();
	entorno.Inicializa(level);
	entorno.Fin(pantalla);
	personajes.Inicializa(hombre);



	virus2.Inicializa(-5, 1);

	virus3.Inicializa(-10, 15);



	for (int i = 0; i < 1; i++)
	{

		listavirus.agregar(new VirusSeta(50 + 20 * i, -3));
	}
	for (int i = 0; i < 1; i++)
	{

		listavirus.agregar(new VirusSlime(30 + 30 * i, -3));
	}
	for (int i = 0; i < 20; i++)
	{
		listabonus.agregar(new BonusTest(lanzaDado(180), lanzaDado(6), 3, 3));
	}

	//slime.Inicializa(-10, 10);


	//listaexplosiones.agregar(new Explosiones(0, 0));

	limites.SetLimites(-20, 500, -10, 30); //Son los bordes del juego que el jugador no puede pasar	
	vidas.Inicializa(hombre);



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
	//}




}
void Mundo::Dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,
		x_ojo, y_ojo, 0.0, //NOTESE QUE HEMOS CAMBIADO ESTO
		0.0, 5.0, 0.0); //PARA MIRAR AL CENTRO DE LA ESCENA
	entorno.Aviso(pantalla, hombre.posicion.x, hombre.posicion.y);
	entorno.DibujaJuego(level);

	limites.Dibuja();
	if (level == 0) {
		hombre.FinPartida();
		Setojo(0, 10, 53);
		pantalla = 0;
	}
	else if (level > 0) {
		hombre.Dibuja(pantalla);
		vidas.Dibuja(hombre, hombre.GetVidas());
		if (pantalla != 1 && pantalla != 2) {
			glPushMatrix();//guarda la matriz
			glColor3f(0, 0, 1);
			glutSolidSphere(0.2, 15, 15); //dibuja la esfera solida
			glColor3f(0, 0, -1);
			glPopMatrix();//la guarda y la restaura


			personajes.Dibuja(level, hombre);
			disparos.Dibuja();
			misiles.Dibuja();
			listalanzamisiles.Dibuja();


			virus2.Dibuja(level);
			virus3.Dibuja(level);
			
			
			listaexplosiones.dibuja();
			listaslime.dibuja();
			//slime.Dibuja();
			plataformas.Dibuja();

			bordessube.Dibuja();
			listavirus.dibuja();
			listabonus.dibuja();




			listalanzamisiles.Agregar(new Lanzamisiles("imagenes/lanzamisiles.png", 30, -3)); ///L1
			listalanzamisiles.Agregar(new Lanzamisiles("imagenes/lanzamisiles.png", 70, 10.55));  ///L2


			float naleatorio = lanzaDado(800.0);
			if (naleatorio < 10) {
				misiles.Agregar(new Misil("imagenes/misilizq.png", 29, -2, -5.0f, 0.0f));
			}
			if (naleatorio < 5) {
				misiles.Agregar(new Misil("imagenes/misilizq.png", 69, 9.55, -5.0f, 0.0f));
			}
			if (naleatorio < 1) {

				listabonus.agregar(new BonusMascarilla(hombre.GetPosX() + naleatorio * 10, 25, 1.5, 1.5));
			}
			
		
			


			if (hombre.GetVidas() == 0) {

				hombre.SetVel(0, 0);
				pantalla = 1;
				fichero();
				//musica de muerte va aqui
			}
			//FIN DE PARTIRA: Ganador
			if (hombre.posicion.x > 250) {//HABR� QUE AMPLIARLO
				hombre.SetVel(0, 0);
				pantalla = 2;
				//musica de ganador va aqui

			}
			//misilizq.Dibuja();
			//disparo.Dibuja();
			//plataforma.Dibuja();
			//bonus.Dibuja();
			//hombre.SetVidas(4);		
			//vidas.Dibuja(mascarillas);
			//disparos.Agregar(new Disparo(0.5, hombre.posicion.x, hombre.posicion.y + 2, 0.0f, 22.0f));
			//bordessube.Agregar(new BordesSube(10, 1, 20, 1.5));
			//bordessube.Agregar(new BordesSube(25, 3, 35, 3.5));		

			//ETSIDI::Vector2D posicion = hombre.GetPos();			
		}
	}
}


void Mundo::Mueve()
{
	plataformas.Mueve(0.025f);
	//esto es para cuando acaba la partida que durante 2s se congele la imagen, no se como hacerlo la verdad el getMillis
	/*if (hombre.GetVidas() == 0) {
		while (getMillis() <= 2000) {
			finde= 1;
		}
	}*/
	//OJO//

	if (hombre.posicion.x > 0 && level != 0) ////Necesitamos algo mas elegante
		Setojo(hombre.posicion.x, 10, 53);
	else
		Setojo(0, 10, 53);


	//.Mueve//
	if (pantalla != 1 && pantalla != 2) {
		personajes.Mueve(0.025f);
	}
	virus2.Mueve(0.025f);
	virus3.Mueve(0.025f);


	virus3.Seguir(hombre);

	
	listaexplosiones.mueve(0.025f);
	//slime.Mueve(0.025f);
	//bonus1.Mueve(0.025f);
	hombre.Mueve(0.025f);

	disparos.Mueve(0.025f);
	misiles.Mueve(0.025f);
	vidas.Mueve(x_ojo);

	listavirus.mueve(0.025f, hombre);
	listavirus.Sigue(hombre);
	listavirus.Colision(disparos, listaexplosiones);

	listaslime.mueve(0.025f, hombre);



	listabonus.mueve(0.025f);
	listabonus.Colision(limites);
	listabonus.Colision(plataformaprueba);


	////INTERACCIONES////

	//Interaccion::Colision(bonus1, limites);

	//Interaccion::Colision(slime, limites);
	plataformas.Colision(slime);

	listaslime.Colision(limites);
	listaslime.Colision(plataformas);

	//Interaccion::reboteinterior(hombre, limites);
	if (Interaccion::caida(hombre, limites) == 1)
		salto = 0;

	if (Interaccion::Colision(hombre, virus1)) {
		if (virus1.GetMuerto() == 0) {
			hombre.SetVidas(hombre.GetVidas() - 1);
		}
	}

	Bonus* auxBM = listabonus.colision(hombre);
	if (auxBM != 0) {
		if (hombre.GetVidas() <= 4) {
			hombre.SetVidas(hombre.GetVidas() + 1);
			listabonus.eliminar(auxBM);
		}
	}


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
			hombre.SetVidas(hombre.GetVidas() - 1);
			misiles.Eliminar(aux);
		}
		//misiles.Eliminar(aux);

	//misiles.Explota();
	}
	for (int t = 0; t < plataformas.GetNumero(); t++) {
		listabonus.Colision(*plataformas[t]);
	}

	Plataformas* auxPLAT = plataformas.ColisionSube(hombre);
	//ETSIDI::Vector2D poscaida = auxPLAT->GetLim2();
	//if (Interaccion::caida(hombre, limites) == 1) {
	//	if (hombre.GetPos().x > auxPLAT->GetLim2().x) {
	//		hombre.SetPos(auxPLAT->GetLim2().x-2, auxPLAT->GetLim2().y+4);
	//	}
	//}
	if (Interaccion::caida(hombre, limites) == 1) {

		hombre.SetPos(hombre.GetPos().x - 10, hombre.GetPos().y + 10);

		hombre.SetVel(0, 0);
		hombre.SetVidas(hombre.GetVidas() - 1);
	}

	misiles.limpiar();

}



int Mundo::Tecla(unsigned char key)
{	//NIVELES:	

	switch (pantalla) {
	case 0: //SI NO EST� NI MUERTO NI CON EL NIVEL ACABADO
		switch (key) {
		case 'm':
			virus2.Ataca();

			break;
		case 'n':
			virus3.dispara(listaslime);

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

		case 'j':

			listabonus.agregar(new BonusMascarilla(hombre.GetPos().x, 25, 1.5, 1.5));
			break;
		case 'x':
			//virus.Muere();

			misiles.Agregar(new Misil("imagenes/misilizq.png", 29, -2.0f, -5.0f, 0.0f));
			break;
			///////// TESTS DE VIDAS
		case 't':
			if (hombre.GetVidas() < 5) {
				/// radio, x , y, vx, vy
				hombre.SetVidas(hombre.GetVidas() + 1);
			}

			break;
		case 'y':
			if (hombre.GetVidas() > 0) {
				//hombre.vidas--; /// radio, x , y, vx, vy
				hombre.SetVidas(hombre.GetVidas() - 1);
			}
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

		break;
	case 1: //MUERE
		switch (key) {
		case '7': //VOLVER AL MENU PRINCIPAL
			level = 0;
			pantalla = 0;
			//NO SE USA EL hombre.FinPartida()  PORQUE ESTA ARRIBA AL TENER LEVEL==0
			disparos.DestruirContenido();
			return 0;
			break;
		case '8': //REINICIAR EL NIVEL
			level = 1;
			CargarNivel();
			pantalla = 0;
			disparos.DestruirContenido();
			break;
		}
		break;
	case 2: //GANADOR
		switch (key) {
		case '7':
			level = 0;
			pantalla = 0;
			disparos.DestruirContenido();
			return 0;
			break;
		case '8':
			level += 1;
			CargarNivel();
			pantalla = 0;
			disparos.DestruirContenido();
			break;

		}
		break;
	}
	entorno.Tecla(key);
}

void Mundo::teclaEspecial(unsigned char key) {
	//distancia = 0;
	// glutSetKeyRepeat(1);
	if (pantalla != 1 && pantalla != 2) {//para que no se mueva cuando esta en el menu
		switch (key)
		{
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
				virus3.dispara(listaslime);
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

		hombre.Setagachado( key);


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
//void Mundo::Interaccion() {
//	virus2.Ataca();
//}

int Mundo::ClickMouse(int b, int state, int x, int y) { //click del raton
	bool down = (state == GLUT_DOWN);
	//xmouse = (x - 400) / 13, 3; //coordinar con la x de nuestra pantalla
	//ymouse = -(y - 455) / 17.5 + 1; //coordinar con la y de niestra pantalla
	int button;
	if (level == 0) {
		disparos.DestruirContenido();
		if (b == GLUT_LEFT_BUTTON) {
			button = MOUSE_LEFT_BUTTON;

			if (y > 11 && y <= 13) {

				level = 1;
				tiempo = clock(); //para el tiempo
				return level;
			}
			else if (y > 9 && y <= 11) {

				level = 2;
				return level;
			}
			else if (y > 7 && y <= 9) {
				level = 3;
				return level;
			}
		}
	}

}


void Mundo::CargarNivel() {
	hombre.FinPartida();//REINICIA TODO LO DEL HOMBRE
	Setojo(0, 10, 53);
}



