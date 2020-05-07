#include "VirusBaba.h"


using namespace ETSIDI;
using namespace std;
using ETSIDI::getTexture;

VirusBaba::~VirusBaba() {

}

VirusBaba::VirusBaba() {


}

VirusBaba::VirusBaba(float x, float y, float w, float h, int lateral, int ataque, int muere) {

 

        anchura = 0.4 * w;//Redimensionamos ya que el recorte de la imagen no es perfecta
        altura = 0.4 * h;

        posicion.x = x;
        posicion.y = y;

        //Permisos de el tipo de virus

        permitirlateral = lateral;
        permitirataque = ataque;
        permitirmuerte = muere;

        //Creacion de los objetos sprites

        sprite = new SpriteSequence("imagenes/enemigos/virusbabaanda.png", 7, 1, 25, true, 0, 0, w, h);

        //Creamos los sprites de movimientos laterales

        if (permitirlateral == 1) {

            spriteder = new SpriteSequence("imagenes/enemigos/virusbabader.png", 1, 9, 90, true, 0, 0, w, h);

        }

        if (permitirataque == 1) {

            spriteataca = new SpriteSequence("imagenes/enemigos/virusbabaataca.png", 1, 9, 25, true, 0, 0, w, h);
        }

       

    }



void VirusBaba::Inicializa(float x, float y, float w, float h, int lateral, int ataque, int muere) {

    anchura = 0.4 * w;//Redimensionamos ya que el recorte de la imagen no es perfecta
    altura = 0.4 * h;

    posicion.x = x;
    posicion.y = y;
    velocidad.x = 1;
    //Permisos de el tipo de virus
   
    permitirlateral = lateral;
    permitirataque = ataque;
    permitirmuerte = muere;

    sprite = new SpriteSequence("imagenes/enemigos/virusbabaanda.png", 7, 1, 80, true, 0, 0, w, h);

    //Creamos los sprites de movimientos laterales

    if (permitirlateral == 1) {

        spriteder = new SpriteSequence("imagenes/enemigos/virusbabader.png", 1, 9, 90, true, 0, 0, w, h);

    }

    if (permitirataque == 1) {

        spriteataca = new SpriteSequence("imagenes/enemigos/virusbabaataca.png", 1, 9, 25, true, 0, 0, w, h);
    }

}

