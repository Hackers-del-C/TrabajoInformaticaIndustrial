#include "Hombre.h"
#include "ETSIDI.h"
#include "glut.h"
#include <iostream>
using namespace ETSIDI;
using ETSIDI::getTexture;


void Hombre::Dibuja(int nivel)
{

   // glPushMatrix();
    glTranslatef(posicion.x, posicion.y, 0);
    //////// level 1:
    if (dir == 0 && nivel == 1) {
        goku->draw();
    }
    if (dir == 1 && nivel == 1) {
        gokuder->draw();
    }
    if (dir == 2 && nivel == 1) {
        gokuizq->draw();
    }
    ///////// level 2
    if (dir == 0 && nivel == 2) {
        trump->draw();
    }
    if (dir == 1 && nivel == 2) {
        trumpder->draw();
    }
    if (dir == 2 && nivel == 2) {
        trumpizq->draw();
    }
    //////// level3
    if (dir == 0 && nivel == 3) {
        mu�eco->draw();
    }
    if (dir == 1 && nivel == 3) {
        mu�ecoder->draw();
    }
    if (dir == 2 && nivel == 3) {
        mu�ecoizq->draw();
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

    goku->loop();
    gokuder->loop();
    gokuizq->loop();

    mu�eco->loop();
    mu�ecoder->loop();
    mu�ecoizq->loop();
}

void Hombre::Inicializa()
{

    /////level1
    goku = new SpriteSequence("imagenes/goku.png", 1, 3, 25, true, -2, 2, 5, 5);
    gokuder = new SpriteSequence("imagenes/gokuder.png", 1, 3, 25, true, -2, 2, 5, 5);
    gokuizq = new SpriteSequence("imagenes/gokuizq.png", 1, 3, 25, true, -2, 2, 5, 5);
    ////level 2
    trump = new SpriteSequence("imagenes/trump.png", 6, 4, 25, true, -2, 2, 5, 5);
    trumpder = new SpriteSequence("imagenes/trumpder.png", 6, 1, 25, true, -2, 2, 5, 5);
    trumpizq = new SpriteSequence("imagenes/trumpizq.png", 6, 1, 25, true, -2, 2, 5, 5);
    
    ////level3
    mu�eco = new SpriteSequence("imagenes/mu�eco.png", 6, 1, 25, true, -2, 2, 5, 5);
    mu�ecoder = new SpriteSequence("imagenes/mu�ecoder.png", 6, 1, 25, true, -2, 2, 5, 5);
    mu�ecoizq = new SpriteSequence("imagenes/mu�ecoizq.png", 6, 1, 25, true, -2, 2, 5, 5);
}

Hombre::Hombre() {
    ///aceleracion.y = -9.8f;  --- para cuando ya haya limites mientras =0
    aceleracion.y = 0.0f;
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