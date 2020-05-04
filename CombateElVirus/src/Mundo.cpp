#pragma once
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include "Mundo.h"
#include "Interaccion.h"
#include "ListaDisparos.h"
#include <math.h>
#include "glut.h"



Mundo::Mundo(){
	 //ESTABA INICIALIZADO AQUI EL LEVEL. PERO TIENE QUE IR EN MENU.H 
	//Asi ya trabajamos como debería ser ;)

}
void Mundo::Setojo(float ox, float oy, float oz) {

	x_ojo = ox;
	y_ojo = oy;
	z_ojo = oz;
}
/*
//OJO
void Mundo::RotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}*/

void Mundo::Inicializa()
{
	lanzamisiles1.Inicializa();
	hombre.Inicializa();
	entorno.Inicializa(level);
	personajes.Inicializa(hombre);	
	
	virus.Inicializa("virusseta", 8, 1, 0, 0, 3, 3, 0, 0);
	limites.SetLimites(-20, 500, -3.5, 30); //Son los bordes del juego que el jugador no puede pasar
	
	vidas.Inicializa(hombre);
	
	plataformaprueba.Inicializa(0, 1, 8, 3);



	//bonus.SetPos(5.0f, 5.0f);
	//plataforma1.SetLimites(30, 60, 5, 10);//Los brdes de una plataforma
	//plataforma.SetColor(255, 0, 0);//plataforma.SetPos(70.0f, 9.0f, 80.0f, 9.0f);
	//disparo.SetPos(-5.0f, 0.0f);
	//disparo.SetOri(-5.0f, 0.0f);
	/*vida1.Inicializa(hombre,15,20);
	vida2.Inicializa(hombre,19, 20);
	vida3.Inicializa(hombre,23,20);
	vida4.Inicializa(hombre,27, 20);
	vida5.Inicializa(hombre,30, 20);*/
	//misiles.Inicializa();
	//misilizq.Inicializa();
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
	////zapatos.Inicializa(hombre);
	
}
void Mundo::Dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,
		x_ojo, y_ojo, 0.0, //NOTESE QUE HEMOS CAMBIADO ESTO
		0.0, 5.0, 0.0); //PARA MIRAR AL CENTRO DE LA ESCENA
	
	entorno.Dibuja(level);
	limites.Dibuja();

	if (level !=0) {
		
		glPushMatrix();//guarda la matriz
	
		glColor3f(0, 0, 1);
		glutSolidSphere(0.2,15,15); //dibuja la esfera solida
		glColor3f(0, 0, -1);
		
		glPopMatrix();//la guarda y la restaura

		hombre.Dibuja();
		personajes.Dibuja(level, hombre);		
		disparos.Dibuja();
		misiles.Dibuja();
		lanzamisiles1.Dibuja();

		virus.Dibuja(level);
		//plataformas.Dibuja(); PRUEBA
		plataformaprueba.Dibuja();

		vidas.Dibuja(hombre.GetVidas());		
		bordessube.Dibuja();
		listavirus.dibuja();
		zapatos.Dibuja(hombre);

		int naleatorio = lanzaDado(1000);
		if (naleatorio < 10) {
			misiles.Agregar(new Misil("imagenes/misilizq.png", 15, -3.0f, -5.0f, 0.0f));
		}
		//plataformas.Agregar(new Plataformas(10, 1, 20, 1.25));
		//plataformas.Agregar(new Plataformas(25, 3, 35, 3.25));

		 //FIN DE PARTIDA
		if (hombre.GetVidas() == 0 ) { //con un || pondría aqui cuando se acaba el nivel 
			// habría que poner con un contador de esos un tiempo para que se viera que el sprite cambia a muerto y cae al vacio)
			while (finde==1) { 
				hombre.SetVel(0, 0);
				hombre.SetAceleracion(0, -10);					
			}
			finde = 0;
			hombre.FinPartida();
			level = 0;
			Setojo(0, 10, 53);	
			
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
	}
}


