#pragma once

#include "Coordinador.h"
Coordinador::Coordinador() {
	
}
Coordinador::~Coordinador() {

}
void Coordinador::Inicializa() {
	mundo.Inicializa();
	mundo.InicializaFondo();
}
void Coordinador::Mueve() {
	mundo.Mueve();
}
void Coordinador::Dibuja() {
	mundo.Dibuja();
}
void Coordinador::tecla(unsigned char key) {
	mundo.Tecla(key);
}
void Coordinador::teclaEspecial(unsigned char key) {
	mundo.teclaEspecial(key);
}
void Coordinador::teclaEspecialsuelta(unsigned char key) {
	mundo.teclaEspecialsuelta(key);
}
void Coordinador:: ClickMouse(int b, int state) {
	mundo.ClickMouse(b, state);
}
void Coordinador::MyMouse(int x, int y) {
	mundo.MyMouse(x, y);
}
