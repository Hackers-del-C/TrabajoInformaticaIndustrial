#include "Personajes.h"
#include "ETSIDI.h"
#include "glut.h"

Personajes::Personajes() {

}
Personajes:: ~Personajes() {

}
void Personajes::Inicializa(Hombre h) {
//	hombre.Inicializa();

	virus.Inicializa("trump", 6, 1, 4, 4, 3, 3, 1, 0);
	amigo.Inicializa();

	amigo.SetAceleracion(h.GetAceleracion().x);
	amigo.SetVel(h.GetVel().x);
}
void Personajes::Dibuja(int nivel,Hombre h) {
	//hombre.Dibuja(nivel);
	virus.Dibuja(nivel);
	
	amigo.Dibuja(h);
	amigo.Mensajes();
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
