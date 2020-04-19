#include "Entorno.h"
#include "glut.h"
#include "ETSIDI.h"

void Entorno::Dibuja() {

	/*
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


		glTranslated(10, -10, 0);
		ninja->draw();
		*/

	nivel.Escenario(level);

	nivel.Titulo(level);

}
void Entorno::Inicializa() {

	////// MUSICAAA/////

	nivel.Musica(level); //SOLO VA CON EL NIVEL 1

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


	//ninja->setState(2, 2);

}
void Entorno::Mueve(float t) {
	explosion->loop();
	trump->loop();
	virus->loop();
	ninja->loop();
}
void Entorno::Tecla(unsigned char key) {

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