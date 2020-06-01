#include "Avion.h"
#include "ETSIDI.h"


using namespace ETSIDI;
using namespace std;
using ETSIDI::getTexture;



 Avion::Avion(float x, float y) {

    posicion.x = x;
    posicion.y = y;
    velocidad.x = -9;
    velocidad.y = 5;
    sprite = new Sprite("imagenes/avion.png", 0, 0, 10, 10);
}
Avion::Avion() {

   
}



Avion::~Avion() {

}
void Avion::Dibuja()
{
    glTranslatef(posicion.x, posicion.y, 0);

    sprite->draw();

    glTranslatef(-posicion.x, -posicion.y, 0);

}

void Avion::Mueve(float t) {

    posicion = posicion + velocidad * t;
 

}






