#pragma once
#include <stdlib.h>
#include <glut.h>
#include "Coordinador.h"
Coordinador::Coordinador() {

	estado = MENU;
	nivel = 0;
}
Coordinador::~Coordinador() {

}
void Coordinador::Inicializa() {
		mundo.RecargarNivel(); //RESETEA HOMBRE Y DESTRUYE ALGUNAS LISTAS PERO NO SE
		mundo.Inicializa(nivel);
		
		if (estado == MUERTE)		{
			entorno.Fin(MUERTE);
		}
		else if (estado == GANAR) {
			entorno.Fin(GANAR);
		}
}
void Coordinador::Mueve() {
	if(estado==JUEGO)
		mundo.Mueve(nivel);
}
void Coordinador::Dibuja() {
	mundo.InicioDibuja(); //ES EL OJO 
	
	if (estado == JUEGO) {
		mundo.Dibuja(nivel);
		mundo.InicializaFondo(nivel);
	}
	else if (estado == MENU)
		entorno.DibujaMenu(xmouse, ymouse);

	else if(estado==MUERTE){
		mundo.Aviso(1);
	}
	else if (estado == GANAR) {
		mundo.Aviso(2);
	}
	else if (estado == JUEGO) {
		if (mundo.Muerte()) {
			estado = MUERTE;
			mundo.Aviso(1);
		}
		else if (mundo.Ganar()) {
			estado = GANAR;
			mundo.Aviso(2);
		}
	}
}
void Coordinador::tecla(unsigned char key) {
	if (estado == JUEGO) {
		mundo.Tecla(key);
		if (key == 'p') {
			estado = PAUSA;
			mundo.Dibuja(nivel);		
		}
	}
	else if (estado == MUERTE) {
		switch (key) {
		case '7': //VOLVER AL MENU PRINCIPAL
			estado = MENU;
			mundo.RecargarNivel();
			break;
		case '8': //REINICIAR EL NIVEL
			estado = JUEGO;
			mundo.RecargarNivel();
			break;
		}
	}
	else if (estado == GANAR) {
		switch (key) {
		case '7':
			estado = MENU;
			mundo.RecargarNivel();
			break;
			break;
		case '8':
			estado = JUEGO;
			nivel += 1;
			mundo.RecargarNivel();
			break;
		}				
	}
	else if (estado == PAUSA) {
		if (key == 'c') {
			mundo.Dibuja(nivel);
			estado = JUEGO;
		}
	}
	/*else if (mundo.Tecla(key)==0) {
		estado = MENU;
	}*/
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
	bool down = (state == GLUT_DOWN);
	int button;
	if (estado == MENU) {
		if (b == GLUT_LEFT_BUTTON) {
			button = MOUSE_LEFT_BUTTON;

			if (ymouse > 11 && ymouse <= 13) {
				nivel = 1;
				estado = JUEGO;
				mundo.RecargarNivel();
			}
			else if (ymouse > 9 && ymouse <= 11) {
				nivel = 2;
				estado = JUEGO;
				mundo.RecargarNivel();
			}
			else if (ymouse > 7 && ymouse <= 9) {
				nivel = 3;
				estado = JUEGO;
				mundo.RecargarNivel();
			}
		}
	}
	
}
void Coordinador::MyMouse(int x, int y) {
	cout << "(" << xmouse << "," << ymouse << ")" << endl; //borrar futuro
	xmouse = (x - 400) / 13, 3; //coordinar con la x de nuestra pantalla
	ymouse = -(y - 455) / 17.5 + 1; //coordinar con la y de niestra pantalla
}
