#include "Hombre.h"
#include "ETSIDI.h"
#include "glut.h"
#include <iostream>
#include "Interaccion.h"

using namespace ETSIDI;
using ETSIDI::getTexture;

Hombre::Hombre() {
    aceleracion.y = -20.0f;
    //aceleracion.y = 0.0f;
   
    posicion.y = 0;
    posicion.x = 0;
    dir = 0;
    vidas =5;
}

Hombre::~Hombre() {

}
void Hombre::Dibuja()
{
    glTranslatef(posicion.x, posicion.y, 0);

    switch (dir) {
    case 0:
        mario->draw();
        break;

    case 1:
        marioder->draw();
        break;

    case 2:

        marioizq->draw();
        break;
    }
        glTranslatef(-posicion.x, -posicion.y, 0);
    
  
}

void Hombre::Mueve(float t)
{
 
    posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
    velocidad = velocidad + aceleracion * t;

    //ESTO LO PONDRIA CON UN SWICH Y AHORRAMOS MEMORIA
    

    mario->loop();
    marioder->loop();
    marioizq->loop();

  

}

void Hombre::Inicializa(){  

    /////level1
    mario = new SpriteSequence("imagenes/mariofrente.png", 1, 1, 25, true, -2, 2, 3, 3);
    marioder = new SpriteSequence("imagenes/marioderecha.png", 3, 1, 25, true, -2, 2, 3, 3); 
    marioizq = new SpriteSequence("imagenes/marioizquierda.png", 3, 1, 25, true, -2, 2, 3, 3);
    mariomuerte = new SpriteSequence("imagenes/mariomuerte.png",5, 1, 25, true, -2, 2, 3, 3);//no se por que no funciona bien el sprite

    ////level 2
    /*
    trump = new SpriteSequence("imagenes/trump.png", 6, 4, 25, true, -2, 2, 5, 5);
    trumpder = new SpriteSequence("imagenes/trumpder.png", 6, 1, 25, true, -2, 2, 5, 5);
    trumpizq = new SpriteSequence("imagenes/trumpizq.png", 6, 1, 25, true, -2, 2, 5, 5);
    */
   
   
    altura = 5;
    anchura = 5;
}



void Hombre::SetVel(float vx, float vy)
{
    velocidad.x = vx;
    velocidad.y = vy;
}

void Hombre::Salta()
{
    velocidad.y = 15;
}
void Hombre::FinPartida() { //va e Mundo.cpp Dibuja
    velocidad.x = 0;
    velocidad.y = 0;
    posicion.x = 0;
    posicion.y = -5; 
    vidas = 5;
    dir = 0;
    //personajemuerto->draw();
}