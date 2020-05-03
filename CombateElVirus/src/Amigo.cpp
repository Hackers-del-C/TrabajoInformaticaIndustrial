#include "ETSIDI.h"
#include "glut.h"
#include <iostream>
#include "Vector2D.h"

#include "Amigo.h"


void Amigo::Inicializa() {
    //compañero
    companionder = new SpriteSequence("imagenes/companionder.png", 2, 1, 25, true, 0, 0, 2, 2);
    companionizq = new SpriteSequence("imagenes/companionizq.png", 2, 1, 25, true, 0, 0, 2, 2);
    companion = new SpriteSequence("imagenes/companion.png", 2, 1, 25, true, 0, 0, 2, 2);
    izqder = 0;
}
void Amigo::Dibuja(Hombre h) {
   
    posicion.y = -3.5;
    glTranslatef(posicion.x, posicion.y, 0);
    switch (h.GetDir()) {
    case 0:
        posicion.x =  - 7;
        companion->draw();
        break;
    case 1: //// hombre yendo a la derecha
        switch (izqder) {
        case 0:  // muñeco a la izquierda del hombre            
            companionder->draw();
            if (h.GetPos().x - posicion.x >= 7) {
                posicion.x = h.GetPos().x - 7;
            }          
                break;
        case 1:  //muñeco a la derecha
            companion->draw();
            if (h.GetPos().x - posicion.x >= 7) {
                izqder = 0;
            }
            break;
        }
  
        break;
    case 2:  ///hombre yendo a la izquierda
       
        switch (izqder) {
        case 0:  // muñeco a la izquierda del hombre
            companion->draw();
            if (posicion.x-h.GetPos().x >= 7) {
                izqder = 1;
            }
            break;
        case 1:  //muñeco a la derecha
            companionizq->draw();
            if (posicion.x-h.GetPos().x  >= 7) {
                posicion.x = h.GetPos().x + 7;
            }      
            break;
        }
        break;
    }
        glTranslatef(-posicion.x, -posicion.y, 0);        
}

void Amigo::SetVel(float vx)// float vy)
{
    velocidad.x = vx;
 
}

void Amigo::Mueve(float t) {
  
    companionder->loop();
    companionizq->loop();
    companion->loop();
}

void Amigo::Mensajes() {
    
    if (posicion.x <5) {
        auxetsidi.Texto("Holaaaa!", posicion.x - 3, -1, 0, 0.1, 0.2, 8);        
        
   }
    else if (5 <= posicion.x && posicion.x < 26) {
        auxetsidi.Texto("Soy Pedro", posicion.x - 7, 0, 0, 0.1, 0.2, 8);
        auxetsidi.Texto("tu compañero de aventuras", posicion.x - 7, -1, 0, 0.1, 0.2, 8);
      
    }   
}
