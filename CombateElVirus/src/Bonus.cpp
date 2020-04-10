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
    posicion.x = posicion.x + velocidad.x * t + 0.5f * aceleracion.x * t * t;
    posicion.y = posicion.y + velocidad.y * t + 0.5f * aceleracion.y * t * t;
    velocidad.x = velocidad.x + aceleracion.x * t;
    velocidad.y = velocidad.y + aceleracion.y * t;
}

Bonus::Bonus() {
    lado = 0.25f;
    aceleracion.y = -9.8;
    aceleracion.x = 0;
}