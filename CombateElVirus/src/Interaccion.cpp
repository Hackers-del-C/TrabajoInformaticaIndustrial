#include "Interaccion.h"
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

 bool Interaccion::colision(ListaMisil& misiles, Hombre h){
     for (int i = 0; i < misiles.lista.size(); i++) {
         if (misiles.lista[i]->posicion.x == h.posicion.x) {
             if (h.vidas >= 1) {
                 h.vidas--;
                 return TRUE;
             }
             
         }
     }
     return false;
 }

/*
bool Interaccion::rebote(Esfera& e, Pared p)
{
    Vector2D dir;
    float dif = p.distancia(e.posicion, &dir) - e.radio;
    if (dif <= 0.0f)
    {
        Vector2D v_inicial = e.velocidad;
        e.velocidad = v_inicial - dir * 2.0 * (v_inicial * dir);
        e.posicion = e.posicion - dir * dif;
        return true;
    }
    return false;
}

bool Interaccion::rebote(Esfera& e, Caja c) //CUTREEEEEEEEEEEEEEEEEEEEEEEEE
{
    return false;
}
*/


