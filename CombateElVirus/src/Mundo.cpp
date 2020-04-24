#pragma once
#include "Mundo.h"
#include "Interaccion.h"
#include "ListaDisparos.h"
#include <math.h>
#include "glut.h"

Mundo::Mundo(){
	level = 0;
}
void Mundo::Inicializa()
{
	if (level == 0) {
		level=menu.GetLevel();
	}
	entorno.Inicializa(level);
	personajes.Inicializa();

	bonus.SetPos(5.0f, 5.0f);
	//disparo.SetPos(-5.0f, 0.0f);
	//disparo.SetOri(-5.0f, 0.0f);
	plataforma.SetColor(255, 0, 0);
	plataforma.SetPos(70.0f, 9.0f, 80.0f, 9.0f);
	
	hombre.Inicializa();
	virus.Inicializa("trump");

	limites.SetLimites(-20, 500, -5, 30); //Son los bordes del juego que el jugador no puede pasar
	plataforma1.SetLimites(30, 60, 5, 10);//Los brdes de una plataforma
	lanzamisiles1.Inicializa();
	

	//misiles.Inicializa();

	//misilizq.Inicializa();
	/*
	disparo.origen.y = 0.0f;
	disparo.origen.x = -5.0f;

	 Se podria poner asi, si se hace en la funcion Tecla para que cuando se pulse el disparo salga desde esa posicion
	disparo.origen.y = disparo.posicion.y;
	disparo.origen.x = disparo.posicion.x;
	*/
	
}
void Mundo::Dibuja()
{

	gluLookAt(x_ojo, y_ojo, z_ojo,
		x_ojo, y_ojo, 0.0, //NOTESE QUE HEMOS CAMBIADO ESTO
		0.0, 5.0, 0.0); //PARA MIRAR AL CENTRO DE LA ESCENA

	entorno.Dibuja(level);
	limites.Dibuja();
	personajes.Dibuja(level);
	
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
	
	}
}


void Mundo::Mueve()
{

	entorno.Mueve(0.025f);
	personajes.Mueve(0.025f);
	virus.Mueve(0.025f);
	hombre.Mueve(0.025f);
	bonus.Mueve(0.025f);
	//disparo.Mueve(0.025f); 	
	disparos.Mueve(0.025f);
	misiles.Mueve(0.025f);
	 //INTERACCIONES
	
	//misilizq.Mueve(0.025f);
	
	Interaccion::reboteinterior(hombre, limites);
	Interaccion::reboteexterior(hombre, plataforma1);
	//Interaccion::rebote(esfera, caja);
	//Interaccion::rebote(esfera, plataforma);
	//Interaccion::rebote(esfera2, caja);
	//Interaccion::rebote(esfera2, plataforma);
	
	
	Setojo(hombre.posicion.x, 10, 53);

	if (virus.posicion.x+5 < hombre.posicion.x) {
		virus.velocidad.x = 3;
	}
	if (virus.posicion.x+5 > hombre.posicion.x) {
		virus.velocidad.x = -3;
	}
	
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
			misiles.Agregar(new Misil("imagenes/misilizq.png", lanzaDado(30, -10), -3.0f, -5.0f, 0.0f));
			//disparos.Agregar(new Disparo(0.5, hombre.posicion.x, hombre.posicion.y + 2, 0.0f, 22.0f));
			 //// x y vx vy
			break;
			//"imagenes/misilizq.png"
		case 's':
			disparos.Agregar(new Disparo(0.5, hombre.posicion.x, hombre.posicion.y+2, 0.0f, -22.0f)); /// radio, x , y, vx, vy
		
			break;

		case 'a':
			disparos.Agregar(new Disparo(0.5, hombre.posicion.x, hombre.posicion.y+2, -22.0f, 0.0f));
			break;

		case 'd':
			disparos.Agregar(new Disparo(0.5, hombre.posicion.x, hombre.posicion.y+2, 22.0f, 0.0f));
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

			 hombre.dir = 2;

			 break;
		 case GLUT_KEY_RIGHT:
			 hombre.SetVel(+6, hombre.velocidad.y);
			 hombre.dir = 1;

			 break;
		 case GLUT_KEY_UP:

			 if (salto >= 1 && salto < 3 && hombre.posicion.y == -5) {
				 salto += 1;
				 hombre.SetVel(hombre.velocidad.x, 15.0f);
				 /*distancia += 1;
				 if (distancia > 2) {
					 salto = 0;

					 break;
				 }*/

			 }
			 else if (salto == 3 && hombre.posicion.y == -5) {

				 hombre.SetVel(hombre.velocidad.x, 20.0f);
				 salto = 1;
			 }
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

