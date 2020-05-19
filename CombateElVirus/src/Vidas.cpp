
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
   glTranslatef(-posicion.x, -posicion.y, 0);
   //posiicon.x - 20, 20,
   switch (h.GetMonedas()) {
   case 0:
       auxetsidi.Texto("x 0", posicion.x - 19, 20, 0, 0,0,20);
       break;

   case 1:
       auxetsidi.Texto("x 1", posicion.x - 19, 20, 0, 0, 0, 20);
       
       break;
   case 2:
       auxetsidi.Texto("x 2", posicion.x - 19, 20, 0, 0, 0, 20);
       break;
   case 3:
       auxetsidi.Texto("x 3", posicion.x - 19, 20, 0, 0, 0, 20);
       break;
   case 4:
       auxetsidi.Texto("x 4", posicion.x - 19, 20, 0, 0, 0, 20);
       break;

   case 5:
       auxetsidi.Texto("x 5", posicion.x - 19, 20, 0, 0, 0, 20);

       break;
   case 6:
       auxetsidi.Texto("x 6", posicion.x - 19, 20, 0, 0, 0, 20);
       break;
   case 7:
       auxetsidi.Texto("x 7", posicion.x - 19, 20, 0, 0, 0, 20);
       break;
   case 8:
       auxetsidi.Texto("x 8", posicion.x - 19, 20, 0, 0, 0, 20);
       break;

   case 9:
       auxetsidi.Texto("x 9", posicion.x - 19, 20, 0, 0, 0, 20);

       break;
   case 10:
       auxetsidi.Texto("x 10", posicion.x - 19, 20, 0, 0, 0, 20);
       break;
   case 11:
       auxetsidi.Texto("x 11", posicion.x - 19, 20, 0, 0, 0, 20);
       break;
   case 12:
       auxetsidi.Texto("x 12", posicion.x - 19, 20, 0, 0, 0, 20);
       break;

   case 13:
       auxetsidi.Texto("x 13", posicion.x - 19, 20, 0, 0, 0, 20);

       break;
   case 14:
       auxetsidi.Texto("x 14", posicion.x - 19, 20, 0, 0, 0, 20);
       break;
   case 15:
       auxetsidi.Texto("x 15", posicion.x - 19, 20, 0, 0, 0, 20);
       break;
   case 16:
       auxetsidi.Texto("x 16", posicion.x - 19, 20, 0, 0, 0, 20);
       break;

   case 17:
       auxetsidi.Texto("x 17", posicion.x - 19, 20, 0, 0, 0, 20);

       break;
   case 18:
       auxetsidi.Texto("x 18", posicion.x - 19, 20, 0, 0, 0, 20);
       break;
   case 19:
       auxetsidi.Texto("x 19", posicion.x - 19, 20, 0, 0, 0, 20);
       break;
   case 20:
       auxetsidi.Texto("x 20", posicion.x - 19, 20, 0, 0, 0, 20);
       break;
   }

   switch (h.GetMunicion()) {
   case 0:
       auxetsidi.Texto("x 0", posicion.x - 19, 17, 0, 0, 0, 20);
       break;

   case 1:
       auxetsidi.Texto("x 1", posicion.x - 19, 17, 0, 0, 0, 20);

       break;
   case 2:
       auxetsidi.Texto("x 2", posicion.x - 19, 17, 0, 0, 0, 20);
       break;
   case 3:
       auxetsidi.Texto("x 3", posicion.x - 19, 17, 0, 0, 0, 20);
       break;
   case 4:
       auxetsidi.Texto("x 4", posicion.x - 19, 17, 0, 0, 0, 20);
       break;

   case 5:
       auxetsidi.Texto("x 5", posicion.x - 19, 17, 0, 0, 0, 20);

       break;
   case 6:
       auxetsidi.Texto("x 6", posicion.x - 19, 17, 0, 0, 0, 20);
       break;
   case 7:
       auxetsidi.Texto("x 7", posicion.x - 19, 17, 0, 0, 0, 20);
       break;
   case 8:
       auxetsidi.Texto("x 8", posicion.x - 19, 17, 0, 0, 0, 20);
       break;

   case 9:
       auxetsidi.Texto("x 9", posicion.x - 19, 17, 0, 0, 0, 20);

       break;
   case 10:
       auxetsidi.Texto("x 10", posicion.x - 19, 17, 0, 0, 0, 20);
       break;
   case 11:
       auxetsidi.Texto("x 11", posicion.x - 19, 17, 0, 0, 0, 20);
       break;
   case 12:
       auxetsidi.Texto("x 12", posicion.x - 19, 17, 0, 0, 0, 20);
       break;

   case 13:
       auxetsidi.Texto("x 13", posicion.x - 19, 17, 0, 0, 0, 20);

       break;
   case 14:
       auxetsidi.Texto("x 14", posicion.x - 19, 17, 0, 0, 0, 20);
       break;
   case 15:
       auxetsidi.Texto("x 15", posicion.x - 19, 17, 0, 0, 0, 20);
       break;
   case 16:
       auxetsidi.Texto("x 16", posicion.x - 19, 17, 0, 0, 0, 20);
       break;

   case 17:
       auxetsidi.Texto("x 17", posicion.x - 19, 17, 0, 0, 0, 20);

       break;
   case 18:
       auxetsidi.Texto("x 18", posicion.x - 19, 17, 0, 0, 0, 20);
       break;
   case 19:
       auxetsidi.Texto("x 19", posicion.x - 19, 17, 0, 0, 0, 20);
       break;
   case 20:
       auxetsidi.Texto("x 20", posicion.x - 19, 17, 0, 0, 0, 20);
       break;
   }
   
  
}
void Vidas::Mueve(float xojo) {
    posicion.x = xojo;
}