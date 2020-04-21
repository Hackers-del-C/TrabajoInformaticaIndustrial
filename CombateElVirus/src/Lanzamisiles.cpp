#include "Lanzamisiles.h"
#include "glut.h"

void Lanzamisiles::Inicializa() {
lanzamisiles1= new Sprite("imagenes/lanzamisiles.png", 30, -4, 4, 4);
//sprite = new Sprite("imagenes/banana.png", 0.05, 0.05, 10, 10);
}
Lanzamisiles::Lanzamisiles() {
	posicion.x = 300;
	posicion.y = 0.5;
}
Lanzamisiles::Lanzamisiles(Vector2D pos) {

}
Lanzamisiles::~Lanzamisiles() {
}


void Lanzamisiles::Dibuja() {
	lanzamisiles1->draw();
}
