#include "VirusBaba.h"


using namespace ETSIDI;
using namespace std;
using ETSIDI::getTexture;

VirusBaba::~VirusBaba() {

}

VirusBaba::VirusBaba() {

    anchura = 6*0.4;
    altura = 6*0.4;

}

VirusBaba::VirusBaba(float x, float y) {

    posicion.x = x;
    posicion.y = y;

    sprite = new SpriteSequence("imagenes/enemigos/virusbabaanda.png", 7, 1, 80, true, 0, 0, 6, 6);

}



void VirusBaba::Inicializa(float x, float y) {

    posicion.x = x;
    posicion.y = y;

    sprite = new SpriteSequence("imagenes/enemigos/virusbabaanda.png", 7, 1, 80, true, 0, 0, 6, 6);

}

void VirusBaba::Ataca() {

    sprite = new SpriteSequence("imagenes/enemigos/virusbabaataca.png", 1, 9, 90, false, 0, 0, 6, 6);

}

void VirusBaba::Desaparece() {

    sprite = new SpriteSequence("imagenes/enemigos/virusbabades.png", 1, 9, 90, false, 0, 0, 6, 6);

}

void VirusBaba::Mueve(float t) {

    posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
    velocidad = velocidad + aceleracion * t;


    if (lanzaDado(100) < 2) {
        Desaparece();
    }


    sprite->loop();

}

int VirusBaba::Fin() {

    
    return sprite->getState();
}



