#include "Background.h"
#include "glut.h"
#include "ETSIDI.h"


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
	switch (level) {
	case 1:
		glTranslatef(-35, +10, 0);
		banderachina->draw();
		break;
	case 2:
		glTranslatef(-35, +10, 0);
		banderaitaliana->draw();
		break;
	case 3:
		glTranslatef(-35, +10, 0);
		banderaespa�ola->draw();
		break;
	}
	//pato->draw();

	glTranslated(10, -10, 0);
	ninja->draw();
	glTranslated(-10, 10, 0);
	
	nivel.Escenario(level);

	nivel.Titulo(level);
}
void Background::Inicializa() {

	////// MUSICAAA/////

	//ETSIDI::playMusica("mis_sonidos/i_need_a_hero.mp3",true);
	//ETSIDI::playMusica("mis_sonidos/dont_stop_me_now.mp3", true);
	//ETSIDI::playMusica("mis_sonidos/all_shook_up.mp3", true);
	//ETSIDI::playMusica("mis_sonidos/Espa�a.mp3", true); // ESTE SERIA EL DE ESPA�A VALE?

	//nivel.Musica(1);
	ETSIDI::playMusica("mis_sonidos/China.mp3", true);
	//
	/*EXPLICACI�N NUMEROS DE ESTA FUNCION DEL DEMONIO(CREO):
	1�y 2� porci�n de la imagen que muestras???
	3�-> ni puta
	4� x
	5� y
	6� ancho
	7� alto
	*/
	explosion = new SpriteSequence("imagenes/explosion_43FR.png", 10, 4, 25, true, -2, 2, 5, 5);
	sprite = new Sprite("imagenes/banana.png", 0.05, 0.05, 10, 10);
	ternerito = new Sprite("imagenes/ternero.png", 0.05, 0.05, 10, 10);

	virus = new SpriteSequence("imagenes/virus1.png", 6, 4, 25, true, -2, 2, 5, 5);
	trump = new SpriteSequence("imagenes/trump.png", 6, 4, 25, true, -2, 2, 5, 5);

	//pato = new SpriteSequence("imagenes/pato.png", 2, 2, 25, true, -2, 2, 5, 5);
	ninja = new SpriteSequence("imagenes/ninja.png", 5, 11, 200, true, 0, 0, 3, 3);

	banderachina = new SpriteSequence("imagenes/banderachina.png", 1, 1, 200, true, -4, 8, 8, 5);
	banderaitaliana= new SpriteSequence("imagenes/banderaitaliana.png", 1, 1, 200, true, -4, 8, 8, 5);
	banderaespa�ola = new SpriteSequence("imagenes/banderaespa�ola.png", 1, 1, 200, true, -4, 8, 8, 5);
	//ninja->setState(2, 2);

}
void Background::Mueve(float t) {
	explosion->loop();
	trump->loop();
	virus->loop();
	ninja->loop();
}
void Background::Tecla(unsigned char key) {

	if (key == 'b') {
		ETSIDI::play("mis_sonidos/imbatman.wav");
		
	}
	if (key == 'a' || key == 's' || key == 'w' || key == 'd') {
		ETSIDI::play("mis_sonidos/disparo.wav");
	}
	if (key == 'v') {
		ETSIDI::play("mis_sonidos/alicates.wav");
	}
	
}