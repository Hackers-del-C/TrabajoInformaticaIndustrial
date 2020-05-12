#include "Explosiones.h"


using namespace ETSIDI;
using namespace std;
using ETSIDI::getTexture;

Explosiones::Explosiones() {

}

Explosiones::~Explosiones() {

}

Explosiones::Explosiones(float x, float y) {


   posicion.x = x;
   posicion.y = y;
	sprite = new SpriteSequence("imagenes/explosion.png", 5, 2, 40, false, 0, 0, 3, 3);

}

void Explosiones::Inicializa(float x, float y) {

   posicion.x = x;
   posicion.y = y;

    sprite = new SpriteSequence("imagenes/explosion.png", 5, 2, 40, true, 0, 0, 3, 3);

}

void Explosiones::Mueve(float t) {

    sprite->loop();
}

void Explosiones::Dibuja()
{
   
   glTranslatef(posicion.x, posicion.y, 0);

    sprite->draw();

    glTranslatef(-posicion.x, -posicion.y, 0);

}
