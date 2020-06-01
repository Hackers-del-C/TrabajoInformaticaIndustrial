#include "VirusGusano.h"


using namespace ETSIDI;
using namespace std;
using ETSIDI::getTexture;

VirusGusano::~VirusGusano() {

}

VirusGusano::VirusGusano() {


    anchura = 6 * 0.4;
    altura = 6 * 0.4;
    mov = 0;

}

VirusGusano::VirusGusano(float x, float y) {

    posicion.x = x;
    posicion.y = -10;
    vidas = 8;
    anchura = 3;
    altura =3;
    mov = 0;
    sprite = new SpriteSequence("imagenes/enemigos/gusanoagujero.png", 1, 1, 90, false, 0, 0, 3, 3);

}



void VirusGusano::Inicializa(float x, float y) {

    posicion.x = x;
    posicion.y = y;

    sprite = new SpriteSequence("imagenes/enemigos/gusanoagujero.png", 1, 1, 90, false, 0, 0, 3, 3);

}


void VirusGusano::Aparece() {

    sprite = new SpriteSequence("imagenes/enemigos/gusanoaparece.png", 8, 1, 120, false, 0, 0, 3, 3);


}

void VirusGusano::finsequence(Estado e) {

    if (sprite->getState() > 6 && mov == 1) {

        switch (e)
        {
        case normal:
            break;
        case desaparece:
            
            sprite = new SpriteSequence("imagenes/enemigos/gusanoagujero.png", 1, 1, 100, false, 0, 0, 3, 3);
            posicion.y = -20; //hacemos que desaparezca
           
            mov = 0;

            break;
        case aparece:
            estado = desaparece;
            sprite = new SpriteSequence("imagenes/enemigos/gusanodesaparece.png", 8, 1, 120, false, 0, 0, 3, 3);
            mov = 1;
            break;

        }

    }

}

void VirusGusano::Mueve(float t, ListaSlime& l, Hombre h) {

    if (h.GetPos().x < posicion.x) {
        sprite->flip(1, 0);
    }

    int aux = lanzaDado(200);



    if (aux <3 && mov == 0) {
        Aparece();
        estado = aparece;
       
        posicion.y = -3.5;
        mov = 1;
    }
   
    finsequence(estado);

    
    sprite->loop();

}


