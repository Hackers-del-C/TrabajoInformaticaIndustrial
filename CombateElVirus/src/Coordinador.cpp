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
	entorno.Inicializa(nivel);
	mundo.Inicializa(nivel);
	mundo.Setojo(0, 10, 53);

		if (estado == JUEGO) {
			
			/*mundo.Inicializa(nivel);
			mundo.RecargarNivel();*/ //RESETEA HOMBRE Y DESTRUYE ALGUNAS LISTAS 
		}
		else if (estado == MUERTE)		{
			entorno.Fin(MUERTE);
		}
		else if (estado == GANAR) {
			entorno.Fin(GANAR);
		}
}
void Coordinador::Mueve() {
	if (estado == JUEGO ) { 
		mundo.Mueve(nivel);
	}
	else if (estado == GANAR || estado == MUERTE) {
		mundo.MueveHombre();
	}
}
void Coordinador::Dibuja() {
	mundo.InicioDibuja(); //ES EL OJO 
	
	if (estado == JUEGO) {
		mundo.Dibuja(nivel);
		mundo.DibujaBasico();
		mundo.InicializaFondo(nivel);
		entorno.DibujaJuego(nivel);
		if (mundo.Muerte()) {
			estado = MUERTE;			
		}
		else if (mundo.Ganar()) {
			estado = GANAR;			
		}
	}
	else if (estado == MENU) {
		entorno.DibujaMenu(xmouse, ymouse);
	
	}
	else if(estado==MUERTE){

		entorno.Aviso(1, mundo.GetHombrePos().x, mundo.GetHombrePos().y); // funciona pero se resetea la posicion del hombre 
		entorno.DibujaJuego(nivel); //funciona
		mundo.DibujaBasico();
		//mundo.InicializaFondo(nivel); creo que no hace falta
		
	}
	else if (estado == GANAR) {
		entorno.Aviso(2, mundo.GetHombrePos().x, mundo.GetHombrePos().y);
		entorno.DibujaJuego(nivel);
		mundo.DibujaBasico();
	}
	else if (estado == PAUSA) {
		entorno.Aviso(3, mundo.GetHombrePos().x, mundo.GetHombrePos().y);
		entorno.DibujaJuego(nivel);
		mundo.Dibuja(nivel);
		mundo.DibujaBasico();
		
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
			nivel = 0;
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
			nivel = 0;
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

			if (ymouse > 11.5 && ymouse <= 13) {
				nivel = 1;
				estado = JUEGO;
				mundo.RecargarNivel();
			}
			else if (ymouse > 9.5 && ymouse <= 11.5) {
				nivel = 2;
				estado = JUEGO;
				mundo.RecargarNivel();
			}
			else if (ymouse > 8 && ymouse <= 9.5) {
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
