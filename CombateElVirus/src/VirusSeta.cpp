#include "VirusSeta.h"
#include "Municion.h"
#include "BonusMascarilla.h"

using namespace ETSIDI;
using namespace std;
using ETSIDI::getTexture;

VirusSeta::~VirusSeta() {

}

VirusSeta::VirusSeta() {

    anchura = 0.4 * 3;
    altura = 0.4 * 3;
   
}

VirusSeta::VirusSeta(float x, float y, float r) {
    recorrido = r;
    vidas = 2;
    posicion.x = x;
    posicion.y = y;
    anchura = 3*0.4;
    altura = 3*0.4;
    velocidad = 4;
    posicionini.x = x;
    posicionini.y = y;
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

    //No sigue al hombre 

    if (recorrido+posicionini.x < posicion.x) {
        velocidad.x = -velocidad.x;
    }
    if ( posicionini.x -recorrido> posicion.x) {
        velocidad.x = -velocidad.x;
    }

}

void VirusSeta::LanzaBonus(ListaBonus& l) {
    float naleatorio = lanzaDado(100.0);
    if (naleatorio <60.0) {
        l.agregar(new Municion(posicion.x, posicion.y, 0, 2, 2));
    }
    else if (naleatorio >60.0) {
        l.agregar(new BonusMascarilla(posicion.x, posicion.y, 0, 2, 2));
    }
}
