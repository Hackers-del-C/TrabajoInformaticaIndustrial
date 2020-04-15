#include "Hombre.h"
#include "ETSIDI.h"
#include "glut.h"
#include <iostream>
using namespace ETSIDI;
using ETSIDI::getTexture;


void Hombre::Dibuja()
{

    glPushMatrix();
    glTranslatef(posicion.x, posicion.y, 0);
    glColor3f(100, 10.0, 0.0);
    glutSolidSphere(altura, 20, 20);
    glPopMatrix();

   
}

void Hombre::Mueve(float t)
{
    posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
    velocidad = velocidad + aceleracion * t;
   
}

Hombre::Hombre() {
    aceleracion.y = 0;
    altura = 1.5f;
}

Hombre::~Hombre() {

}

void Hombre::SetVel(float vx, float vy)
{
    velocidad.x = vx;
    velocidad.y = vy;
}