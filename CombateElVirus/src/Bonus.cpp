#include "Bonus.h"
#include <stdlib.h>
#include "glut.h"

void Bonus::Dibuja()
{
    glPushMatrix();
    glTranslatef(posicion.x, posicion.y, 0);
    glRotatef(30, 1, 1, 1);
    glColor3f(rand() / (float)RAND_MAX, rand() / (float)RAND_MAX,
        rand() / (float)RAND_MAX);//color aleatorio
    glutSolidCube(lado);
    glPopMatrix();
}

void Bonus::Mueve(float t)
{
    posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
    velocidad = velocidad + aceleracion * t;
}

Bonus::Bonus() {
    lado = 0.25f;
    aceleracion.y = -9.8;
    aceleracion.x = 0;
}

Bonus::~Bonus() {


}

void Bonus::SetPos(float ix, float iy) {

   posicion.x = ix;
   posicion.y = iy;

}

