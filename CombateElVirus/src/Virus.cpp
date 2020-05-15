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

void Virus::Muere(){
       //muerte
        // sprite = new SpriteSequence("imagenes/enemigos/virusslimeanda.png", 8, 1, 80, false, 0, 0, 4, 4);
        //ETSIDI::play("mis_sonidos/virusmuere1.wav");
        /*glutPostRedisplay();
        glutTimerFunc(2500,Muere, 0);*/    
}

int Virus::GetVidas() {
    return vidas;
}

void Virus::SetVidas(int v) {
    vidas = v;


    if(vidas<1){
        Muere();
    }
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
void Virus::Dispara(ListaSlime& l) {


}





