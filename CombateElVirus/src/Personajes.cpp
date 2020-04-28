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
	amigo.Inicializa();
	amigo.SetAceleracion(hombre.aceleracion.x);
	amigo.SetVel(hombre.velocidad.x);
}
void Personajes::Dibuja(int nivel) {
	//hombre.Dibuja(nivel);
	virus.Dibuja(nivel);
	
	amigo.Dibuja(hombre.posicion.x,hombre.posicion.y,hombre.dir);
}
void Personajes::Mueve(float t ) {
	virus.Mueve(t);
	amigo.Mueve(t);
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
