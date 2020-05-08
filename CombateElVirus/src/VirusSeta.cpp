#include "VirusSeta.h"


using namespace ETSIDI;
using namespace std;
using ETSIDI::getTexture;

VirusSeta::~VirusSeta() {

}

VirusSeta::VirusSeta() {

    anchura = 0.4 * 3;
    altura = 0.4 * 3;
}

VirusSeta::VirusSeta(float x, float y) {


    posicion.x = x;
    posicion.y = y;

    //Creacion de los objetos sprites

    sprite = new SpriteSequence("imagenes/enemigos/virusseta.png", 8, 1, 40, true, 0, 0, 3, 3);

}


void VirusSeta::Inicializa(float x, float y) {

  
    posicion.x = x;
    posicion.y = y;

    //Creacion de los objetos sprites

    sprite = new SpriteSequence("imagenes/enemigos/virusseta.png", 8, 1, 40, true, 0, 0, 3, 3);

}

void VirusSeta::Seguir(Hombre h) {

    if (h.posicion.x + 5 < posicion.x) {
        velocidad.x = -3;
    }
    if (h.posicion.x -5 > posicion.x) {
        velocidad.x = +3;
    }


}