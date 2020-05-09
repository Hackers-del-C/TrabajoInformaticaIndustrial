#include "VirusGusano.h"


using namespace ETSIDI;
using namespace std;
using ETSIDI::getTexture;

VirusGusano::~VirusGusano() {

}

VirusGusano::VirusGusano() {

    anchura = 0.4 * 3;
    altura = 0.4 * 3;
}

VirusGusano::VirusGusano(float x, float y) {


    posicion.x = x;
    posicion.y = y;

    //Creacion de los objetos sprites

    sprite = new SpriteSequence("imagenes/enemigos/virusgusano.png", 8, 1, 40, true, 0, 0, 3, 3);

}


void VirusGusano::Inicializa(float x, float y) {


    posicion.x = x;
    posicion.y = y;

    //Creacion de los objetos sprites

    sprite = new SpriteSequence("imagenes/enemigos/virusgusano.png", 8, 1, 40, true, 0, 0, 1, 1);

}

void VirusGusano::Seguir(Hombre h) {

    if (h.posicion.x + 5 < posicion.x) {
        velocidad.x = -3;
        sprite->flip(0, 0);
    }
    if (h.posicion.x - 5 > posicion.x) {
        velocidad.x = +3;
        sprite->flip(1, 0);
    }


}