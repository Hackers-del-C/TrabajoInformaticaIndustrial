#include "Personajes.h"
#include "ETSIDI.h"
#include "glut.h"

Personajes::Personajes() {

}
Personajes:: ~Personajes() {

}
void Personajes::Inicializa(float ax, float vx) {
//	hombre.Inicializa();

	virus.Inicializa("trump");
	amigo.Inicializa();
	amigo.SetAceleracion(ax);
	amigo.SetVel(vx);
}
void Personajes::Dibuja(int nivel,float posx,float posy, int dir) {
	//hombre.Dibuja(nivel);
	virus.Dibuja(nivel);
	
	amigo.Dibuja(posx,posy,dir);
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
