#include "ETSIDI.h"
#include "glut.h"
#include <iostream>
#include "Vector2D.h"
#include <Time.h>
#include "Amigo.h"


void Amigo::Inicializa() {
    //compañero
    companionder = new SpriteSequence("imagenes/companionder.png", 1, 1, 100, true, 0, 0, 2, 2);
    companionizq = new SpriteSequence("imagenes/companionizq.png", 1, 1, 100, true, 0, 0, 2, 2);
    izqder = 0;
    posicion.x = -7;
  
}
void Amigo::Dibuja(Hombre h) {
   
   
    glTranslatef(posicion.x, posicion.y, 0);
    switch (h.GetDir()) {
    case 0:
      
        companionder->draw();
        switch (izqder) {
        case 0:  // muñeco a la izquierda del hombre            
            companionder->draw();
            if (h.GetPos().x - posicion.x >= 7 || h.GetPos().x - posicion.x <= -7) {
                posicion.x = h.GetPos().x - 7;
            }
            break;
        case 1:  //muñeco a la derecha
            companionizq->draw();
            if (h.GetPos().x - posicion.x >= 7 || h.GetPos().x - posicion.x <= -7) {
                izqder = 0;
            }
            break;
        }
        break;
    case 1: //// hombre yendo a la derecha
        switch (izqder) {
        case 0:  // muñeco a la izquierda del hombre            
            companionder->draw();
            if (h.GetPos().x - posicion.x >= 7 || h.GetPos().x - posicion.x <= -7) {
                posicion.x = h.GetPos().x - 7;
            }          
                break;
        case 1:  //muñeco a la derecha
            companionder->draw();
            if (h.GetPos().x - posicion.x >= 7 || h.GetPos().x - posicion.x <= -7) {
                izqder = 0;
            }
            break;
        }
  
        break;
    case 2:  ///hombre yendo a la izquierda
       
        switch (izqder) {
        case 0:  // muñeco a la izquierda del hombre
            companionder->draw();
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
  
    posicion.y = -2.8 +sin(2*3.14* clock());
    companionder->loop();
    companionizq->loop();
 
}

void Amigo::Mensajes(int level) {

    switch (level){
    case 1:
    if (posicion.x < 10) {
        auxetsidi.Texto("Ni hao!", posicion.x , 1, 0, 0.1, 0.2, 8);
        auxetsidi.Texto("Usa las teclas para moverte", posicion.x -3, 0, 0, 0.1, 0.2, 8);
        auxetsidi.Texto("Usa s,w,a,d para disparar", posicion.x -3, -1, 0, 0.1, 0.2, 8);

   }
    else if (10 <= posicion.x && posicion.x < 30) {
        auxetsidi.Texto("Coge los spray para poder disparar", posicion.x - 7, -1, 0, 0.1, 0.2, 8);
    }
    else if (50 <= posicion.x && posicion.x < 70) {
        auxetsidi.Texto("Pulsa la barra espaciadora para pararte", posicion.x - 7, -1, 0, 0.1, 0.2, 8);
    }
    else if (90 <= posicion.x && posicion.x < 110) {
        auxetsidi.Texto("A mayor numero de probetas mayor puntuacion ", posicion.x - 7, -1, 0, 0.1, 0.2, 8);
    }
    else if (115 <= posicion.x && posicion.x < 140) {
        auxetsidi.Texto("Las mascarillas te dan vidas", posicion.x - 7, -1, 0, 0.1, 0.2, 8);
    }
    else if (150 <= posicion.x && posicion.x < 200) {
        auxetsidi.Texto("Nos acercamos al foco de infeccion...", posicion.x - 7, -1, 0, 0.1, 0.2, 8);
    }
    else if (200 <= posicion.x && posicion.x < 250) {
        auxetsidi.Texto("Mata al virus Mosca y consigue  un billete", posicion.x - 7, 0, 0, 0.1, 0.2, 8);
        auxetsidi.Texto("de avion para combatir en otros paises ", posicion.x - 7, -1, 0, 0.1, 0.2, 8);
    }
    break;
    case 2:
        if (posicion.x < 10) {
            auxetsidi.Texto("Ciao!", posicion.x - 1, -1, 0, 0.1, 0.2, 8);
            auxetsidi.Texto("Vamos a por esos virus!", posicion.x - 6, -2, 0, 0.1, 0.2, 8);
           
        }
      
        else if (20 <= posicion.x && posicion.x < 50) {
            auxetsidi.Texto("cuidado con el suelo...", posicion.x - 7, -1, 0, 0.1, 0.2, 8);
        }
        
       
        else if (100 <= posicion.x && posicion.x < 130) {
            auxetsidi.Texto("Recuerda: Para una buena pizza tomar", posicion.x - 7, 0, 0, 0.1, 0.2, 8);
            auxetsidi.Texto("las manos te has de lavar", posicion.x - 8, -1, 0, 0.1, 0.2, 8);
        }
        else if (150 <= posicion.x && posicion.x < 200) {
            auxetsidi.Texto("Nos acercamos al foco de infeccion...", posicion.x - 7, -1, 0, 0.1, 0.2, 8);
        }
        else if (200 <= posicion.x && posicion.x < 250) {
            auxetsidi.Texto("Mata al virus  y consigue  un billete", posicion.x - 7, 0, 0, 0.1, 0.2, 8);
            auxetsidi.Texto("de avion para combatir en otros paises ", posicion.x - 7, -1, 0, 0.1, 0.2, 8);
        }
        break;
    case 3:
        if (posicion.x < 10) {
            auxetsidi.Texto("Holaaaa!", posicion.x - 3, 0, 0, 0.1, 0.2, 8);
            auxetsidi.Texto("Conseguiremos en Espana la cura?", posicion.x - 6, -1, 0, 0.1, 0.2, 8);
          

        }
        else if (10 <= posicion.x && posicion.x < 20) {
            auxetsidi.Texto("Para con el espacio", posicion.x - 4, 0, 0, 0.1, 0.2, 8);
            auxetsidi.Texto("Y sube la escalera saltando", posicion.x - 7, -1, 0, 0.1, 0.2, 8);
        }     
        else if (30 <= posicion.x && posicion.x < 70) {
            auxetsidi.Texto("CUIDADO, no te caigas...", posicion.x - 7, -1, 0, 0.1, 0.2, 8);
        }
        else if (100 <= posicion.x && posicion.x < 130) {
            auxetsidi.Texto("Recuerda: Lavate con jabon", posicion.x - 7, 0, 0, 0.1, 0.2, 8);
            auxetsidi.Texto("para comer un buen jamon", posicion.x - 8, -1, 0, 0.1, 0.2, 8);
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
