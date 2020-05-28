
#include "Vidas.h"
#include "Hombre.h"
#include "glut.h"

void Vidas::Inicializa(Hombre h) {
    ///// vidas
   
    vida1 = new Sprite("imagenes/mascarilla.png", h.posicion.x+11, 20, 2,2);
    vida2 = new Sprite("imagenes/mascarilla.png", h.posicion.x + 14, 20, 2, 2);
    vida3 = new Sprite("imagenes/mascarilla.png", h.posicion.x + 17, 20, 2, 2);
    vida4 = new Sprite("imagenes/mascarilla.png", h.posicion.x + 20,20, 2, 2);
    vida5 = new Sprite("imagenes/mascarilla.png", h.posicion.x + 23, 20, 2, 2);
    monedas= new Sprite("imagenes/test.png", h.posicion.x -20, 20.5, 2, 2);
    municion = new Sprite("imagenes/municion.png", h.posicion.x - 20, 17.5, 2, 2);
}
void Vidas::Dibuja(Hombre& h, int vidas) {

    glTranslatef(posicion.x, posicion.y, 0);
    this->monedas->draw();
    this->municion->draw();
    switch (vidas) {
    case 1:
        vida1->draw();
        break;
    case 2:
        vida1->draw();
        vida2->draw();
        break;
    case 3:
        vida1->draw();
        vida2->draw();
        vida3->draw();
        break;
    case 4:
        vida1->draw();
        vida2->draw();
        vida3->draw();
        vida4->draw();
        break;
    case 5:
        vida1->draw();
        vida2->draw();
        vida3->draw();
        vida4->draw();
        vida5->draw();
        break;
    }
    glTranslatef(-posicion.x, -posicion.y, 0);
    //posiicon.x - 20, 20,

    stringstream sstr;
    sstr << h.GetMonedas();

    auxetsidi.Texto(sstr.str(), posicion.x - 19, 20, 0, 0, 0, 20);

    stringstream sstr2;
    sstr2 << h.GetMunicion();

    auxetsidi.Texto(sstr2.str(), posicion.x - 19, 17, 0, 0, 0, 20);
}
void Vidas::Mueve(float xojo) {
    posicion.x = xojo;
}