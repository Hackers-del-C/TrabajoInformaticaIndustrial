#include "Personajes.h"
#include "ETSIDI.h"
#include "glut.h"

Personajes::Personajes() {

}
Personajes:: ~Personajes() {

}
void Personajes::Inicializa() {
//	hombre.Inicializa();

	virus.Inicializa("trump");
	
	
}
void Personajes::Dibuja(int nivel) {
	//hombre.Dibuja(nivel);
	virus.Dibuja(nivel);
}
void Personajes::Mueve(float t ) {
	virus.Mueve(t);

	if (virus.posicion.x < hombre.posicion.x) {
		virus.velocidad.x = 5;
	}
	if (virus.posicion.x > hombre.posicion.x) {
		virus.velocidad.x = -5;
	}

}
void Personajes::Tecla(unsigned char key) {

}
void Personajes::TeclaEspecial(unsigned char key) {

	}
