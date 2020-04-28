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
    glTranslatef(posx, posy, 0);


    if (dir == 1) {
        companionder->draw();
    }
    if (dir == 2) {
        companionizq->draw();
    }


    glTranslatef(-posx, -posy, 0);
}
void Amigo::SetVel(float vx, float vy)
{
    velocidad.x = vx;
    velocidad.y = vy;
}
void Amigo::Mueve() {
    companionder->loop();
    companionizq->loop();
}