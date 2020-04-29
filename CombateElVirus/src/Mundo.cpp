#pragma once
#include "Mundo.h"
#include "Interaccion.h"
#include "ListaDisparos.h"
#include <math.h>
#include "glut.h"

Mundo::Mundo(){
	level = 1;
}
void Mundo::Inicializa()
{
	if (level == 0) {
		level=menu.GetLevel();
	}
	entorno.Inicializa(level);
	personajes.Inicializa(hombre);

	bonus.SetPos(5.0f, 5.0f);
	//disparo.SetPos(-5.0f, 0.0f);
	//disparo.SetOri(-5.0f, 0.0f);
	plataforma.SetColor(255, 0, 0);
	plataforma.SetPos(70.0f, 9.0f, 80.0f, 9.0f);
	
	hombre.Inicializa();
	virus.Inicializa("trump",6,1,4,4,3,3,1,0);

	limites.SetLimites(-20, 500, -5, 30); //Son los bordes del juego que el jugador no puede pasar
	plataforma1.SetLimites(30, 60, 5, 10);//Los brdes de una plataforma
	lanzamisiles1.Inicializa();

	vidas.Inicializa(hombre);

	/*vida1.Inicializa(hombre,15,20);
	vida2.Inicializa(hombre,19, 20);
	vida3.Inicializa(hombre,23,20);
	vida4.Inicializa(hombre,27, 20);
	vida5.Inicializa(hombre,30, 20);*/
	//misiles.Inicializa();

	//misilizq.Inicializa();
	Virus* e1 = new Virus();
	e1->Inicializa("trump", 6, 1, 4, 4, 3, 3, 1, 0);
	listavirus.agregar(e1); 
	for (int i = 0; i < 5; i++)
	{
		Virus* aux = new Virus();
		aux->Inicializa("trump", 6, 1, 4+2*i, 4, 3, 3, 1, 0);
		listavirus.agregar(aux);
	}
	for (int i = 0; i < 5; i++)
	{
		Virus* aux = new Virus();
		aux->Inicializa("virusseta", 8, 1, -10 + 2.5 * i, 4, 2, 2, 0, 0);
		listavirus.agregar(aux);
	}
	
}
void Mundo::Dibuja()
{

	gluLookAt(x_ojo, y_ojo, z_ojo,
		x_ojo, y_ojo, 0.0, //NOTESE QUE HEMOS CAMBIADO ESTO
		0.0, 5.0, 0.0); //PARA MIRAR AL CENTRO DE LA ESCENA

	entorno.Dibuja(level);
	limites.Dibuja();
	personajes.Dibuja(level,hombre);
	
	//disparo.Dibuja();
	//plataforma.Dibuja();
	//bonus.Dibuja();
	disparos.Dibuja();

	misiles.Dibuja();
	lanzamisiles1.Dibuja();

	//misilizq.Dibuja();

	hombre.Dibuja(level);
	virus.Dibuja(level);
	
	int naleatorio = lanzaDado(1000);
	if (naleatorio < 10) {
		misiles.Agregar(new Misil("imagenes/misilizq.png", 15, -3.0f, -5.0f, 0.0f));
	}

	//hombre.SetVidas(4);
	vidas.Dibuja(hombre.GetVidas());
	//vidas.Dibuja(mascarillas);

	plataformas.Dibuja();
	bordessube.Dibuja();
	//disparos.Agregar(new Disparo(0.5, hombre.posicion.x, hombre.posicion.y + 2, 0.0f, 22.0f));
	
	plataformas.Agregar(new Plataformas(10, 1, 20, 1.5));
	bordessube.Agregar(new BordesSube(10, 1, 20, 1.5));

	plataformas.Agregar(new Plataformas(25, 3, 35, 2.5));
	

	listavirus.dibuja();

	
}


void Mundo::Mueve()
{

	entorno.Mueve(0.025f);
	personajes.Mueve(0.025f);
	virus.Mueve(0.025f, hombre);
	hombre.Mueve(0.025f);
	bonus.Mueve(0.025f);
	//disparo.Mueve(0.025f); 	
	disparos.Mueve(0.025f);
	misiles.Mueve(0.025f);

	vidas.Mueve(0.025f,hombre);

	 //INTERACCIONES
	
	//misilizq.Mueve(0.025f);
	
	Interaccion::reboteinterior(hombre, limites);
	Interaccion::reboteexterior(hombre, plataforma1);
	//Interaccion::rebote(esfera, caja);
	//Interaccion::rebote(esfera, plataforma);
	//Interaccion::rebote(esfera2, caja);
	//Interaccion::rebote(esfera2, plataforma);
	

	//Interaccion::colision(misiles, hombre); /// no funciona

	Setojo(hombre.posicion.x, 10, 53);


	//Necesitamos algo mas elegante

	
	
	Misil* aux = misiles.colision(hombre);
	if (aux != 0) {
		hombre.SetVidas(hombre.GetVidas() - 1);
		misiles.Eliminar(aux);
	}

	listavirus.mueve(0.025f, hombre);
}



void Mundo::Tecla(unsigned char key)
{
	if (level == 0) {
		menu.Tecla(key);
	}
	entorno.Tecla(key);
	if (level != 0) {//para que no dispare mientras estemos en el nivel 0 
		switch (key) {

		case 'w':
			disparos.Agregar(new Disparo(0.5, hombre.posicion.x, hombre.posicion.y + 2, 0.0f, 22.0f));
			

			break;
			
		case 's':
			disparos.Agregar(new Disparo(0.5, hombre.posicion.x, hombre.posicion.y+2, 0.0f, -22.0f)); /// radio, x , y, vx, vy
		
			break;

		case 'a':
			disparos.Agregar(new Disparo(0.5, hombre.posicion.x, hombre.posicion.y+2, -22.0f, 0.0f));
			break;

		case 'd':
			disparos.Agregar(new Disparo(0.5, hombre.posicion.x, hombre.posicion.y+2, 22.0f, 0.0f));
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
			int i = 0;
			misiles.DestruirContenido(i);
			i++;
			break;

		
		}
	}
}

void Mundo::teclaEspecial(unsigned char key){
	//distancia = 0;

	 if(level!=0){//para que no se mueva cuando esta en el menu
		 switch (key)
		 {
		 case GLUT_KEY_LEFT:

			 hombre.SetVel(-6, hombre.velocidad.y);
			 //HAY QUE PONER QUE CUANDO ESTE EN EL AIRE NO VAYA HACIA LA DERECHA

			 hombre.SetDir(2 );

			 break;
		 case GLUT_KEY_RIGHT:
			 hombre.SetVel(+6, hombre.velocidad.y);
			 hombre.SetDir(1);

			 break;
		 case GLUT_KEY_UP:
			 if (Interaccion::colision(hombre, limites)) {
				 hombre.SetVel(hombre.velocidad.x, 18.0f);

			 }

			 ///////////////////////////////*
			 /*
			 if (salto >= 1 && salto < 3 && hombre.posicion.y == -5) {
				 salto += 1;
				 hombre.SetVel(hombre.velocidad.x, 15.0f);
				 /*distancia += 1;
				 if (distancia > 2) {
					 salto = 0;

					 break;
				 }*/
			 /*
			 }
			 else if (salto == 3 && hombre.posicion.y == -5) {

				 hombre.SetVel(hombre.velocidad.x, 20.0f);
				 salto = 1;
			 }

			 */
			 ///////////7
			 break;
		 }

	}
	
	
	
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

void Mundo::Setojo(float ox, float oy, float oz) {

	x_ojo = ox;
	y_ojo = oy;
	z_ojo = oz;
}

