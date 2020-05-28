#include "VirusBaba.h"


using namespace ETSIDI;
using namespace std;
using ETSIDI::getTexture;

VirusBaba::~VirusBaba() {

}

VirusBaba::VirusBaba() {

    
    anchura = 6*0.4;
    altura = 6*0.4;
    mov = 0;

}

VirusBaba::VirusBaba(float x, float y) {

    posicion.x = x;
    posicion.y = y;

    sprite = new SpriteSequence("imagenes/enemigos/virusbabaanda.png", 7, 1, 80, true, 0, 0, 6, 6);

}



void VirusBaba::Inicializa(float x, float y) {

    posicion.x = x;
    posicion.y = y;

    sprite = new SpriteSequence("imagenes/enemigos/virusbabaanda.png", 7, 1, 80, true, 0, 0, 6, 6);

}

void VirusBaba::Ataca() {

    sprite = new SpriteSequence("imagenes/enemigos/virusbabaataca.png", 1, 9, 90, false, 0, 0, 6, 6);

}

void VirusBaba::Desaparece() {

    sprite = new SpriteSequence("imagenes/enemigos/virusbabades.png", 1, 9, 90, false, 0, 0, 6, 6);

    
}

void VirusBaba::finsequence(Estado e, ListaSlime& l, Hombre h){

    if (sprite->getState() > 7 && mov == 1) {

    switch (e)
    {
    case normal:
        break;
    case ataca:
        //lanzar slime
      
        Dispara(l, h);
        sprite = new SpriteSequence("imagenes/enemigos/virusbabaanda.png", 7, 1, 80, true, 0, 0, 6, 6);
        mov = 0;
        break;
    case desaparece:

        
        switch (lanzaDado(3, 0))
        {
        case 1:
            posicion.x = 10;
            posicion.y = 10;
            
            break;
        case 2:
            posicion.x = -18;
            posicion.y = 10;
            break;
        case 3:
            posicion.x = 0;
            posicion.y = 10;
            break;

        }
        sprite = new SpriteSequence("imagenes/enemigos/virusbabaapar.png", 1, 9, 90, false, 0, 0, 6, 6);
        estado = aparece;
        mov = 1;
        
        break;
    case aparece:
        estado = normal;
        sprite = new SpriteSequence("imagenes/enemigos/virusbabaanda.png", 7, 1, 80, true, 0, 0, 6, 6);
        mov = 0;
        break;

    }
  
    }

}

void VirusBaba::Mueve(float t, ListaSlime& l, Hombre h) {

    posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
    velocidad = velocidad + aceleracion * t;
    if (h.GetPos().x < posicion.x) {
        sprite->flip(1, 0);
    }

    int aux = lanzaDado(200);

    if (aux< 3 && mov == 0) {
        Desaparece();
        estado = desaparece;
        mov = 1;
    }
   else if (aux< 4 && mov == 0) {
        Ataca();
        estado = ataca;
        mov = 1;
    }

    finsequence(estado, l, h);
    sprite->loop();

}

void VirusBaba::Dispara(ListaSlime& l, Hombre h) {

    slime = new Slime(posicion.x, posicion.y);
 
   // slime->aceleracion.y = 0;
    if (h.GetPos().x < posicion.x) {
        slime->velocidad.x = -7;
  }
    else
        slime->velocidad.x = +7;

    l.agregar(slime);
   
}



