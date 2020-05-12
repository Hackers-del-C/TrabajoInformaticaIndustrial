#pragma once

#include "Coordinador.h"
Coordinador::Coordinador() {
	level = 0;
	estado = MENU;
}
Coordinador::~Coordinador() {

}
void Coordinador::Inicializa() {

		mundo.Inicializa();
		mundo.InicializaFondo();
	
}
void Coordinador::Mueve() {
	if(estado==JUEGO)
		mundo.Mueve();
}
void Coordinador::Dibuja() {
	mundo.Dibuja();
	if(estado==MENU )//if(level==0)
		entorno.DibujaMenu(xmouse,ymouse);
}
void Coordinador::tecla(unsigned char key) {
	if (estado == JUEGO) {
		mundo.Tecla(key);
		if (key == 'p') {
			estado == PAUSA;
			mundo.Dibuja();
		
		}
	}
	if (estado == PAUSA) {
		if (key == 'c') {
			mundo.Dibuja();
			estado == JUEGO;
		}
	}
	else if (mundo.Tecla(key)==0) {
		estado = MENU;
	}
}
void Coordinador::teclaEspecial(unsigned char key) {
	if(estado==JUEGO)
		mundo.teclaEspecial(key);
}
void Coordinador::teclaEspecialsuelta(unsigned char key) {
	if (estado == JUEGO)
		mundo.teclaEspecialsuelta(key);
}
void Coordinador::ClickMouse(int b, int state) {
	if (mundo.ClickMouse(b, state, xmouse, ymouse)){
		estado = JUEGO;
	}
}
void Coordinador::MyMouse(int x, int y) {
	cout << "(" << xmouse << "," << ymouse << ")" << endl; //borrar futuro
	xmouse = (x - 400) / 13, 3; //coordinar con la x de nuestra pantalla
	ymouse = -(y - 455) / 17.5 + 1; //coordinar con la y de niestra pantalla
}
