#include "Bonus.h"
#include <stdlib.h>
#include "glut.h"

Bonus::Bonus() {
    lado = 0.25f;
    aceleracion.y = -9.8;
    aceleracion.x = 0;
}

Bonus::~Bonus() {


}
void Bonus::Dibuja()
{
    glTranslatef(posicion.x, posicion.y, 0);
    bonus->draw();
    glTranslatef(-posicion.x, -posicion.y, 0);
}

void Bonus::Mueve(float t)
{
    posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
    velocidad = velocidad + aceleracion * t;
}

void Bonus::SetPos(float ix, float iy) {

   posicion.x = ix;
   posicion.y = iy;

}

