#pragma once
#include "Mundo.h"
#include "Interaccion.h"
#include "Esfera.h"
#include "ListaDisparos.h"
#include "Background.h"
#include <math.h>
#include "glut.h"


/*
void Mundo::RotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}*/
void Mundo::Dibuja()
{
	
	gluLookAt(x_ojo, y_ojo, z_ojo,
		x_ojo, y_ojo, 0.0, //NOTESE QUE HEMOS CAMBIADO ESTO
		0.0, 5.0, 0.0); //PARA MIRAR AL CENTRO DE LA ESCENA

	background.Dibuja();
	//esfera.Dibuja();
	caja.Dibuja();
	hombre.Dibuja(background.level);
	//disparo.Dibuja();
	plataforma.Dibuja();
	//bonus.Dibuja();
	//esfera2.Dibuja();
	background.Dibuja();
	

	disparos.Dibuja();

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
void Mundo::Setojo(float ox, float oy, float oz) {

	x_ojo = ox;
	y_ojo = oy;
	z_ojo = oz;
}

void Mundo::Mueve()
{
	hombre.Mueve(0.025f);
	esfera.Mueve(0.025f);
	bonus.Mueve(0.025f);
	//disparo.Mueve(0.025f); 

	esfera2.Mueve(0.025f);
	background.Mueve(0.025f);
	disparos.Mueve(0.025f);

	Interaccion::reboteinterior(hombre, caja);
	Interaccion::reboteexterior(hombre, plataforma1);
	Interaccion::rebote(esfera, caja);
	Interaccion::rebote(esfera, plataforma);
	Interaccion::rebote(esfera2, caja);
	Interaccion::rebote(esfera2, plataforma);
	
	
	Setojo(hombre.posicion.x, 10, 53);
}

void Mundo::Inicializa()
{	
	

	esfera.SetColor(0, 0, 255);
	esfera.SetRadio(1.5f);
	esfera.SetPos(2, 4);
	esfera.SetVel(5, 15);
	esfera2.SetRadio(2);
	esfera2.SetPos(-2, 4);
	esfera2.SetVel(-5, 15);
	bonus.SetPos(5.0f, 5.0f);
	//disparo.SetPos(-5.0f, 0.0f);
	//disparo.SetOri(-5.0f, 0.0f);
	plataforma.SetColor(255, 0, 0);
	plataforma.SetPos(70.0f, 9.0f, 80.0f, 9.0f);
	background.Inicializa();
	hombre.Inicializa();

	caja.SetCaja(-20, 220, -5, 30); //Son los bordes del juego que el jugador no puede pasar
	plataforma1.SetCaja(30, 60, 5, 10);//Los brdes de una plataforma

	
	/*
	disparo.origen.y = 0.0f;
	disparo.origen.x = -5.0f;

	 Se podria poner asi, si se hace en la funcion Tecla para que cuando se pulse el disparo salga desde esa posicion
	disparo.origen.y = disparo.posicion.y;
	disparo.origen.x = disparo.posicion.x;
	*/

}

void Mundo::Tecla(unsigned char key)
{
	background.Tecla(key);
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
	if (hombre.posicion.x < 190) { //QUITAR ESTE IF CUANDO SE PUEDA
		switch (key)
		{
		case GLUT_KEY_LEFT:
			hombre.SetVel(-6, hombre.velocidad.y);   //HAY QUE PONER QUE CUANDO ESTE EN EL AIRE NO VAYA HACIA LA DERECHA
			hombre.dir = 2;

			break;
		case GLUT_KEY_RIGHT:
			hombre.SetVel(+6, hombre.velocidad.y);
			hombre.dir = 1;
			
			break;
		case GLUT_KEY_UP:
			if(1){ //HAY QUE PONER QUE NO SALTE DOS VECES PERO NO ME VA BIEN
			hombre.Salta();
			}
			break;

		}
	if (hombre.posicion.x>=190) { //el plan era como parar el muñeco en 190 pero no va
		hombre.SetVel(0, 0);
	}
	}
	
	
	
}
