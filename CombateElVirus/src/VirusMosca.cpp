#include "VirusMosca.h"
#include "Billete.h"

using namespace ETSIDI;
using namespace std;
using ETSIDI::getTexture;

VirusMosca::~VirusMosca() {

}

VirusMosca::VirusMosca() {

    anchura = 0.4 * 3;
    altura = 0.4 * 3;
}

VirusMosca::VirusMosca(float x, float y, float r) {
    recorrido = r;
    vidas = 3;
    posicion.x = x;
    posicion.y = y;
    anchura = 4;
    altura = 4;
    velocidad.x = 3;
    

    posicionini.x = x;
    posicionini.y = y;
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

        if (recorrido + posicionini.x < posicion.x) {
            velocidad.x = -velocidad.x;
            sprite->flip(0, 0);
        }
        if (posicionini.x - recorrido > posicion.x) {
            velocidad.x = -velocidad.x;
            sprite->flip(1, 0);
        }
        
}

void VirusMosca::Dispara(ListaSlime &l) {

    l.agregar(new Slime(posicion.x, posicion.y));

}

void VirusMosca::Muere() {
   
}

void VirusMosca::LanzaBonus(ListaBonus& l) {
    l.agregar(new Billete(posicion.x,17, 4, 4));
}

