#pragma once
#include "Mundo.h"
#include "Interaccion.h"
#include "ListaDisparos.h"
#include <math.h>
#include "glut.h"

void Mundo::Inicializa()
{
	entorno.Inicializa(level);


	bonus.SetPos(5.0f, 5.0f);
	//disparo.SetPos(-5.0f, 0.0f);
	//disparo.SetOri(-5.0f, 0.0f);
	plataforma.SetColor(255, 0, 0);
	plataforma.SetPos(70.0f, 9.0f, 80.0f, 9.0f);
	
	hombre.Inicializa();

	limites.SetLimites(-20, 220, -5, 30); //Son los bordes del juego que el jugador no puede pasar
	plataforma1.SetLimites(30, 60, 5, 10);//Los brdes de una plataforma
	lanzamisiles1.Inicializa();
	misilder.Inicializader();
	misilizq.Inicializaizq();
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

	hombre.Dibuja(level);
	//disparo.Dibuja();
	plataforma.Dibuja();
	//bonus.Dibuja();
	disparos.Dibuja();
	lanzamisiles1.Dibuja();
	misilder.Dibujader();
	misilizq.Dibujaizq();
	//aqui es donde hay que poner el codigo de dibujo
	/*
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
		glColor3ub(255,0,0);
		glVertex3f(-5.0f,0,-5.0f);
		glVertex3f(-5.0f,0,5.0f);
		glColor3ub(255,255,0);
		glVertex3f(5.0f,0,5.0f);
		glVertex3f(5.0f,0,-5.0f);
	glEnd();
	glEnable(GL_LIGHTING);
	*/
}


void Mundo::Mueve()
{

	entorno.Mueve(0.025f);


	hombre.Mueve(0.025f);
	bonus.Mueve(0.025f);
	//disparo.Mueve(0.025f); 	
	disparos.Mueve(0.025f);
	 //INTERACCIONES
	misilder.Mueveder(0.025f);
	misilizq.Mueveizq(0.025f);
	misilder.SetVel(5.0f);
	misilizq.SetVel(-5.0f);
	Interaccion::reboteinterior(hombre, limites);
	Interaccion::reboteexterior(hombre, plataforma1);
	//Interaccion::rebote(esfera, caja);
	//Interaccion::rebote(esfera, plataforma);
	//Interaccion::rebote(esfera2, caja);
	//Interaccion::rebote(esfera2, plataforma);
	
	
	Setojo(hombre.posicion.x, 10, 53);
}



void Mundo::Tecla(unsigned char key)
{
	entorno.Tecla(key);
	switch (key) {
	
	case 'w':
		disparos.Agregar(new Disparo(0.5, hombre.posicion.x, hombre.posicion.y, 0.0f, 22.0f));
		break;

	case 's':
		disparos.Agregar(new Disparo(0.5, hombre.posicion.x, hombre.posicion.y, 0.0f, -22.0f));
		break;

	case 'a':
		disparos.Agregar(new Disparo(0.5, hombre.posicion.x, hombre.posicion.y, -22.0f, 0.0f));
		break;

	case 'd':
		disparos.Agregar(new Disparo(0.5, hombre.posicion.x, hombre.posicion.y, 22.0f, 0.0f));
		break;

	}
}

void Mundo::teclaEspecial(unsigned char key){
	int salto = 0;
	if (hombre.posicion.x < 190) { //QUITAR ESTE IF CUANDO SE PUEDA
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
			salto = 1;
			if (salto == 1) {
				if (1) { //HAY QUE PONER QUE NO SALTE DOS VECES PERO NO ME VA BIEN
					//hombre.Salta();
					hombre.SetVel(hombre.velocidad.x, 15.0f);
				}
				salto = 0;
			}
			break;

		}
	if (hombre.posicion.x>=190) { //el plan era como parar el muñeco en 190 pero no va
		hombre.SetVel(0, 0);
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