void Mundo::Mueve()
{
	//esto es para cuando acaba la partida que durante 2s se congele la imagen, no se como hacerlo la verdad el getMillis
	/*if (hombre.GetVidas() == 0) {
		while (getMillis() <= 2000) {
			finde= 1;
		}
	}*/
	//OJO//
	
	if (hombre.posicion.x > 0 && level!=0) ////Necesitamos algo mas elegante
		Setojo(hombre.posicion.x, 10, 53);
	else
		Setojo(0, 10, 53);
	

	//.Mueve//

	personajes.Mueve(0.025f);
	virus.Mueve(0.025f, hombre);
	hombre.Mueve(0.025f);
		 	
	disparos.Mueve(0.025f);
	misiles.Mueve(0.025f);
	vidas.Mueve(x_ojo);
	listavirus.mueve(0.025f, hombre);
	//zapatos.Mueve(0.025f, hombre);
	//disparo.Mueve(0.025f);
	//bonus.Mueve(0.025f);

	////INTERACCIONES////
	if (finde != 1) {
		Interaccion::reboteinterior(hombre, limites);
	}

	if (Interaccion::Colision(hombre, virus)) {
		
		hombre.SetVidas(hombre.GetVidas() - 1);
	}
	
	if (Interaccion::Colision(hombre, plataformaprueba)) {

		plataformaprueba.aux = 1;	
	
	}
	else {
		plataformaprueba.aux = 0;
	}

	if (salto == 1) {
		hombre.SetVel(hombre.GetVel().x, +18);
		salto = 0;
	}


	//IMPORTANTE//Interaccion::reboteexterior(hombre, plataforma1);
	//Interaccion::colision(misiles, hombre); /// no funciona


	//Colision virus con disp	
	if (disparos.Colision(virus)) {//si alguna esfera ha chocado
		virus.Muere();
		

	}		//disparo.eliminar(aux7);	

	///////// misil-hombre
	Misil* aux = misiles.colision(hombre);
	if (aux != 0) {
		hombre.SetVidas(hombre.GetVidas() - 1);
		misiles.Eliminar(aux);
		//misiles.Explota();
	}

	//////interacciones con plataforma -BASURA

	/*  Plataformas* aux2 = plataformas.Colision(hombre);

	if (aux2 != 0) {


		/*plataformas.Agregar(new Plataformas(10, 3, 15, 3.5));
		hombre.SetVel(hombre.GetVel().x, 0.0);
		hombre.SetAceleracion(0.0, -20.0);*/
	//}



	////////	TEMPORIZADOR	//////
/*
	Plataformas* aux1 = plataformas.Colision(zapatos);

	if (aux1 != 0) {
		if (salto == 0) {
			//plataformas.Agregar(new Plataformas(10, 3, 15, 3.5));
			hombre.SetVel(hombre.GetVel().x, 0.0);
			hombre.SetAceleracion(0.0, 0.0);

		}

	}
	else if (aux1 == 0) {

		hombre.SetAceleracion(0.0, -20.0);

	}
	*/
	
	/*switch (salto) {
	case 1:
		if (Interaccion::colision(hombre, limites) == 1 || aux1 != 0) {
			hombre.SetVel(hombre.GetVel().x, 18.0f);
			//zapatos.SetPos(zapatos.GetPos().x, zapatos.GetPos().y+0.5);
			hombre.SetAceleracion(0.0, 0.0);
			salto = 0;
		}
		
	}

*/
	///////colision hombre-virus

	/*Virus* auxv = listavirus.Colision(hombre);
	if (auxv != 0) {
		listavirus.eliminar(auxv);
		hombre.SetVidas(hombre.GetVidas() - 1);
	}*/

	//Misil* auxm = misiles.colision(hombre);

	//if (auxm != 0) {
	//	misiles.Eliminar(auxm);
	//	hombre.SetVidas(hombre.GetVidas() - 1);
	//}
}



void Mundo::Tecla(unsigned char key)
{	
	if (level == 0) {
		switch (key) {
		case '1':
			level = 1;
			break;
		case '2':
			level = 2;
			break;
		case '3':
			level = 3;
			break;
		}
	}
	entorno.Tecla(key);
	if (level != 0) {//para que no dispare mientras estemos en el nivel 0 
		switch (key) {

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
			virus.Muere();
			break;
		case 'x':
			//virus.Muere();
			
			misiles.Agregar(new Misil("imagenes/misilizq.png", 15, -3.0f, -5.0f, 0.0f));
			break;
			///////// TESTS DE VIDAS
		case 't':
			if (hombre.GetVidas()< 5) {
				 /// radio, x , y, vx, vy
				hombre.SetVidas(hombre.GetVidas() +1);
			}

			break;
		case 'y':
			if (hombre.GetVidas()> 0) {
				//hombre.vidas--; /// radio, x , y, vx, vy
				hombre.SetVidas(hombre.GetVidas() - 1);
			}
			break;
			///test
		case ' ':
			hombre.SetVel(0, hombre.velocidad.y);
			//hombre.SetDir(0);
			int i = 0;
			//misiles.DestruirContenido(i);
			i++;
			break;

		
		}
	}
}

void Mundo::teclaEspecial(unsigned char key) {
	//distancia = 0;
	 glutSetKeyRepeat(1);
	if (level != 0) {//para que no se mueva cuando esta en el menu
		switch (key)
		{
		case GLUT_KEY_LEFT:

			hombre.SetVel(-6, hombre.velocidad.y);
			//HAY QUE PONER QUE CUANDO ESTE EN EL AIRE NO VAYA HACIA LA DERECHA
			hombre.SetDir(2);

			break;
		case GLUT_KEY_RIGHT:
			hombre.SetVel(+6, hombre.velocidad.y);
			hombre.SetDir(1);

			break;
		case GLUT_KEY_UP:
			salto = 1;
				break;
			}

		}



}
//void Mundo::MyMouse(int button, int state, int x, int y){
//	switch (button) {
//	case GLUT_LEFT_BUTTON:
//		level = 1;
//	}
//}




