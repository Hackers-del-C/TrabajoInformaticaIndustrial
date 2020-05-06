
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
    monedas= new Sprite("imagenes/moneda.png", h.posicion.x -20, 20, 2, 2);
}
void Vidas::Dibuja(Hombre& h, int vidas) {

    glTranslatef(posicion.x, posicion.y, 0);
    this->monedas->draw();
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
   //posiicon.x - 20, 20,
   switch (h.GetMonedas()) {
   case 0:
      // auxetsidi.Imagen("0", h.GetPos().x - 19, h.GetPos().x - 18, 19, 21);
       break;

   case 1:
       //auxetsidi.Imagen("1", h.GetPos().x - 19, h.GetPos().x - 18, 19, 21);
       break;
   case 2:
      // auxetsidi.Imagen("2", h.GetPos().x - 19, h.GetPos().x - 18, 19, 21);
       break;
   }
   
   glTranslatef(-posicion.x, -posicion.y, 0);
}
void Vidas::Mueve(float xojo) {
    posicion.x = xojo;
}