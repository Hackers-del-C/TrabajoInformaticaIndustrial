#include"Municion.h"
using namespace ETSIDI;

Municion::Municion() {

	velocidad.y = -6.0f;

}
Municion:: ~Municion() {

}

Municion::Municion(int x, int y, int w, int h) {

	anchura = 0.5 * w;
	altura = 0.5 * h;
	bonus = new Sprite("imagenes/municion.png", 0, 0, w, h);
	posicion.x = x;
	posicion.y = y;

}

Municion::Municion(int x, int y, int vx, int w, int h) {

	anchura = 0.5 * w;
	altura = 0.5 * h;
	bonus = new Sprite("imagenes/municion.png", 0, 0, w, h);
	posicion.x = x;
	posicion.y = y;
	velocidad.x = vx;

}

void Municion::Mueve(float t) {

	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
}
bool Municion::colision(Hombre& h) {
	
	if (h.GetMunicion() < 20) {
		h.SetMunicion(h.GetMunicion() + 2);
		return true;
	}
	else {
		return false;
	}
}