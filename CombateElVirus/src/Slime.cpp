#include "Slime.h"


using namespace ETSIDI;
using namespace std;
using ETSIDI::getTexture;

Slime::~Slime() {

}

Slime::Slime() {

    anchura = 6 * 0.4;
    altura = 6 * 0.4;
    velocidad.x = 0;
    velocidad.y = 0;
    aceleracion.y = -3;

}

Slime::Slime(float x, float y) {

    posicion.x = x;
    posicion.y = y;
    altura = 0.1;
    anchura = 0.1;
    velocidad.x = 0;
    velocidad.y = 0;
    aceleracion.y = -3;
    chocar = 0;
    sprite = new SpriteSequence("imagenes/enemigos/balababa.png", 8, 1, 40, true, 0, 0, 3, 3);

}

void Slime::Dibuja()
{
    glTranslatef(posicion.x, posicion.y, 0);

    sprite->draw();

    glTranslatef(-posicion.x, -posicion.y, 0);

}


void Slime::Inicializa(float x, float y) {

    posicion.x = x;
    posicion.y = y;

    sprite = new SpriteSequence("imagenes/enemigos/balababa.png", 8, 1, 40, true, 0, 0, 3, 3);

}

void Slime::Choca() {

    if(chocar==0){
    sprite = new SpriteSequence("imagenes/enemigos/balababaexplota.png", 3, 1, 80, false, 0, 0, 3, 3);
    SetVel(0, 0);
    aceleracion.y = 0;
    chocar = 1;
    }


}

void Slime::Goto(float x, float y) {

  

}


void Slime::SetVel(float vx, float vy)
{
    velocidad.x = vx;
    velocidad.y = vy;
}


void Slime::Mueve(float t) {

    posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
    velocidad = velocidad + aceleracion * t;

    sprite->loop();
}
