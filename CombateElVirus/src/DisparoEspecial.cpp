#include "DisparoEspecial.h"
#include "ETSIDI.h"

void DisparoEspecial::Dibuja()
{
  
    glTranslatef(posicion.x, posicion.y, 0);
    shot->draw();
    glTranslatef(-posicion.x, -posicion.y, 0);


}

void DisparoEspecial::Mueve(float t) {
    posicion = posicion + velocidad * t;
    shot->loop();
}


DisparoEspecial::DisparoEspecial(float r, float px, float py, float vx, float vy) {
    radio = r;
    posicion.x = px;
    posicion.y = py;
    velocidad.x = vx;
    velocidad.y = vy;
    shot = new ETSIDI::SpriteSequence("imagenes/disparos/escopeta.png", 4, 2, 50, false, 0, 0, 2, 2);
}
DisparoEspecial::DisparoEspecial() {


    velocidad.y = 0;
    aceleracion.y = 0;
    radio = 0.25f;

}

DisparoEspecial::~DisparoEspecial() {
}

int DisparoEspecial::Fin() {

    return shot->getState();

}
