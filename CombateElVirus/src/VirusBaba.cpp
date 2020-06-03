#include "VirusBaba.h"
#include "Billete.h"

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
    vidas = 6;
    anchura = 6 * 0.4;
    altura = 6 * 0.4;
    mov = 0;
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
      
        Disparafinal(l, h);
        sprite = new SpriteSequence("imagenes/enemigos/virusbabaanda.png", 7, 1, 80, true, 0, 0, 6, 6);
        mov = 0;
        break;
    case desaparece:

        
        switch (lanzaDado(8, 1))
        {
        case 1:
            posicion.x = 239;
            posicion.y = 9.5;
            
            break;
        case 2:
            posicion.x = 239;
            posicion.y = 15.5;
            break;
        case 3:
            posicion.x = 239;
            posicion.y = 21.5;
            break;
        case 4:
            posicion.x = 201;
            posicion.y = 9.5;
            break;
        case 5:
            posicion.x = 201;
            posicion.y = 15.5;
            break;
        case 6:
            posicion.x = 201;
            posicion.y = 21.5;
            break;
        case 7:
            posicion.x = 220;
            posicion.y = 18.5;
            break;;
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

    if (aux< 7 && mov == 0) {
        Desaparece();
        estado = desaparece;
        mov = 1;
    }
   else if (aux< 15 && mov == 0) {
        Ataca();
        estado = ataca;
        mov = 1;
    }

    finsequence(estado, l, h);
    sprite->loop();

}

void VirusBaba::Disparafinal(ListaSlime& l, Hombre h) {

    slime = new Slime(posicion.x, posicion.y);
 
   // slime->aceleracion.y = 0;
    if (h.GetPos().x < posicion.x) {
        slime->velocidad.x = -lanzaDado(10, 5);
  }
    else
        slime->velocidad.x = +lanzaDado(10, 5);

    l.agregar(slime);
   
}
void VirusBaba::LanzaBonus(ListaBonus& l, int nivel) {
    if (nivel == 3) {
        l.agregar(new Billete(225, 10, 4, 4,'p'));
    }
}

