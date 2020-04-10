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
    glVertex3d(posicion.x + 0.05, posicion.y, 0);
    glVertex3d(origen.x + 0.05, origen.y, 0);
    glEnd();

}

void Disparo::Mueve(float t)
{
    posicion = posicion + velocidad * t;
    

}

Disparo::Disparo() {

    aceleracion.y = 0;
    radio = 0.25f;
    velocidad.y = 7;

}

Disparo::~Disparo() {
}

void Disparo::SetPos(float ix, float iy) {
    posicion.x = ix;
    posicion.y = iy;
}

void Disparo::SetOri(float ix, float iy) {

    origen.x = ix;
    origen.y = iy;

}
