#include "Virus.h"
#include "ETSIDI.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "glut.h"

using namespace ETSIDI;
using namespace std;
using ETSIDI::getTexture;

Virus::Virus(){

    posicion.x = 10;
    posicion.y = -3.5;

}



Virus::~Virus() {

}
void Virus::Dibuja(int nivel)
{
    glTranslatef(posicion.x, posicion.y, 0);
   
   
    if (muere == 0) {
        if (izqder == 1) {
            if (velocidad.x > 0) {
                spriteder->draw();
            }
            if (velocidad.x < 0) {
                spriteizq->draw();
            }
            if (velocidad.x == 0) {
                sprite->draw();
            }
        }
        else {
            sprite->draw();
        }
    }


    if (muere == 1) {
        glTranslatef(-0.5, 0, 0); //Para que la sangre salga del lateral, estaria mejor con W
        spritemuere->draw();
        glTranslatef(+0.5, 0, 0);
        if (izqder == 1) {
            spriteizq->draw();
        }
        else { sprite->draw(); }
    }
    glTranslatef(-posicion.x, -posicion.y, 0);

}


void Virus::Muere()
{
    
    muere = 1;
    
}

void Virus::SetVel(float vx, float vy)
{
    velocidad.x = vx;
    velocidad.y = vy;
}

void Virus::Mueve(float t, Hombre h) {

    posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
    velocidad = velocidad + aceleracion * t;



    if (muere == 1) {
        spritemuere->loop();
        sprite->pause();

        if (izqder == 1) {
            spriteder->pause();
            spriteizq->pause();
        }
        
        velocidad.x = 0;

    }
    if (muere == 0) {

        sprite->loop();

        if (izqder == 1) {
            spriteder->loop();
            spriteizq->loop();
        }

        if (posicion.x + 5 < h.posicion.x) {
            velocidad.x = 0;
        }
        if (posicion.x + 5 > h.posicion.x) {
            velocidad.x = 0;
        }
    }
   
    

}


