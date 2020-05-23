#include "VirusSlime.h"
#include "Municion.h"
#include "BonusMascarilla.h"


using namespace ETSIDI;
using namespace std;
using ETSIDI::getTexture;

VirusSlime::~VirusSlime() {

}

VirusSlime::VirusSlime() {

    anchura = 0.4 * 3;
    altura = 0.4 * 3;
}

VirusSlime::VirusSlime(float x, float y, float r) {

    vidas = 1;
    posicion.x = x;
    posicion.y = y;
    velocidad.x = 2;
    anchura = 4;
    altura = 4;
    posicionini.x = x;
    posicionini.y = y;
    recorrido = r;
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

   
    if (recorrido + posicionini.x < posicion.x) {
        velocidad.x = -velocidad.x;
        sprite->flip(0, 0);
    }
    if (posicionini.x - recorrido > posicion.x) {
        velocidad.x = -velocidad.x;
        sprite->flip(1, 0);
    }
    //No sigue al hombre 

}

void VirusSlime::LanzaBonus(ListaBonus& l) {
    float naleatorio = lanzaDado(100.0);
    if (naleatorio < 60.0) {
        l.agregar(new Municion(posicion.x, posicion.y, 0, 2, 2));
    }
    else if (naleatorio > 60.0) {
        l.agregar(new BonusMascarilla(posicion.x, posicion.y, 0, 2, 2));
    }
}