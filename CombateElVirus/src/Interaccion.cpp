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
   
}
bool Interaccion::colision(Hombre h, Limites l) {
    ETSIDI::Vector2D dir;
    float dif = h.GetPos().y - l.suelo.GetSuelo();
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
  /*  float px, py, distancia;
    px = misil.posicion.x; // En principio son iguales
    if (px < h.posicion.x - 22) px = h.posicion.x - 22;
    if (px > h.posicion.x - 22 + h.anchura) px = h.posicion.x - 22 + h.anchura;
    py = misil.posicion.y;
    if (py < misil.posicion.y + 2) py = misil.posicion.y + 2;
    if (py > misil.posicion.y + 2 + h.altura) py = h.posicion.y + 2 + h.altura;
    distancia = sqrt((misil.posicion.x - px) * (misil.posicion.x - px) + (misil.posicion.y - py) * (misil.posicion.y - py));
    //distancia = sqrt((misil.posicion.x - h.posicion.x) * (misil.posicion.x - h.posicion.x) + (misil.posicion.y - h.posicion.y) * (misil.posicion.y - h.posicion.y));
    if (distancia <= h.anchura / 2) {
        // Colisión detectada
        return true;
    }
    return false;
*/
    
    if (h.posicion.x -20> misil.posicion.x - misil.anchura) { return false; }
    if (h.posicion.x + h.anchura-20 < misil.posicion.x) { return false; }
    if (h.posicion.y -40 > misil.altura + misil.posicion.y) { return false; }
    if (h.posicion.y +2  < misil.posicion.y) { return false; }
    else {
        return true;
    }
    
}
//bool Interaccion::Colision(Hombre h, Plataformas p) {
//    ETSIDI::Vector2D  dir;
//    float dif = p.distancia(h.GetPos(), &dir) - h.altura; //antes no estaba lo de -h.altura pero no se si arregla algo o lo empeora
//    if (dif <= 0.0f) {
//        return true;
//    }
//    return false;
//}

bool Interaccion::Colision(Plataformas p, Zapatos z) {
    ETSIDI::Vector2D  dir;
    float dif = p.distancia(z.GetPos(), &dir) - z.GetRadio();
    if (dif <= 0.75f) {

        return true;
    }
    return false;
}

bool Interaccion::Colision(Disparo d, Virus &v) {

    float px, py;
    ETSIDI::Vector2D  aux;
    px = d.posicion.x; // En principio son iguales
    if (px < v.posicion.x-v.anchura/2) px = v.posicion.x - v.anchura / 2;
    if (px > v.posicion.x + v.anchura/2) px = v.posicion.x + v.anchura/2;
    py = d.posicion.y;
    if (py < v.posicion.y-v.altura/2) py = v.posicion.y - v.altura / 2;
    if (py > v.posicion.y + v.altura/2) py = v.posicion.y + v.altura/2;
    aux.x = (d.posicion.x - px) * (d.posicion.x - px);
    aux.y = (d.posicion.y - py) * (d.posicion.y - py);
    if (aux.module() < d.radio) {
        // Colisión detectada
        
        
       v.Muere(aux);
        return true;
    }
    return false;
}

bool Interaccion::Colision(Hombre h, Virus v) {

   //Crea un recatangulo en centro hombre, altura la altura del hombre y anchura la anchura del hombre.
    //SIRVE PARA DETECTAR COLISIONES ENTRE ELEMENTOS RECTANGULARES
    if (h.posicion.x-h.anchura/2 > v.posicion.x + v.anchura/2) { return false; }
    if (h.posicion.x + h.anchura/2 < v.posicion.x- v.anchura/2) { return false; }
    if (h.posicion.y -h.altura/2> v.altura/2 + v.posicion.y) { return false; }
    if (h.posicion.y + h.altura/2 < v.posicion.y-v.altura/2) { return false; }
    else {
        return true;
    }

}

bool Interaccion::colision(Hombre h, Bonus  b) {
   if (h.posicion.x - h.anchura / 2 > b.posicion.x + b.anchura / 2) { return false; }
    if (h.posicion.x + h.anchura / 2 < b.posicion.x - b.anchura / 2) { return false; }
   if (h.posicion.y - h.altura / 2 > b.altura / 2 + b.posicion.y) { return false; }
    if (h.posicion.y + h.altura / 2 < b.posicion.y - b.altura / 2) { return false; }
    else {
        return true;
   }
}


