#include "Disparo.h"

#include "glut.h"

void Disparo::Dibuja()
{
    glColor3ub(0,0, 0);
    glPushMatrix();
    glTranslatef(posicion.x, posicion.y, 0);
    glutSolidSphere(radio, 20, 20);
    glTranslatef(-posicion.x, -posicion.y, 0);
    glDisable(GL_LIGHTING);

 
    /*
    glBegin(GL_POLYGON);
    glVertex3d(posicion.x, posicion.y, 0);
    glVertex3d(posicion.x, posicion.y, 0);
    glVertex3d(posicion.x + 0.05, posicion.y, 0);
    glVertex3d(posicion.x + 0.05, posicion.y, 0);
    glEnd();*/

}

void Disparo::Mueve(float t)
{
    posicion = posicion + velocidad * t;
    


}


Disparo::Disparo(float r, float px, float py, float vx, float vy) {
    radio = r;
    posicion.x = px;
    posicion.y = py;
    velocidad.x = vx;
    velocidad.y = vy;
}
Disparo::Disparo() {


    velocidad.y = 0;
    aceleracion.y = 0;
    radio = 0.25f;
    
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
