#include "Virus.h"
#include "ETSIDI.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "glut.h"
#include "math.h"

using namespace ETSIDI;
using namespace std;
using ETSIDI::getTexture;
void Virus::OnTimer(int value) {

   /* glutTimerFunc(25, Virus::OnTimer, 0);
    glutPostRedisplay();*/
}
Virus::Virus(){

   
}


Virus::~Virus() {

}
void Virus::Dibuja(int nivel)
{
    glTranslatef(posicion.x, posicion.y, 0);
   
    //Dependiendo de los permisos y las acciones dibuja un srpite u otro
   
   
    if (ataque == 1) {
            spriteataca->draw();
    }
    if (anda == 1) {

       if(lateral==1){
            if (velocidad.x > 0) {
                spriteder->draw();
            }
            if (velocidad.x < 0) {
                spriteizq->draw();
            }
       }
       else {
           sprite->draw();
       }
    }
    if (muere == 1) {

         spritemuere->draw();
    }


    //if (muere == 1) {
    //    glTranslatef(-0.5, 0, 0); //Para que la sangre salga del lateral, estaria mejor con W
    //    spritemuere->draw();
    //    glTranslatef(+0.5, 0, 0);
    //    if (lateral == 1) {
    //        spriteizq->draw();
    //    }
    //    else { sprite->draw(); }
    //}
    glTranslatef(-posicion.x, -posicion.y, 0);

}

void Virus::Muere(ETSIDI::Vector2D vectormuerte)
{
    //spritemuere->setCenter(10, 3);
      //  spritemuere->setPos(10,3);

    if (permitirmuerte == 1) {
        spritemuere->setAngle(vectormuerte.argument() * 180 / 3.14159265); //Hay que mirar si la funcion vector 2d de etsidi tiene argumento (atan(vectormuerte.y/vectormuerte.x)
        muere = 1;
        anda = 0;
        ataque = 0;

        ETSIDI::play("mis_sonidos/virusmuere1.wav");
        /*glutPostRedisplay();
        glutTimerFunc(2500,Muere, 0);*/
    }
    
}

void Virus::SetVel(float vx, float vy)
{
    velocidad.x = vx;
    velocidad.y = vy;
}

void Virus::Ataca()
{
    if (permitirataque == 1) {
        ataque = 1;
        muere = 0;
        lateral = 0;
        anda = 0;
    }

}

void Virus::Anda()
{
    anda = 1;
    if(permitirlateral==1){
        lateral = 1;
    }
    muere = 0;
    ataque = 0;
   

}

void Virus::Mueve(float t) {

    posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
    velocidad = velocidad + aceleracion * t;

    if (ataque == 1) {
        spriteataca->loop();
    }
    if (anda == 1) {

        if (lateral == 1) {
            if (velocidad.x > 0) {
                spriteder->loop();
            }
            if (velocidad.x < 0) {
                spriteizq->loop();
            }
        }
        else {
            sprite->loop();
        }
    }
    if (muere == 1) {

        spritemuere->loop();
    }
}


