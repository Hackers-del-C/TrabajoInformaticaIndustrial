#include"Billete.h"
#include"Hombre.h"

using namespace ETSIDI;
using namespace std;

Billete::Billete() {

	velocidad.y = -5;

}

Billete:: ~Billete() {


}

void Billete::Mueve(float t) {

	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	
}

Billete::Billete(int x, int y, int w, int h, char tipo) {
	anchura = 0.5 * w;
	altura = 0.5 * h;
	if (tipo == 'b') {
		bonus = new Sprite("imagenes/billeteavion.png", 0, 0, w, h);
	}
	if (tipo == 'p') {
		bonus = new Sprite("imagenes/llave.png", 0, 0, w, h);
	}
	posicion.x = x;
	posicion.y = y;

}

bool Billete::colision(Hombre& h) {
	h.SetFinNivel(1);
	return 1;
}



