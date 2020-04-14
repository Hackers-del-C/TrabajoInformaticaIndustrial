#include "Background.h"
#include "glut.h"
#include "ETSIDI.h"

void Background::SetEscenario(float x) {
	if (x < 60) {
		Escenario = 1;
	}
	else if (60 <= x < 90) {
		Escenario = 2;
	}
	switch (Escenario) {

	case 1:
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo1.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);

		glTexCoord2d(0, 1);		glVertex3f(x - 30, -30, -0.1);//ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
		glTexCoord2d(1, 1);		glVertex3f(x + 32, -30, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(x + 32, 20, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(x - 30, 20, -0.1);
		glEnd();
		break;
	case 2:
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo2.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);

		glTexCoord2d(0, 1);		glVertex3f(x - 30, -30, -0.1);//ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
		glTexCoord2d(1, 1);		glVertex3f(x + 32, -30, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(x + 32, 20, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(x - 30, 20, -0.1);
		glEnd();
		break;
	}

}
void Background::Dibuja() {


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
	
	glTranslated(5, 0, 0);
	trump->draw();

	glTranslated(5, 0, 0);
	trump->draw();
	glTranslatef(-35, +10, 0);
	banderachina->draw();

	//pato->draw();

	glTranslated(10, -10, 0);
	ninja->draw();
	glTranslated(-10, 10, 0);
	
	
	/*
	//IMAGEN 1//
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo1.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);

	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);		glVertex3f(-30, -20, -0.1);//ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
	glTexCoord2d(1, 1);		glVertex3f(30, -20, -0.1);
	glTexCoord2d(1, 0);		glVertex3f(30, 20, -0.1);
	glTexCoord2d(0, 0);		glVertex3f(-30, 20, -0.1);
	glEnd();

	//IMAGEN 2//
	
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);



	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo2.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);

	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);		glVertex3f(30, -20, -0.1); //ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.

	glTexCoord2d(1, 1);		glVertex3f(90, -20, -0.1);
	glTexCoord2d(1, 0);		glVertex3f(90, 20, -0.1);
	glTexCoord2d(0, 0);		glVertex3f(30, 20, -0.1);
	glEnd();

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	
	
	*/
	//TEXTO //
	glTranslatef(-20, 8, 0);
	setTextColor(1, 1, 1); //FUNCIONA IGUAL QUE GLUT PERO EN VEZ DE 0-255 DE 0-1
	print("NIVEL 1", "fuentes/Bitwise.ttf", 36);
	setTextColor(1, 1, 1);//Tiene capacidad para un nº mas pero no se pa que sirve
	glTranslated(1, -2, 0); //Como se mueve respecto al texto anterior
	print("CHINA", "fuentes/Bitwise.ttf", 40);
	///////////////////////////////////////////////
}
void Background::Inicializa() {

	////// MUSICAAA/////

	//ETSIDI::playMusica("mis_sonidos/i_need_a_hero.mp3",true);
	//ETSIDI::playMusica("mis_sonidos/dont_stop_me_now.mp3", true);
	//ETSIDI::playMusica("mis_sonidos/all_shook_up.mp3", true);
	//ETSIDI::playMusica("mis_sonidos/España.mp3", true); // ESTE SERIA EL DE ESPAÑA VALE?

	ETSIDI::playMusica("mis_sonidos/China.mp3", true);

	//
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
	ninja = new SpriteSequence("imagenes/ninja.png", 5, 11, 200, true, 0, 0, 3, 3);

	banderachina = new SpriteSequence("imagenes/banderachina.png", 1, 1, 200, true, -4, 8, 8, 5);
	//ninja->setState(2, 2);

}
void Background::Mueve(float t) {
	explosion->loop();
	trump->loop();
	virus->loop();
	ninja->loop();
}
void Background::Tecla(unsigned char key) {

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