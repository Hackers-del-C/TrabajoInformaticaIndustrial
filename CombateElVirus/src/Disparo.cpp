#include "Disparo.h"

#include "glut.h"

void Disparo::Dibuja()
{
    glColor3ub(0,0, 0);

   /* glPushMatrix();*/
  glTranslatef(posicion.x, posicion.y, 0);
  glColor3f(0.1960785, 0.8, 0.6);
 glutSolidSphere(radio, 20, 20);
   // shot->draw();
   glTranslatef(-posicion.x, -posicion.y, 0);
   glDisable(GL_LIGHTING);

   
    
    /*glBegin(GL_POLYGON);
    glVertex3d(posicion.x, posicion.y, 0);
    glVertex3d(posicion.x, posicion.y, 0);
    glVertex3d(posicion.x + 0.05, posicion.y, 0);
    glVertex3d(posicion.x + 0.05, posicion.y, 0);
    glEnd();*/

}

void Disparo::Mueve(float t){
    posicion = posicion + velocidad * t;
    //shot->loop;
}


Disparo::Disparo(float r, float px, float py, float vx, float vy) {
    radio = r;
    posicion.x = px;
    posicion.y = py;
    velocidad.x = vx;
    velocidad.y = vy;
   // shot = new ETSIDI::SpriteSequence("imagenes/disparo/disparo.png", 2, 1, 25, true, 0, 0, 2, 2);
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

int Disparo::Fin() {
    //TODO -add code here si queremos eliminar disparo normal con secuencia
   
    return 0;
}
