#include "VirusMosca.h"


using namespace ETSIDI;
using namespace std;
using ETSIDI::getTexture;

VirusMosca::~VirusMosca() {

}

VirusMosca::VirusMosca() {

    anchura = 0.4 * 3;
    altura = 0.4 * 3;
    billete = 0;
}

VirusMosca::VirusMosca(float x, float y) {

    vidas = 3;
    posicion.x = x;
    posicion.y = y;
    anchura = 4;
    altura = 4;
    billete = 0;

    //Creacion de los objetos sprites

    sprite = new SpriteSequence("imagenes/enemigos/virusmosca.png", 1, 4, 40, true, 0, 0, 3, 3);

}


void VirusMosca::Inicializa(float x, float y) {


    posicion.x = x;
    posicion.y = y;

    //Creacion de los objetos sprites

    sprite = new SpriteSequence("imagenes/enemigos/virusmosca.png", 1, 4, 40, true, 0, 0, 3, 3);

}

void VirusMosca::Seguir(Hombre h) {


    if (h.GetPos().x > 190) {

        if (h.posicion.x < posicion.x - 10) {
            velocidad.x = -3;
            sprite->flip(0, 0);

        }
        else if (h.posicion.x > posicion.x + 10) {
            velocidad.x = +3;

            sprite->flip(1, 0);
        }
        
    }

}

void VirusMosca::Dispara(ListaSlime &l) {

    l.agregar(new Slime(posicion.x, posicion.y));

}

void VirusMosca::Muere() {
    billete = 1;
}

bool VirusMosca::Billete() {
    return billete;
}
