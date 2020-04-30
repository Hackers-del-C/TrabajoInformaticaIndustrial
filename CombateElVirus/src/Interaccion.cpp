#include "Interaccion.h"
#include "math.h"
#include "glut.h"

Interaccion::Interaccion() {

}
Interaccion::~Interaccion() {


}
void Interaccion::reboteinterior(Hombre& h, Limites c)
{
    float xmax = c.suelo.limite2.x;
    float xmin = c.suelo.limite1.x;
    if (h.posicion.x > xmax)h.posicion.x = xmax;
    if (h.posicion.x < xmin)h.posicion.x = xmin;

    float ymax = c.techo.limite1.y;
    float ymin = c.suelo.limite1.y;
    if (h.posicion.y > ymax)h.posicion.y = ymax;
    if (h.posicion.y < ymin)h.posicion.y = ymin;
    /*
    float xmax = c.suelo.limite2.x;
    float xmin = c.suelo.limite1.x;
    float ymax = c.techo.limite1.y;
    float ymin = c.suelo.limite1.y;
    int enplataforma=0;
    int key=NULL;
    float distancia1 = sqrt((h.posicion.x - xmin) * (h.posicion.x - xmin) + (h.posicion.y - ymin) * (h.posicion.y - ymin));
    float distancia2 = sqrt((h.posicion.x - xmax) * (h.posicion.x - xmax) + (h.posicion.y - ymax) * (h.posicion.y - ymax));

    if (distancia1 < 0.1 || (h.posicion.y - ymax) == 0) {
        enplataforma = 1;
    }

    if (key == GLUT_KEY_UP) {
        enplataforma = 0;
    }
    if (enplataforma == 1) {
        h.posicion.y = ymax;
    }*/
}

void Interaccion::reboteexterior(Hombre& h,Limites c)
{
    float xmax = c.suelo.limite2.x;
    float xmin = c.suelo.limite1.x;
    float ymax = c.techo.limite1.y;
    float ymin = c.suelo.limite2.y;

    /*/
    if (h.posicion.x > xmin && h.posicion.x < xmax && h.posicion.y>ymin && h.posicion.y<ymax)h.posicion.x = xmin;
   if (h.posicion.x < xmax && h.posicion.x > xmin && h.posicion.y < ymax && h.posicion.y > ymin)h.posicion.x = xmax;
    if (h.posicion.x > xmin && h.posicion.x < xmax && h.posicion.y > ymin)h.posicion.y = ymin;
    if (h.posicion.x > xmin && h.posicion.x < xmax && h.posicion.y < ymax)h.posicion.y = ymax;*/
   
}

 /*bool Interaccion::colision(ListaMisil& misiles, Hombre h){
     for (int i = 0; i < misiles.lista.size(); i++) {
         if (misiles.lista[i]->posicion.x == h.posicion.x) { //// MODO TEST -- HAY QUE USAR MODULO DIFERENCIA POSICION
             misiles.DestruirContenido(i);
             //if (h.vidas >= 1) {

                 h.vidas--;
                 return TRUE;
            // }
             
         }
     }
     return false;
 }*/
  bool Interaccion::colision(Hombre h, Limites l) {
      ETSIDI::Vector2D dir;
      float dif = h.GetPos().y- l.suelo.GetSuelo() ;
      if (dif <= 0.0f) {


          return true;
      }
      return false;
 }

  bool Interaccion::colision(Misil misil, Hombre h) {
  /*    float distancia = (misil.posicion - h.posicion).module();
      if (distancia <= 0.0) {
          return true;
      }
      return false;*/

      return h.gokuizq->collides(*misil.misil);
  }
  bool Interaccion::Colision(Hombre h, Plataformas p) {
      ETSIDI::Vector2D  dir;
      float dif = p.distancia(h.GetPos(), &dir);
      if (dif <=0.0f) {


          return true;
      }
      return false;
  }
  bool Interaccion::Colision(Plataformas p, Zapatos z) {
      ETSIDI::Vector2D  dir;
      float dif = p.distancia(z.GetPos(), &dir)-z.GetRadio();
      if (dif <= 0.75f) {
          
          return true;
      }
      return false;
  }

 bool Interaccion::Colision(Hombre h, Virus v)  {
      
      return (h.gokuder->collides(*v.spriteder));
      
 }