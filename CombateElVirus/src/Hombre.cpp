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
    monedas = 0;
    agachado = 0;
}

Hombre::~Hombre() {

}
void Hombre::Dibuja()
{
    glTranslatef(posicion.x, posicion.y, 0);
   
    mario -> draw();
    glTranslatef(-posicion.x, -posicion.y, 0);
    
  
}

void Hombre::Mueve(float t)
{
 
    posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
    velocidad = velocidad + aceleracion * t;

    mario->loop();

    //if (mariorojo = 1 && mario->getState()>=6) {
    ////    mariorojo = 0;
    //}

}

void Hombre::Inicializa(){  

    /////level1
    mario = new SpriteSequence("imagenes/mario/mariofrente.png", 1, 1, 25, true, 0, 0, 4, 4);
    
   // marioizq = new SpriteSequence("imagenes/mario/marioandaizq.png", 7, 1, 25, true, 0, 0, 4, 4);
   

    altura = 4;
    anchura = 4;
}

void Hombre::Victoria()
{
    mario = new SpriteSequence("imagenes/mario/mariovictoria.png", 7, 1, 25, true, 0, 0, 4, 4);
    velocidad.x = 0;
    velocidad.y = 0;
}

void Hombre::SetVel(float vx, float vy)
{
    velocidad.x = vx;
    velocidad.y = vy;

    altura = 4;
    altura = 4;
    //mariorojo = 1;
    if (velocidad.x < 0) {
      
        if (mariorojo == 1) {
           mario = new SpriteSequence("imagenes/mario/mariodano.png", 7, 1, 80, true, 0, 0, 4, 4);
        }
        else
            mario = new SpriteSequence("imagenes/mario/marioandader.png", 7, 1, 25, true, 0, 0, 4, 4);
        mario->flip(1, 0);
    }
    else if (velocidad.x > 0) {
        if (mariorojo == 1) {
            mario = new SpriteSequence("imagenes/mario/mariodano.png", 7, 1, 80, true, 0, 0, 4, 4);
        }
        else
        mario = new SpriteSequence("imagenes/mario/marioandader.png", 7, 1, 25, true, 0, 0, 4, 4);
    }
   
}



void Hombre::Stop() {
    velocidad.x = 0;
  //  mario->pause();
}

void Hombre::Salta()
{
    velocidad.y = 10;
    altura = 4;
    altura = 4;
}

void Hombre::Agacha()
{
    
    if (velocidad.x <= 0) {
        mario = new SpriteSequence("imagenes/mario/marioagachader.png", 3, 1, 2, false, 0, -1, 4, 4);
        mario->flip(1, 0);
        altura = 0.1 * altura;
        
    }
    if (velocidad.x > 0) {
        mario = new SpriteSequence("imagenes/mario/marioagachader.png", 3, 1, 2, false, 0, -1, 4, 4);
        altura = 0.1 * altura;
       
    }
    if (velocidad.y > 0) {
        if (velocidad.x <= 0) {
            mario = new SpriteSequence("imagenes/mario/marioagachader.png", 3, 1, 2, false, 0, -1, 4, 4);
            mario->flip(1, 0);
            altura = 0.1 * altura;
            velocidad.y = -5;

        }
        if (velocidad.x > 0) {
            mario = new SpriteSequence("imagenes/mario/marioagachader.png", 3, 1, 2, false, 0, -1, 4, 4);
            altura = 0.1 * altura;
            velocidad.y =-5;
        }
        
   }
    velocidad.x = 0;
    
}
void Hombre::FinPartida() { 

    mariomuerte = new SpriteSequence("imagenes/mario/mariomuerte.png", 5, 1, 25, true, 0, 0, 4, 4);

    velocidad.x = 0;
    velocidad.y = 0;
    posicion.x = 0;
    posicion.y = -5; 
    vidas = 5;
    dir = 0;
  
}

void Hombre::Setagachado(unsigned char key) {

    switch (key) {
    case GLUT_KEY_DOWN:
        agachado = 1;
        break;

    default:
        agachado = 0;
        break;
    }

}


void Hombre::Dañar() {

    mariorojo = 1;
    SetVidas(GetVidas() - 1); 
}

void Hombre::caida(int caida, int level) {
    if (caida) {
        //   (y != 3 && y != 4 && y != 10 && y != 11 && y != 12 && y != 13 && y != 14 && y != 15 && y != 16 && y != 21 && y != 22 && y != 26 && y != 27 && y != 28)
        if (level == 1) {
            if (posicion.x < 20) {
                velocidad.x = 0;
                velocidad.y = 0;
                posicion.x = 10;
                posicion.y = 0;
            }
            else if (posicion.x < 90) {
                velocidad.x = 0;
                velocidad.y = 0;
                posicion.x = 45;
                posicion.y = 0;
            }
            else if (posicion.x < 120) {
                velocidad.x = 0;
                velocidad.y = 0;
                posicion.x = 100;
                posicion.y = 0;
            }
            else if (posicion.x < 150) {
                velocidad.x = 0;
                velocidad.y = 0;
                posicion.x = 120;
                posicion.y = 0;

            }
            else if (posicion.x < 180) {
                velocidad.x = 0;
                velocidad.y = 0;
                posicion.x = 120;
                posicion.y = 0;

            }
            else if (posicion.x > 180) {
                velocidad.x = 0;
                velocidad.y = 0;
                posicion.x = 210;
                posicion.y = 0;
            }
          
        }
    }
}