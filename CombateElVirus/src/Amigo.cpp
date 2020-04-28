#include "ETSIDI.h"
#include "glut.h"
#include <iostream>
#include "Vector2D.h"
#include "Amigo.h"
using namespace ETSIDI;
using ETSIDI::getTexture;
void Amigo::Inicializa() {
    //compañero
    companionder = new SpriteSequence("imagenes/companionder.png", 2, 1, 25, true, -2, 2, 2, 2);
    companionizq = new SpriteSequence("imagenes/companionizq.png", 2, 1, 25, true, -2, 2, 2, 2);
    companion = new SpriteSequence("imagenes/companion.png", 2, 1, 25, true, -2, 2, 2, 2);
    izqder = 0;
}
void Amigo::Dibuja(Hombre h) {
   
    posicion.y = -5;//si queremos que salte pues habria que poner posy. Realmente sobra
    glTranslatef(posicion.x, posicion.y, 0);
    switch (h.GetDir()) {
    case 0:
        posicion.x =  - 7;
        companion->draw();
        break;
    case 1: //// hombre yendo a la derecha
       /* while (posx - posicion.x < 7) {
            companion->draw();
            SetVel(0);
            
        }*/
        switch (izqder) {
        case 0:  // muñeco a la izquierda del hombre
            
                posicion.x = h.GetPos().x - 7;
                companionder->draw();
          
                break;
        case 1:  //muñeco a la derecha

            companion->draw();
            if (h.GetPos().x - posicion.x >= 7) {
                izqder = 0;
            }
            break;
        }
     //   posicion.x = h.GetPos().x - 7;
     //   companionder->draw();
        break;
    case 2:  ///hombre yendo a la izquierda
        /*while (posicion.x - posx < 4) {
    
            companion->draw();
        }*/
        switch (izqder) {
        case 0:  // muñeco a la izquierda del hombre
            companion->draw();
            if (posicion.x-h.GetPos().x >= 7) {
                izqder = 1;
            }
            break;
        case 1:  //muñeco a la derecha
            posicion.x = h.GetPos().x + 7;
            companionizq->draw();

            
            break;
        }
     //   posicion.x = h.GetPos().x + 7;
      //  companionizq->draw();
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