bool Interaccion::Colision(Hombre h, Plataformas p) {

    //Crea un recatangulo en centro hombre, altura la altura del hombre y anchura la anchura del hombre.
     //SIRVE PARA DETECTAR COLISIONES ENTRE ELEMENTOS RECTANGULARES
    if (h.posicion.x - h.anchura / 2 > p.posicion.x + p.anchura / 2) { return false; }
    if (h.posicion.x + h.anchura / 2 < p.posicion.x - p.anchura/2) { return false; }
    if (h.posicion.y - h.altura / 2 > p.altura / 2 + p.posicion.y) { return false; }
    if (h.posicion.y + h.altura / 2 < p.posicion.y - p.altura / 2) { return false; }
    else {
        return true;
    }

}
bool Interaccion::ColisionSube(Hombre &h, Plataformas p) {

    //Crea un recatangulo en centro hombre, altura la altura del hombre y anchura la anchura del hombre.
     //SIRVE PARA DETECTAR COLISIONES ENTRE ELEMENTOS RECTANGULARES
    if (h.posicion.x - h.anchura / 2.5 > p.posicion.x + p.anchura / 2.5) { return false; }
    if (h.posicion.x + h.anchura / 2.5 < p.posicion.x - p.anchura / 2.5) { return false; }
    if (h.posicion.y - h.altura / 2 > p.altura / 2 + p.posicion.y) { return false; }
    if (h.posicion.y + h.altura / 2 < p.posicion.y - p.altura / 2) { return false; }
    else {
        if (h.GetVel().y < 0.0 && h.posicion.y >= p.posicion.y+ p.anchura /4) {
            if (h.posicion.y <= p.posicion.y + p.anchura / 2.5) {
                h.posicion.y = p.posicion.y + p.anchura / 2.5;
                    return true;
            }
            
        }
        else {
            return false;
        }
    }

}
bool Interaccion::ColisionChoca(Hombre& h, Plataformas p) {

    //Crea un recatangulo en centro hombre, altura la altura del hombre y anchura la anchura del hombre.
     //SIRVE PARA DETECTAR COLISIONES ENTRE ELEMENTOS RECTANGULARES
    if (h.posicion.x - h.anchura / 2.5 > p.posicion.x + p.anchura / 2.5) { return false; }
    if (h.posicion.x + h.anchura / 2.5 < p.posicion.x - p.anchura / 2.5) { return false; }
    if (h.posicion.y - h.altura / 2 > p.altura / 2 + p.posicion.y) { return false; }
    if (h.posicion.y + h.altura / 2 < p.posicion.y - p.altura / 2) { return false; }
    else {
        if (h.GetVel().y > 0.0) {
            return true;
    
        }
        else {
            return false;
        }
    }
}
bool Interaccion::ColisionChocaLado(Hombre &h, Plataformas p) {

    //Crea un recatangulo en centro hombre, altura la altura del hombre y anchura la anchura del hombre.
     //SIRVE PARA DETECTAR COLISIONES ENTRE ELEMENTOS RECTANGULARES
    if (h.posicion.x - h.anchura / 2.5> p.posicion.x + p.anchura / 2.2) { return false; }
    if (h.posicion.x + h.anchura / 2.5 < p.posicion.x - p.anchura / 2.2) { return false; }
    if (h.posicion.y - h.altura / 2 > p.altura / 2 + p.posicion.y) { return false; }
    if (h.posicion.y + h.altura / 2 < p.posicion.y - p.altura / 2) { return false; }
    else {

         if (h.GetVel().y < 0.0 && h.posicion.y < p.posicion.y + p.altura / 2.5  ) {

            return true;
        }
        else {
            return false;
        }
    }
}
bool Interaccion::ColisionChocaLadoIzq(Hombre& h, Plataformas p) {

    //Crea un recatangulo en centro hombre, altura la altura del hombre y anchura la anchura del hombre.
     //SIRVE PARA DETECTAR COLISIONES ENTRE ELEMENTOS RECTANGULARES
    if (h.posicion.x - h.anchura / 2.2 > p.posicion.x + p.anchura / 2.2) { return false; }
    if (h.posicion.x + h.anchura / 2.2 < p.posicion.x - p.anchura / 2.2) { return false; }
    if (h.posicion.y - h.altura / 2 > p.altura / 2 + p.posicion.y) { return false; }
    if (h.posicion.y + h.altura / 2 < p.posicion.y - p.altura / 2) { return false; }
    else {

        if (h.GetVel().y < 0.0 && h.posicion.y < p.posicion.y + p.anchura / 2.5) {
            if (h.posicion.x >= p.posicion.x - p.anchura / 2) {
                h.posicion.x = p.posicion.x - p.anchura / 2;
                return true;
            }

        }
        else {
            return false;
        }
    }
}
void Interaccion::reboteexterior(Hombre& h,Limites c)
{
    float xmax = c.suelo.limite2.x;
   float xmin = c.suelo.limite1.x;
  float ymax = c.techo.limite1.y;
    float ymin = c.suelo.limite2.y;

  
    if (h.posicion.x > xmin && h.posicion.x < xmax && h.posicion.y>ymin && h.posicion.y<ymax)h.posicion.x = xmin;
   if (h.posicion.x > xmin && h.posicion.x < xmax && h.posicion.y > ymin)h.posicion.y = ymin;
    if (h.posicion.x > xmin && h.posicion.x < xmax && h.posicion.y < ymax)h.posicion.y = ymax;
  
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
 

  