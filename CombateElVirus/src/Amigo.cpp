#include "ETSIDI.h"
#include "glut.h"
#include <iostream>
#include "Vector2D.h"

#include "Amigo.h"


void Amigo::Inicializa() {
    //compa�ero
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
        switch (izqder) {
        case 0:  // mu�eco a la izquierda del hombre            
            companionder->draw();
            if (h.GetPos().x - posicion.x >= 7) {
                posicion.x = h.GetPos().x - 7;
            }          
                break;
        case 1:  //mu�eco a la derecha
            companion->draw();
            if (h.GetPos().x - posicion.x >= 7) {
                izqder = 0;
            }
            break;
        }
  
        break;
    case 2:  ///hombre yendo a la izquierda
       
        switch (izqder) {
        case 0:  // mu�eco a la izquierda del hombre
            companion->draw();
            if (posicion.x-h.GetPos().x >= 7) {
                izqder = 1;
            }
            break;
        case 1:  //mu�eco a la derecha
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
   // velocidad.y = vy;
}

void Amigo::Mueve(float t) {
  
    companionder->loop();
    companionizq->loop();
    companion->loop();
}

void Amigo::Mensajes() {
    
    if (posicion.x <5) {
        glTranslatef(posicion.x-3, -1, 0);
        setTextColor(0, 0.1, 0.2); //FUNCIONA IGUAL QUE GLUT PERO EN VEZ DE 0-255 DE 0-1
        print("Holaaaa!", "fuentes/Bitwise.ttf", 8);
        glTranslatef(-posicion.x+3,1, 0);
        
   }
    else if (5 <= posicion.x && posicion.x < 26) {
        glTranslatef(posicion.x - 7, 0, 0);
        setTextColor(0, 0.1, 0.2); //FUNCIONA IGUAL QUE GLUT PERO EN VEZ DE 0-255 DE 0-1
        print("Soy Pedro,", "fuentes/Bitwise.ttf", 8);
        glTranslated(0, -1, 0);
        print(" tu compa�ero de aventuras", "fuentes/Bitwise.ttf", 8);
        glTranslatef(-posicion.x + 7, 1, 0);
    }   
}
