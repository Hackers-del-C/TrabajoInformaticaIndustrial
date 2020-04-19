#include "Hombre.h"
#include "ETSIDI.h"
#include "glut.h"
#include <iostream>
using namespace ETSIDI;
using ETSIDI::getTexture;


void Hombre::Dibuja(int nivel)
{
    glTranslatef(posicion.x, posicion.y, 0);

    switch (nivel) {
    case 1:
        if (dir == 0 ) {
            goku->draw();
        }
        if (dir == 1 ) {
            gokuder->draw();
        }
        if (dir == 2 ) {
            gokuizq->draw();
        }
        break;
    case 2:
        if (dir == 0 ) {
            trump->draw();
        }
        if (dir == 1 ) {
            trumpder->draw();
        }
        if (dir == 2 ) {
            trumpizq->draw();
        }
        break;
    case 3:
        if (dir == 0 ) {
            muñeco->draw();
        }
        if (dir == 1 ) {
            muñecoder->draw();
        }
        if (dir == 2 ) {
            muñecoizq->draw();
        }
           break;

    }
    glTranslatef(-posicion.x, -posicion.y, 0);
   // glPushMatrix();
   
    
    
   
   
 
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

    muñeco->loop();
    muñecoder->loop();
    muñecoizq->loop();
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
    muñeco = new SpriteSequence("imagenes/muñeco.png", 6, 1, 25, true, -2, 2, 5, 5);
    muñecoder = new SpriteSequence("imagenes/muñecoder.png", 6, 1, 25, true, -2, 2, 5, 5);
    muñecoizq = new SpriteSequence("imagenes/muñecoizq.png", 6, 1, 25, true, -2, 2, 5, 5);
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