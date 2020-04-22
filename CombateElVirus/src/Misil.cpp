#include"Misil.h"

#include"glut.h"

/*Misil::Misil() {

}*/
Misil::Misil(float x, float y, float vx, float vy) {
	posicion.x = x;
	posicion.y = x;
	velocidad.x = vx;
	velocidad.y = vy;
}


/*void Misil::Inicializader() {
	//lanzamisiles1 = new Sprite("imagenes/lanzamisiles.png", 30, -4, 4, 4);

	misilder = new Sprite("imagenes/misilder.png", 31, 0, 2, 2);
	
}*/
void Misil::Inicializa() {
	//lanzamisiles1 = new Sprite("imagenes/lanzamisiles.png", 30, -4, 4, 4);

	misilizq = new Sprite("imagenes/misilizq.png", 29, 0, 2, 2);
}
/*void Misil::Dibujader() {
	misilder->draw();

}*/
void Misil::Dibuja() {

	misilizq->draw();
}
/*void Misil::Mueveder(float t) {
	posicion = posicion + velocidad * t;

	misilder->loop();

}*/
void Misil::Mueve(float t) {
	posicion = posicion + velocidad * t;


	misilizq->loop();
}
void Misil::SetVel(float v) {
	velocidad.x = v;
}