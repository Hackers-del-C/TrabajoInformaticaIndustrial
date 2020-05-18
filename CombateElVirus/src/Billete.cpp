#include"Billete.h"

using namespace ETSIDI;

Billete::Billete() {

	velocidad.y = -5;

}

Billete:: ~Billete() {


}

void Billete::Mueve(float t) {

	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;

}

Billete::Billete(int x, int y, int w, int h) {
	anchura = 0.5 * w;
	altura = 0.5 * h;
	bonus = new Sprite("imagenes/billeteavion.png", 0, 0, w, h);
	posicion.x = x;
	posicion.y = y;

}

bool  Billete::colision(Hombre& h) {

	return (Interaccion::ColisionBonus(h, *(this)));

}



