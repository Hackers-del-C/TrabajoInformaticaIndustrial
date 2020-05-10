#include "VirusSlime.h"


using namespace ETSIDI;
using namespace std;
using ETSIDI::getTexture;

VirusSlime::~VirusSlime() {

}

VirusSlime::VirusSlime() {

    anchura = 0.4 * 3;
    altura = 0.4 * 3;
}

VirusSlime::VirusSlime(float x, float y) {


    posicion.x = x;
    posicion.y = y;

    //Creacion de los objetos sprites

    sprite = new SpriteSequence("imagenes/enemigos/virusslimeanda.png", 8, 1, 80, true, 0, 0, 4, 4);

}


void VirusSlime::Inicializa(float x, float y) {


    posicion.x = x;
    posicion.y = y;

    //Creacion de los objetos sprites

    sprite = new SpriteSequence("imagenes/enemigos/virusslimeanda.png", 8, 1, 90, true, 0, 0, 4, 4);

}

void VirusSlime::Seguir(Hombre h) {

    if (h.posicion.x + 5 < posicion.x) {
        velocidad.x = -3;
        sprite->flip(0, 0);
    }
    if (h.posicion.x - 5 > posicion.x) {
        velocidad.x = +3;
        sprite->flip(1, 0);
    }


}