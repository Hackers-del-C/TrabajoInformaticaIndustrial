#include"Misil.h"
#include <iostream>
#include <string>
#include <sstream>
#include"glut.h"

/*Misil::Misil() {

}*/
Misil::Misil(char  nombre [20], float x, float y, float vx, float vy)  {


	misil = new Sprite(nombre, 0, 0, 2, 2);
	posicion.x = x;
	posicion.y = y;
	velocidad.x = vx;
	velocidad.y = vy;
}



void Misil::Dibuja() {

	glTranslatef(posicion.x, posicion.y, 0);
	misil->draw();

	glTranslatef(-posicion.x,-posicion.y, 0);
	/*if (explota = 1) {
		glTranslatef(posicion.x, 0, 0);
		misilexplota->draw();

		glTranslatef(-posicion.x, 0, 0);
	}*/

}

void Misil::Mueve(float t) {

	posicion = posicion + velocidad * t;
	

	misil->loop();
	//misilexplota->loop();
}
void Misil::SetVel(float v) {
	velocidad.x = v;
}
