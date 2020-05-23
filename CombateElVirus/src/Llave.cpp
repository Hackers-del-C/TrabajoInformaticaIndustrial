#include"Llave.h"

using namespace ETSIDI;
using namespace std;
using ETSIDI::getTexture;

Llave::Llave() {
	velocidad.y = -0.05;
}
Llave::~Llave() {

}
Llave::Llave(int x, int y, int w, int h) {
	anchura = 0.4 * w;
	altura = 0.4 * h;


	bonus = new Sprite("imagenes/llave.png", 0, 0, w, h);
	posicion.x = x;
	posicion.y = y;
}
//void Llave::Inicializa(int x, int y, int w, int h) {
//	anchura = 0.4 * w;
//	altura = 0.4 * h;
//
//
//	bonus = new Sprite("imagenes/llave.png", 0, 0, w, h);
//	posicion.x = x;
//	posicion.y = y;
//}
void Llave::Mueve(float t) {
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
}
bool Llave::colision(Hombre& h) {
	//h.SetFinNivel(1) ;
	return 1;
}