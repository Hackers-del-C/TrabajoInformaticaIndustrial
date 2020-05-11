#include "Bonus.h"
#include "ETSIDI.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "glut.h"
#include "math.h"
using namespace ETSIDI;
using namespace std;
using ETSIDI::getTexture;

Bonus::Bonus() {
	velocidad.y = -5;
}
Bonus::~Bonus() {
//	aceleracion.y = -9.8;
}
void Bonus::SetPos(	float ix, float iy) {
	  posicion.x = ix;
	  posicion.y = iy;
}
void Bonus::Dibuja() {
	glTranslatef(posicion.x, posicion.y, 0);
	bonus->draw();
	glTranslatef(-posicion.x, -posicion.y, 0);
}
void Bonus::Mueve(float t) {
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
}









