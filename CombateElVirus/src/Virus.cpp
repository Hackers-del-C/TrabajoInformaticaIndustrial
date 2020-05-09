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
   
    sprite->draw();

    glTranslatef(-posicion.x, -posicion.y, 0);

}

void Virus::Muere(ETSIDI::Vector2D vectormuerte)
{
    //spritemuere->setCenter(10, 3);
      //  spritemuere->setPos(10,3);

  
        spritemuere->setAngle(vectormuerte.argument() * 180 / 3.14159265); //Hay que mirar si la funcion vector 2d de etsidi tiene argumento (atan(vectormuerte.y/vectormuerte.x)
       

        ETSIDI::play("mis_sonidos/virusmuere1.wav");
        /*glutPostRedisplay();
        glutTimerFunc(2500,Muere, 0);*/
 
    
}

void Virus::SetVel(float vx, float vy)
{
    velocidad.x = vx;
    velocidad.y = vy;
}


void Virus::Mueve(float t) {

    posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
    velocidad = velocidad + aceleracion * t;

    sprite->loop();
}

void Virus::Seguir(Hombre h) {

}





