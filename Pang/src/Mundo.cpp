#include "Mundo.h"
#include "Esfera.h"
#include <math.h>
#include "ETSIDI.h"
#include "glut.h"



void Mundo::RotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}
void Mundo::Dibuja()
{
	
	gluLookAt(x_ojo, y_ojo, z_ojo,
		0.0, y_ojo, 0.0, //NOTESE QUE HEMOS CAMBIADO ESTO
		0.0, 1.0, 0.0); //PARA MIRAR AL CENTRO DE LA ESCENA
	esfera.Dibuja();
	caja.Dibuja();
	hombre.Dibuja();
	disparo.Dibuja();
	plataforma.Dibuja();
	bonus.Dibuja();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/banana.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	
	glTexCoord2d(0, 1); glVertex3f(-10, 0, -0.1);
	glTexCoord2d(1, 1); glVertex3f(+10, 0, -0.1);
	glTexCoord2d(1, 0); glVertex3f(10, 15, -0.1);
	glTexCoord2d(0, 0); glVertex3f(-10, 15, -0.1);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);


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
	hombre.Mueve(0.025f);
	esfera.Mueve(0.025f);
	bonus.Mueve(0.025f);
	disparo.Mueve(0.025f);

}

void Mundo::Inicializa()
{
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;
	esfera.SetPos(2, 4);
	esfera.SetRadio(1.5f);
	esfera.SetColor(0, 0, 255);
	bonus.posicion.x = 5.0f;
	bonus.posicion.y = 5.0f;

	disparo.posicion.x = -5.0f;
	disparo.posicion.y = 0.0f;
	disparo.origen.y = 0.0f;
	disparo.origen.x = disparo.posicion.x;

	/* Se podria poner asi, si se hace en la funcion Tecla para que cuando se pulse el disparo salga desde esa posicion
	disparo.origen.y = disparo.posicion.y;
	disparo.origen.x = disparo.posicion.x;
	*/

	plataforma.SetColor(255, 0, 0);

	plataforma.limite1.x = -5.0f;
	plataforma.limite2.x = 5.0f;
	plataforma.limite1.y = 9.0f;
	plataforma.limite2.y = 9.0f;
}

void Mundo::Tecla(unsigned char key)
{



}
