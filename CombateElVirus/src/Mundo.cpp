#pragma once
#include "Mundo.h"
#include "Interaccion.h"
#include "Esfera.h"
#include "ETSIDI.h"
#include <math.h>
#include "glut.h"
// #include "Abascal.h"

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
		0.0, 2.0, 0.0); //PARA MIRAR AL CENTRO DE LA ESCENA
	esfera.Dibuja();
	caja.Dibuja();
	hombre.Dibuja();
	disparo.Dibuja();
	//plataforma.Dibuja();
	bonus.Dibuja();
	esfera2.Dibuja();
	glTranslated(0, 0, -10);
	explosion->draw();
	glTranslated(-10, -5, 0);
	virus->draw();
	glTranslated(15, 10, 0);
	ternerito->setSize(5, 5);
	ternerito->draw();
	glTranslated(3, 3, 0);
	sprite->setSize(5, 5);
	sprite->draw();
	glTranslated(20, -10, 0);
	trump->draw();
	glTranslated(5, 0, 0);
	trump->draw();
	glTranslated(5, 0, 0);
	trump->draw();
	glTranslated(5, 0, 0);
	trump->draw();
	glTranslated(-35, +10, 0);
	banderachina->draw();
	//pato->draw();
	glTranslated(10, -10, 0);
	ninja->draw();
	glTranslated(-10, 10, 0);
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo1.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);

	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);		glVertex3f(-30, -20, -0.1);
	glTexCoord2d(1, 1);		glVertex3f(10, -20, -0.1);
	glTexCoord2d(1, 0);		glVertex3f(10, 20, -0.1);
	glTexCoord2d(0, 0);		glVertex3f(-30, 20, -0.1);
	glEnd();

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo2.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);

	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);		glVertex3f(10, -20, -0.1);
	glTexCoord2d(1, 1);		glVertex3f(40, -20, -0.1);
	glTexCoord2d(1, 0);		glVertex3f(40, 20, -0.1);
	glTexCoord2d(0, 0);		glVertex3f(10, 20, -0.1);
	glEnd();

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	
	//TEXTO //
	glTranslatef(-18, 8, 0);
	setTextColor(1, 1, 1); //FUNCIONA IGUAL QUE GLUT PERO EN VEZ DE 0-255 DE 0-1
	print("NIVEL 1", "fuentes/Bitwise.ttf", 36);
	setTextColor(1, 1, 1);//Tiene capacidad para un nº mas pero no se pa que sirve
	glTranslated(1, -2, 0); //Como se mueve respecto al texto anterior
	print("CHINA", "fuentes/Bitwise.ttf", 40);
	///////////////////////////////////////////////

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
	disparo.Mueve(0.025f);
	esfera2.Mueve(0.025f);
	Interaccion::rebote(hombre, caja);
	Interaccion::rebote(esfera, caja);
	Interaccion::rebote(esfera, plataforma);
	Interaccion::rebote(esfera2, caja);
	Interaccion::rebote(esfera2, plataforma);
	explosion->loop();
	trump->loop();
	virus->loop();
	ninja->loop();
	//pato->loop();
	Setojo(hombre.posicion.x, 5, 30);
}

void Mundo::Inicializa()
{
	////// MUSICAAA/////

	//ETSIDI::playMusica("mis_sonidos/i_need_a_hero.mp3",true);
	//ETSIDI::playMusica("mis_sonidos/dont_stop_me_now.mp3", true);
	//ETSIDI::playMusica("mis_sonidos/all_shook_up.mp3", true);
	//ETSIDI::playMusica("mis_sonidos/España.mp3", true); // ESTE SERIA EL DE ESPAÑA VALE?

	ETSIDI::playMusica("mis_sonidos/China.mp3", true);

	//
	x_ojo = 10;
	y_ojo = 6;
	z_ojo = 0;
	esfera.SetColor(0, 0, 255);
	esfera.SetRadio(1.5f);
	esfera.SetPos(2, 4);
	esfera.SetVel(5, 15);
	esfera2.SetRadio(2);
	esfera2.SetPos(-2, 4);
	esfera2.SetVel(-5, 15);
	bonus.SetPos(5.0f, 5.0f);
	disparo.SetPos(-5.0f, 0.0f);
	disparo.SetOri(-5.0f, 0.0f);
	plataforma.SetColor(255, 0, 0);
	plataforma.SetPos(-5.0f, 9.0f, 5.0f, 9.0f);

	/*EXPLICACIÓN NUMEROS DE ESTA FUNCION DEL DEMONIO(CREO):
	1ºy 2º porción de la imagen que muestras???
	3º-> ni puta
	4º x
	5º y
	6º ancho
	7º alto
	*/
	explosion = new SpriteSequence("imagenes/explosion_43FR.png", 10, 4, 25, true, -2, 2, 5, 5);
	sprite = new Sprite("imagenes/banana.png", 0.05, 0.05, 10, 10);
	ternerito = new Sprite("imagenes/ternero.png", 0.05, 0.05, 10, 10);
	
	virus = new SpriteSequence("imagenes/virus1.png", 6, 4, 25, true, -2, 2, 5, 5);
	trump = new SpriteSequence("imagenes/trump.png", 6, 4, 25, true, -2, 2, 5, 5);

	//pato = new SpriteSequence("imagenes/pato.png", 2, 2, 25, true, -2, 2, 5, 5);
	ninja = new SpriteSequence("imagenes/ninja.png", 5, 11, 200, true, 0, 0,3,3);

	banderachina = new SpriteSequence("imagenes/banderachina.png", 1, 1, 200, true, -4, 8, 8,5);
	//ninja->setState(2, 2);


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
	
	if (key == 'a') {
		ETSIDI::play("mis_sonidos/alicates.wav");
		}
	if (key == 'b') {
		ETSIDI::play("mis_sonidos/imbatman.wav");
	}
	if (key == 'v') {
		ETSIDI::play("mis_sonidos/disparo.wav");
	}
}

void Mundo::teclaEspecial(unsigned char key)
{

	switch (key)
	{
	case GLUT_KEY_LEFT:
		hombre.SetVel(-6, 0);
	
		break;
	case GLUT_KEY_RIGHT:
		hombre.SetVel(+6, 0);
	
		break;
		
	}
	
}
