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
   
  
    if (h.posicion.x - h.anchura / 2 > misil.posicion.x + misil.anchura / 2) { return false; }
    if (h.posicion.x + h.anchura / 2 < misil.posicion.x - misil.anchura / 2) { return false; }
    if (h.posicion.y - h.altura / 2 > misil.altura / 2 + misil.posicion.y) { return false; }
    if (h.posicion.y + h.altura / 2 < misil.posicion.y - misil.altura / 2) { return false; }
    else {
        return true;
    }
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


bool Interaccion::Colision(Slime &s, Plataformas p) {

    //Crea un recatangulo en centro hombre, altura la altura del hombre y anchura la anchura del hombre.
     //SIRVE PARA DETECTAR COLISIONES ENTRE ELEMENTOS RECTANGULARES
    if (s.posicion.x - s.anchura / 2 > p.posicion.x + p.anchura / 2) { return false; }
    if (s.posicion.x + s.anchura / 2 < p.posicion.x - p.anchura / 2) { return false; }
    if (s.posicion.y - s.altura / 2 > p.altura / 2 + p.posicion.y) { return false; }
    if (s.posicion.y + s.altura / 2 < p.posicion.y - p.altura / 2) { return false; }
    else {
        s.Choca();
        return true;
    }

}
bool Interaccion::Colision(Slime& s, Limites l) {

    ETSIDI::Vector2D dir;
    float dif = s.posicion.x - l.suelo.GetSuelo(); //Cabrones
    if (s.posicion.y<-3.5) {
        s.Choca();
        s.SetVel(0, 0);
        s.aceleracion.y = 0;
        
        return true;
    }
    else { return false; }
}



bool Interaccion::ColisionBonus(Hombre &h, Bonus  b) { //Esto deberia ser bonusmascarillas

   if (h.posicion.x - h.anchura / 2 > b.posicion.x + b.anchura / 2) { return false; }
    if (h.posicion.x + h.anchura / 2 < b.posicion.x - b.anchura / 2) { return false; }
   if (h.posicion.y - h.altura / 2 > b.altura / 2 + b.posicion.y) { return false; }
    if (h.posicion.y + h.altura / 2 < b.posicion.y - b.altura / 2) { return false; }
    else {
        //if (h.GetVidas() <= 4) {
        //   // h.SetVidas(h.GetVidas() + 1);
        //}
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
       
            if (h.GetVel().y < 0.0 && h.posicion.y >= p.posicion.y + p.anchura / 4) {
                if (h.posicion.y <= p.posicion.y + p.altura * 1.75) {
                    h.posicion.y = p.posicion.y + p.altura * 1.75;

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
        if (p.GetTipo() == p.PLATAFORMA_CHOCA) {
            if (h.GetVel().y > 0.0) {
                return true;

            }
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

void Interaccion::Colision(BonusMascarilla& b, Limites c) {

    float ymin = c.suelo.limite1.y;
 
    if (b.posicion.y < ymin)b.posicion.y = ymin;


}

void Interaccion::Colision(BonusMascarilla& b, Plataformas p) {


    float ymin = p.posicion.y + p.altura / 2;

    if (b.posicion.x   > p.posicion.x - p.anchura / 2) {
        if (b.posicion.x < p.posicion.x + p.anchura / 2) {
            if (b.posicion.y < ymin+2)
                b.posicion.y = ymin+2;
        }
    }










   
   

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
 

  