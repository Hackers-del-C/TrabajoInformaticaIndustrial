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

      //return h.gokuizq->collides(*misil.misil);
      float px, py, distancia;
      px = misil.posicion.x; // En principio son iguales
      if (px < h.posicion.x-22) px = h.posicion.x-22;
      if (px > h.posicion.x-22 + h.anchura) px = h.posicion.x-22+h.anchura;
      py = misil.posicion.y;
      if (py < misil.posicion.y+2) py = misil.posicion.y+2;
      if (py > misil.posicion.y+2 + h.altura) py = h.posicion.y+2 + h.altura;
      distancia = sqrt((misil.posicion.x  - px) * (misil.posicion.x - px) + (misil.posicion.y - py) * (misil.posicion.y - py));
      //distancia = sqrt((misil.posicion.x - h.posicion.x) * (misil.posicion.x - h.posicion.x) + (misil.posicion.y - h.posicion.y) * (misil.posicion.y - h.posicion.y));
      if (distancia <=h.anchura/2){
          // Colisión detectada
          return true;
      }
      return false;

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

 bool Interaccion::Colision(Disparo d, Virus v)  {
      
     // Disparo centro y radio r
 // Rectángulo con esquina superior izquierda en (x,y) ancho w y algo h
 // Punto (en verde) del perímetro del rectángulo más cercano a la circunferencia en (px,py)
     //float px, py, distancia;
     //px = d.posicion.x; // En principio son iguales
     //if (px < v.posicion.x) px = v.posicion.x;
     //if (px > v.posicion.x + v.anchura) px = v.posicion.x + v.anchura;
     //py = d.posicion.y;
     //if (py < v.posicion.y) py = v.posicion.y;
     //if (py > v.posicion.y + v.altura) py = v.posicion.y + v.altura;
     //distancia = sqrt((d.posicion.x - px) * (d.posicion.x - px) + (d.posicion.y - py) * (d.posicion.y - py));
     //if (distancia < d.radio) {
     //    // Colisión detectada
     //    return true;
     //}
     //return false;

     float px, py, distancia;
     px = d.posicion.x; // En principio son iguales
     if (px < v.posicion.x) px = v.posicion.x;
     if (px > v.posicion.x + v.anchura) px = v.posicion.x + v.anchura;
     py = d.posicion.y;
     if (py < d.posicion.y) py = d.posicion.y;
     if (py > d.posicion.y + v.altura) py = d.posicion.y + v.altura;
     distancia = sqrt((d.posicion.x - px) * (d.posicion.x - px) + (d.posicion.y - py) * (d.posicion.y - py));
     if (distancia < d.radio) {
        // Colisión detectada
        return true;
     }
     return false;
 }

 bool Interaccion::Colision(Hombre h , Virus v) {

     // Rectángulo 1 con esquina superior izquierda en (x1,y1) ancho w1 y alto h1
  // Rectángulo 2 con esquina superior izquierda en (x2,y2) ancho w2 y alto h2
     if (h.posicion.x > v.posicion.x + v.anchura) { return false; }
      if(h.posicion.x + h.anchura < v.posicion.x) { return false; }
        if(h.posicion.y > v.altura + v.posicion.y ) { return false;}
         if(h.posicion.y + h.altura < v.posicion.y) { return false;}
         else {
             return true;
         }

 }