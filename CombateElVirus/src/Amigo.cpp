#include "ETSIDI.h"
#include "glut.h"
#include <iostream>
#include "Vector2D.h"
#include "Amigo.h"
using namespace ETSIDI;
using ETSIDI::getTexture;
void Amigo::Inicializa() {
    //compañero
    companionder = new SpriteSequence("imagenes/companionder.png", 6, 1, 25, true, -2, 2, 5, 5);
    companionizq = new SpriteSequence("imagenes/companionizq.png", 6, 1, 25, true, -2, 2, 5, 5);
}
void Amigo::Dibuja(float posx, float posy, int dir) {

    if (dir == 1) {
        glTranslatef(posx - 4, posy, 0);
        companionder->draw();
        glTranslatef(-posx + 4, -posy, 0);
    }
    if (dir == 2) {
        glTranslatef(posx + 4, posy, 0);
        companionizq->draw();
        glTranslatef(-posx - 4, -posy, 0);
    }


}
void Amigo::SetVel(float vx)// float vy)
{
    velocidad.x = vx;
   // velocidad.y = vy;
}
void Amigo::Mueve(float t) {
    posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
    velocidad = velocidad + aceleracion * t;
    companionder->loop();
    companionizq->loop();
}