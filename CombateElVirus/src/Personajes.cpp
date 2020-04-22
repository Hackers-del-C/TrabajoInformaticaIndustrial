#include "Personajes.h"
#include "ETSIDI.h"
#include "glut.h"

Personajes::Personajes() {

}
Personajes:: ~Personajes() {

}
void Personajes::Inicializa() {
//	hombre.Inicializa();
	virus.Inicializa();
	
}
void Personajes::Dibuja(int nivel) {
//	hombre.Dibuja(nivel);
	virus.Dibuja(nivel);
}
void Personajes::Mueve(float t ) {
	virus.Mueve(t);
}
void Personajes::Tecla(unsigned char key) {

}
void Personajes::TeclaEspecial(unsigned char key) {

	}
