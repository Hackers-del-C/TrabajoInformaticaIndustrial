#include "ETSIDI.h"
#include "glut.h"
#include <iostream>
#include "Vector2D.h"
#include "Amigo.h"
using namespace ETSIDI;
using ETSIDI::getTexture;
void Amigo::Inicializa() {
    //compañero
    companionder = new SpriteSequence("imagenes/companionder.png", 2, 1, 25, true, -2, 2, 5, 5);
    companionizq = new SpriteSequence("imagenes/companionizq.png", 2, 1, 25, true, -2, 2, 5, 5);
    companion = new SpriteSequence("imagenes/companion.png", 2, 1, 25, true, -2, 2, 5, 5);
}
void Amigo::Dibuja(float posx, float posy, int dir) {
   
    posicion.y = -5;//si queremos que salte pues habria que poner posy. Realmente sobra
    glTranslatef(posicion.x, posicion.y, 0);
    switch (dir) {
    case 0:
        posicion.x = posx - 7;
        companion->draw();
        break;
    case 1:
       /* while (posx - posicion.x < 7) {
            companion->draw();
            SetVel(0);
            
        }*/
        posicion.x = posx - 7;
        companionder->draw();
        break;
    case 2:
        /*while (posicion.x - posx < 4) {
    
            companion->draw();
        }*/
        posicion.x = posx + 7;
        companionizq->draw();
        break;
    }
        glTranslatef(-posicion.x, -posicion.y, 0);

        
}
void Amigo::SetVel(float vx)// float vy)
{
    velocidad.x = vx;
   // velocidad.y = vy;
}
void Amigo::Mueve(float t) {
  
    companionder->loop();
    companionizq->loop();
    companion->loop();
}
