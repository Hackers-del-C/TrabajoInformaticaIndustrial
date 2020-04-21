#include"Misil.h"

#include"glut.h"

/*Misil::Misil() {

}*/
void Misil::Inicializader() {
	//lanzamisiles1 = new Sprite("imagenes/lanzamisiles.png", 30, -4, 4, 4);

	misilder = new Sprite("imagenes/misilder.png", 31, 0, 2, 2);
	
}
void Misil::Inicializaizq() {
	//lanzamisiles1 = new Sprite("imagenes/lanzamisiles.png", 30, -4, 4, 4);

	misilizq = new Sprite("imagenes/misilizq.png", 29, 0, 2, 2);
}
void Misil::Dibujader() {
	misilder->draw();

}
void Misil::Dibujaizq() {

	misilizq->draw();
}
void Misil::Mueveder(float t) {
	posicion = posicion + velocidad * t;

	misilder->loop();

}
void Misil::Mueveizq(float t) {
	posicion = posicion + velocidad * t;


	misilizq->loop();
}
void Misil::SetVel(float v) {
	velocidad.x = v;
}