#include "Hombre.h"
#include "ETSIDI.h"
#include "glut.h"
#include <iostream>
using namespace ETSIDI;
using ETSIDI::getTexture;


void Hombre::Dibuja()
{

   // glPushMatrix();
    glTranslatef(posicion.x, posicion.y, 0);
    if (dir == 0) {
        trump->draw();
    }
    if (dir == 1) {
        trumpder->draw();
    }
    if (dir == 2) {
        trumpizq->draw();
    }
    glTranslatef(-posicion.x, -posicion.y, 0);
   // glColor3f(100, 10.0, 0.0);
   // glutSolidSphere(altura, 20, 20);
   // glPopMatrix();
  
}

void Hombre::Mueve(float t)
{
 
        posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
    
    
    velocidad = velocidad + aceleracion * t;
    trump->loop();
    trumpder->loop();
    trumpizq->loop();
    
   
}

void Hombre::Inicializa()
{
    trump = new SpriteSequence("imagenes/trump.png", 6, 4, 25, true, -2, 2, 5, 5);
    trumpder = new SpriteSequence("imagenes/trumpder.png", 6, 1, 25, true, -2, 2, 5, 5);
    trumpizq = new SpriteSequence("imagenes/trumpizq.png", 6, 1, 25, true, -2, 2, 5, 5);
}

Hombre::Hombre() {
    aceleracion.y = -9.8f;
    altura = 1.5f;
    posicion.y = -5;
    posicion.x = 0;
    dir = 0;

}

Hombre::~Hombre() {

}

void Hombre::SetVel(float vx, float vy)
{
    velocidad.x = vx;
    velocidad.y = vy;
}