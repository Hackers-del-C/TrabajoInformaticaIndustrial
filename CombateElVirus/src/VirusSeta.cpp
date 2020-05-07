#include "VirusSeta.h"


using namespace ETSIDI;
using namespace std;
using ETSIDI::getTexture;

VirusSeta::~VirusSeta() {

}

VirusSeta::VirusSeta() {


}

VirusSeta::VirusSeta(float x, float y, float w, float h, int lateral, int ataque, int muere) {


    anchura = 0.4 * w;//Redimensionamos ya que el recorte de la imagen no es perfecta
    altura = 0.4 * h;

    posicion.x = x;
    posicion.y = y;

    //Permisos de el tipo de virus

    permitirlateral = lateral;
    permitirataque = ataque;
    permitirmuerte = muere;

    //Creacion de los objetos sprites

    sprite = new SpriteSequence("imagenes/enemigos/virusseta.png", 8, 1, 40, true, 0, 0, w, h);

}


void VirusSeta::Inicializa(float x, float y, float w, float h, int lateral, int ataque, int muere) {

  

    anchura = 0.4 * w;//Redimensionamos ya que el recorte de la imagen no es perfecta
    altura = 0.4 * h;

    posicion.x = x;
    posicion.y = y;

    //Permisos de el tipo de virus

    permitirlateral = lateral;
    permitirataque = ataque;
    permitirmuerte = muere;

    //Creacion de los objetos sprites

    sprite = new SpriteSequence("imagenes/enemigos/virusseta.png", 8, 1, 25, true, 0, 0, w, h);

}

void VirusSeta::Seguir(Hombre h) {

    if (h.posicion.x + 5 < posicion.x) {
        velocidad.x = -3;
    }
    if (h.posicion.x -5 > posicion.x) {
        velocidad.x = +3;
    }


}