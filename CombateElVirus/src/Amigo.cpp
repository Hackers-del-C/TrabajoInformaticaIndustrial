#include "ETSIDI.h"
#include "glut.h"
#include <iostream>
#include "Vector2D.h"

#include "Amigo.h"


void Amigo::Inicializa() {
    //compañero
    companionder = new SpriteSequence("imagenes/companionder.png", 2, 1, 100, true, 0, 0, 2, 2);
    companionizq = new SpriteSequence("imagenes/companionizq.png", 2, 1, 100, true, 0, 0, 2, 2);
    companion = new SpriteSequence("imagenes/companion.png", 1, 1, 100, true, 0, 0, 2, 2);
    izqder = 0;
    posicion.x = -7;
}
void Amigo::Dibuja(Hombre h) {
   
    posicion.y = -3.5;
    glTranslatef(posicion.x, posicion.y, 0);
    switch (h.GetDir()) {
    case 0:
      
        companionder->draw();
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

void Amigo::Mensajes(int level) {

    switch (level){
    case 1:
    if (posicion.x < 10) {
        auxetsidi.Texto("Ni hao!", posicion.x , 2, 0, 0.1, 0.2, 8);
        auxetsidi.Texto("Usa las teclas para moverte", posicion.x -3, 0, 0, 0.1, 0.2, 8);
        auxetsidi.Texto("Usa s,w,a,d para disparar", posicion.x -3, -1, 0, 0.1, 0.2, 8);

   }
    else if (10 <= posicion.x && posicion.x < 30) {
        auxetsidi.Texto("Coge los spry para poder disparar", posicion.x - 7, -1, 0, 0.1, 0.2, 8);
    }
    else if (50 <= posicion.x && posicion.x < 70) {
        auxetsidi.Texto("Pulsa la barra espaciadora para pararte", posicion.x - 7, -1, 0, 0.1, 0.2, 8);
    }
    else if (90 <= posicion.x && posicion.x < 110) {
        auxetsidi.Texto("A mayor numero de probetas mas puntuacion ", posicion.x - 7, -1, 0, 0.1, 0.2, 8);
    }
    else if (115 <= posicion.x && posicion.x < 140) {
        auxetsidi.Texto("Las mascarillas te dan vidas", posicion.x - 7, -1, 0, 0.1, 0.2, 8);
    }
    else if (150 <= posicion.x && posicion.x < 200) {
        auxetsidi.Texto("Nos acercamos al foco de infeccion...", posicion.x - 7, -1, 0, 0.1, 0.2, 8);
    }
    else if (200 <= posicion.x && posicion.x < 250) {
        auxetsidi.Texto("Mata al virus Mosca y consigue ", posicion.x - 7, 0, 0, 0.1, 0.2, 8);
        auxetsidi.Texto("un billete para combatir el virus en otros paises ", posicion.x - 7, -1, 0, 0.1, 0.2, 8);
    }
    break;
    case 2:
        if (posicion.x < 10) {
            auxetsidi.Texto("Ciao!", posicion.x - 3, 2, 0, 0.1, 0.2, 8);
           
        }
        break;

    case 3:
        if (posicion.x < 10) {
            auxetsidi.Texto("Holaaaa!", posicion.x - 3, 0, 0, 0.1, 0.2, 8);
            auxetsidi.Texto("Vamos a por esos virus", posicion.x - 6, -1, 0, 0.1, 0.2, 8);
          

        }
        else if (10 <= posicion.x && posicion.x < 20) {
            auxetsidi.Texto("Para con el espacio", posicion.x - 4, 0, 0, 0.1, 0.2, 8);
            auxetsidi.Texto("Y sube la escalera saltando", posicion.x - 7, -1, 0, 0.1, 0.2, 8);
        }
        else if (30 <= posicion.x && posicion.x < 70) {
            auxetsidi.Texto("CUIDADO, SI CAES MORIRAS", posicion.x - 7, -1, 0, 0.1, 0.2, 8);
        }
        else if (30 <= posicion.x && posicion.x < 70) {
            auxetsidi.Texto("CUIDADO, SI CAES MORIRAS", posicion.x - 7, -1, 0, 0.1, 0.2, 8);
        }
        else if (100 <= posicion.x && posicion.x < 130) {
            auxetsidi.Texto("Sabias que en españa se comen", posicion.x - 7, 0, 0, 0.1, 0.2, 8);
            auxetsidi.Texto("10 toneladas de tortilla de patata al dia?", posicion.x - 8, -1, 0, 0.1, 0.2, 8);
        } 
        else if (150 <= posicion.x && posicion.x < 200) {
            auxetsidi.Texto("Nos acercamos al ULTIMO foco de infeccion...", posicion.x - 7, -1, 0, 0.1, 0.2, 8);
        }
        else if (200 <= posicion.x && posicion.x < 250) {
            auxetsidi.Texto("Mata al virus final y consigue ", posicion.x - 7, 0, 0, 0.1, 0.2, 8);
            auxetsidi.Texto("LA CURA AL CORONAVIRUS ", posicion.x - 7, -1, 0, 0.1, 0.2, 8);
        }
        break;

    }
}
