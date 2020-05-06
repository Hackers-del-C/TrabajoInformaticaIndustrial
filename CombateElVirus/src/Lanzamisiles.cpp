#include "Lanzamisiles.h"
#include "glut.h"

void Lanzamisiles::Inicializa() {
lanzamisiles= new Sprite("imagenes/lanzamisiles.png", 0,0 , 4, 4);
//sprite = new Sprite("imagenes/banana.png", 0.05, 0.05, 10, 10);
}
Lanzamisiles::Lanzamisiles(char nombre[20],float x, float y) {
	lanzamisiles = new Sprite(nombre, 0, 0, 4, 4);
	posicion.x = x;
	posicion.y = y;
}
Lanzamisiles::Lanzamisiles(Vector2D pos) {
	posicion.x = pos.x;
	posicion.y = pos.y;
}
Lanzamisiles::~Lanzamisiles() {
}


void Lanzamisiles::Dibuja() {
	glTranslatef(posicion.x, posicion.y, 0);
	lanzamisiles->draw();
	glTranslatef(-posicion.x, -posicion.y, 0);
}
