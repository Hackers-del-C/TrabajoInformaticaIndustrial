#include "Disparo.h"
#include "glut.h"

void Disparo::Dibuja()
{
    glColor3ub(0, 255, 255);
    glPushMatrix();
    glTranslatef(posicion.x, posicion.y, 0);
    glutSolidSphere(radio, 20, 20);
    glTranslatef(-posicion.x, -posicion.y, 0);
    glDisable(GL_LIGHTING);
   

    glBegin(GL_POLYGON);
    glVertex3d(origen.x, origen.y, 0);
    glVertex3d(posicion.x, posicion.y, 0);
    glVertex3d(posicion.x+0.05, posicion.y, 0);
    glVertex3d(origen.x+0.05, origen.y, 0);
    glEnd();
  

}

void Disparo::Mueve(float t)
{
    posicion.x = posicion.x + velocidad.x * t;
    posicion.y = posicion.y + velocidad.y * t;

}

Disparo::Disparo() {

    aceleracion.y = 0;
    radio = 0.25f;
    velocidad.y = 7;


}