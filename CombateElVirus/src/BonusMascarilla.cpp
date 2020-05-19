#include "BonusMascarilla.h"

using namespace ETSIDI;
using namespace std;
using ETSIDI::getTexture;

BonusMascarilla::BonusMascarilla() {
	
	velocidad.y = -5;
}
BonusMascarilla::~BonusMascarilla() {

}
BonusMascarilla::BonusMascarilla(int x, int y, int w, int h) {
	anchura = 0.4 * w;
	altura = 0.4 * h;
	

	bonus = new Sprite("imagenes/mascarilla.png", 0, 0, w, h);
	posicion.x = x;
	posicion.y = y;
}
void BonusMascarilla::Inicializa(int x, int y, int w, int h) {
	anchura = 0.4 * w;
	altura = 0.4 * h;
	posicion.x = x;
	posicion.y = y;
	bonus = new Sprite("imagenes/municion.png", 0, 0, w, h);
}

void BonusMascarilla::Mueve(float t) {
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
}

bool BonusMascarilla::colision(Hombre& h) {
	if (h.GetVidas() <= 4) {
		h.SetVidas(h.GetVidas() + 1);
		return true;
	}
	else
		return false;
}


