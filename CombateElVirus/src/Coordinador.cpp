#pragma once
#include <stdlib.h>
#include <glut.h>
#include "Coordinador.h"
Coordinador::Coordinador() {
	estado = MENU;
	nivel = 0;
	AvanceNivel = 0;
	aux = 0;//para resetear la musica
	aux2 = 0; //para usar flechas en el menu
}
Coordinador::~Coordinador() {

}
void Coordinador::Inicializa() {
	mundo.Inicializa(nivel);
	mundo.Setojo(0, 10, 53);
	avion = *new Avion(260, -4);
	
	//son simplemente musica. 
		if (estado == JUEGO) {
			
		}
		else if (estado == MUERTE)		{
			entorno.Fin(MUERTE);
		}
		else if (estado == GANAR) {
			
			entorno.Fin(GANAR);
			
			
		}
		else if (estado == MENU) {
			aux = 1;
		}
}
void Coordinador::Mueve() {
	if (estado == JUEGO ) { 
		mundo.Mueve(nivel);
	}
	else if (estado == GANAR || estado == MUERTE) {
		mundo.MueveHombre(); // asi cuando se gana o se muere lo dem�s se para (tampoco se dibuja pero asi nos ahorramos memoria)
		avion.Mueve(0.025f);
	}
}
void Coordinador::Dibuja() {
	mundo.InicioDibuja(); //ES EL OJO. Va fuera  para que no de problemas 
	
	if (estado == JUEGO) {		
		entorno.DibujaJuego(nivel);
		mundo.Dibuja(nivel);
		mundo.DibujaBasico();
		//MUSICA:
		if (aux == 1) {
			entorno.Musica(nivel); aux = 0;
		}
		if (mundo.Muerte()) {
			estado = MUERTE;
			int a = 0;
			if (a == 0) { entorno.Fin(1); a = 1; } //para que no entre bucle y se reproduzca una vez
			//if (mundo.gettiempo() != -1000) { mundo.fichero(nivel); }

		}
		else if (mundo.Ganar()) {
			avion.posicion.x = 260;
			avion.posicion.y = -4;
			estado = GANAR;		
			int b = 0;
			if (b == 0) { entorno.Fin(2); b = 1; }//para que no entre bucle y se reproduzca una vez
		}
	}
	else if (estado == MENU) {
		entorno.DibujaMenu(xmouse, ymouse,aux2,AvanceNivel);
		mundo.RecargarNivel(nivel);	
		if (aux == 1) { //poner la musica del menu
			entorno.Musica(0); aux = 0;
		}
	}
	else if(estado==MUERTE){
	
		entorno.Aviso(1, mundo.GetHombrePos().x, mundo.GetHombrePos().y); 
		entorno.DibujaJuego(nivel); //funciona
		mundo.DibujaBasico();	
		//if (mundo.gettiempo() != -1000) { mundo.fichero(nivel); }
	}
	else if (estado == GANAR) {	
		avion.Dibuja();
		switch (nivel){
		case 1:
			entorno.Aviso(2, mundo.GetHombrePos().x, mundo.GetHombrePos().y);
			AvanceNivel = 1; //sirve para conocer que niveles se han pasado y cuales no 
			break;
		case 2:
			entorno.Aviso(2, mundo.GetHombrePos().x, mundo.GetHombrePos().y);
			AvanceNivel = 2;
			break;
		case 3:
			entorno.Aviso(4, mundo.GetHombrePos().x, mundo.GetHombrePos().y);
			AvanceNivel = 3;
			break;
		}
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
	// ES EL HACK PARA PODER HACER TODOS LOS NIVELES 
	if(key == '0') {
		AvanceNivel = 3;
	}
	/////////////////////////////////////////////////////////////
	if (estado == JUEGO) {
		mundo.Tecla(key);
		if (key == 'p') {
			estado = PAUSA;	
		}
	}
	else if (estado == MUERTE) {
		switch (key) {
		case '7': //VOLVER AL MENU PRINCIPAL
			estado = MENU;
		
			mundo.RecargarNivel(nivel);
			aux = 1;
			nivel = 0;
			
			break;
		case '8': //REINICIAR EL NIVEL
			estado = JUEGO;
			
			mundo.RecargarNivel(nivel);
			aux = 1;
			break;
		}
	}
	else if (estado == GANAR) {
		switch (key) {		
		case '7': //VOLVER AL MENU PRINCIPAL
			estado = MENU;
		
			mundo.RecargarNivel(nivel);
			aux = 1;
			nivel = 0;
			break; //PASAR AL SIGUIENTE NIVEL
		case '8':
			if (AvanceNivel < 3) {
			estado = JUEGO;	
			
			nivel += 1;
			mundo.RecargarNivel(nivel);
			aux = 1;
			break;
			}
			
		}				
	}
	else if (estado == PAUSA) {
		if (key == 'c') { //CONTINUAR EL JUEGO
			mundo.Dibuja(nivel);
			estado = JUEGO;
		}
		else if (key == 'm') { //IR AL MENU PRINCIPAL
			estado = MENU;
			mundo.RecargarNivel(nivel);
			aux = 1;
		}
	}
	else if (estado == MENU) { //PARA ELEGIR EL NIVEL EN CASO DE QUE SE HAYA PASADO EL NIVEL ANTERIOR CON TECLAS
		if (key == ' ') { 
			switch (aux2) {
			case 0:
				break;
			case 1:
				estado = JUEGO;
				nivel = 1;
				mundo.RecargarNivel(nivel);
				aux = 1;
				break;
			case 2:
				if (AvanceNivel >= 1) {
					estado = JUEGO;
					nivel = 2;
					mundo.RecargarNivel(nivel);
					aux = 1;
				}
			
				break;
			case 3:
				if (AvanceNivel >= 2) {
					estado = JUEGO;
					nivel = 3;
					mundo.RecargarNivel(nivel);
					aux = 1;
				}
				
				break;
			}
		}
		else if (key == 's') {
			exit(0);
		}
	}
}
void Coordinador::teclaEspecial(unsigned char key) {

	
	if(estado==JUEGO)
		mundo.teclaEspecial(key);
	else if (estado == MENU) { //PARA ELEGIR NIVEL. AUX=LEVEL PERO SOLO PARA COLOREARLO
		switch (key) {
		case GLUT_KEY_DOWN:
			
			switch (aux2) { 
			case 0:
				aux2 = 3;
				break;
			case 1:
				aux2 = 2;
				break;
			case 2:
				aux2 = 3;
				break;
			case 3:
				aux2 = 3;
			}
			break;
		
		case GLUT_KEY_UP:

			switch (aux2) {
			case 0:
				aux2 = 1;
				break;
			case 1:
				aux2 = 1;
				break;
			case 2:
				aux2 = 1;
				break;
			case 3:
				aux2 = 2;
			}
			break;
		
		}
	}
}

void Coordinador::ClickMouse(int b, int state) { //PARA ELEGIR NIVEL CON EL RAT�N EN CASO DE QUE SE HAYA PASADO EL NIVEL ANTERIOR
	bool down = (state == GLUT_DOWN);
	int button;
	if (estado == MENU) {
		if (b == GLUT_LEFT_BUTTON) {
			button = MOUSE_LEFT_BUTTON;

			if (ymouse > 11.5 && ymouse <= 13) {				
					nivel = 1;
					estado = JUEGO;
					mundo.RecargarNivel(nivel);
					aux = 1;				
			}
			else if (ymouse > 9.5 && ymouse <= 11.5) {
				if (AvanceNivel >= 1) {
					nivel = 2;
					estado = JUEGO;
					mundo.RecargarNivel(nivel);
					aux = 1;
				}
				
			}
			else if (ymouse > 8 && ymouse <= 9.5) {
				if (AvanceNivel >= 2) {
					nivel = 3;
					estado = JUEGO;
					mundo.RecargarNivel(nivel);
					aux = 1;
				}
			}
		}
	}
	
}
void Coordinador::MyMouse(int x, int y) {
	xmouse = (x - 400) / 13, 3; //coordinar con la x de nuestra pantalla
	ymouse = -(y - 455) / 17.5 + 1; //coordinar con la y de niestra pantalla
}


