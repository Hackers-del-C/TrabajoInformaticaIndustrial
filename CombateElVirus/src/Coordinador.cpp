#pragma once

#include "Coordinador.h"
Coordinador::Coordinador() {
	level = 0;
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
	if(level==0)
		entorno.DibujaMenu(xmouse,ymouse);
}
void Coordinador::tecla(unsigned char key) {
	level=mundo.Tecla(key);
}
void Coordinador::teclaEspecial(unsigned char key) {
	mundo.teclaEspecial(key);
}
void Coordinador::teclaEspecialsuelta(unsigned char key) {
	mundo.teclaEspecialsuelta(key);
}
void Coordinador:: ClickMouse(int b, int state) {
	level=mundo.ClickMouse(b, state,xmouse,ymouse);
}
void Coordinador::MyMouse(int x, int y) {
	cout << "(" << xmouse << "," << ymouse << ")" << endl; //borrar futuro
	xmouse = (x - 400) / 13, 3; //coordinar con la x de nuestra pantalla
	ymouse = -(y - 455) / 17.5 + 1; //coordinar con la y de niestra pantalla
}
