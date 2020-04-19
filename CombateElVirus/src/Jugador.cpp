#include "Jugador.h"
#include "ETSIDI.h"
#include "glut.h"
#include <iostream>
using namespace ETSIDI;
using ETSIDI::getTexture;

Jugador::Jugador() {
    aceleracion.y = -15.0f;
    //aceleracion.y = 0.0f;
    altura = 1.5f;
    posicion.y = -5;
    posicion.x = 0;
    dir = 0;

}

Jugador::~Jugador() {

}
void Jugador::Inicializa()
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

void Jugador::Dibuja(int nivel)
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
            mu�eco->draw();
        }
        if (dir == 1 ) {
            mu�ecoder->draw();
        }
        if (dir == 2 ) {
            mu�ecoizq->draw();
        }
           break;

    }
    glTranslatef(-posicion.x, -posicion.y, 0);
   // glPushMatrix();
     
   
   
 
   // glColor3f(100, 10.0, 0.0);
   // glutSolidSphere(altura, 20, 20);
   // glPopMatrix();
  
}

void Jugador::Mueve(float t)
{
 
    posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
    velocidad = velocidad + aceleracion * t;

    //ESTO LO PONDRIA CON UN SWICH Y AHORRAMOS MEMORIA
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




void Jugador::SetVel(float vx, float vy)
{
    velocidad.x = vx;
    velocidad.y = vy;
}

void Jugador::Salta()
{
    velocidad.y = 15;
}