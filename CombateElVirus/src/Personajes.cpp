#include "Personajes.h"
#include "ETSIDI.h"
#include "glut.h"

Personajes::Personajes() {

}
Personajes:: ~Personajes() {

}
void Personajes::Inicializa() {
	
	jugador.Salta();
}
void Personajes::Dibuja(int level) {
	jugador.Dibuja(level);
}
void Personajes::Mueve(int level) {
	jugador.Mueve(level);
}
void Personajes::Tecla(unsigned char key) {

}
void Personajes::TeclaEspecial(unsigned char key) {
	

	}
