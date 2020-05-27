#include "Personajes.h"
#include "ETSIDI.h"
#include "glut.h"

// CLASE FESTIONA EL PERSONAJE AMIGO
Personajes::Personajes() {

}
Personajes:: ~Personajes() {

}
void Personajes::Inicializa(Hombre h) {
	amigo.Inicializa();
	amigo.SetAceleracion(h.GetAceleracion().x);
	amigo.SetVel(h.GetVel().x);
}
void Personajes::Dibuja(int nivel,Hombre h) {	
	amigo.Dibuja(h);
	amigo.Mensajes(nivel);
}
void Personajes::Mueve(float t ) {
	amigo.Mueve(t);
}
void Personajes::Tecla(unsigned char key) {

}
void Personajes::TeclaEspecial(unsigned char key) {

	}
