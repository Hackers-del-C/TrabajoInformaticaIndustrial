#include "Interaccion.h"


void Interaccion::rebote(Hombre& h, Caja c)
{
    float xmax1 = c.suelo.limite2.x;
    float xmin1 = c.suelo.limite1.x;
    if (h.posicion.x > xmax1)h.posicion.x = xmax1;
    if (h.posicion.x < xmin1)h.posicion.x = xmin1;

    float xmax2 = c.suelo.limite2.y;
    float xmin2 = c.suelo.limite1.y;
    if (h.posicion.y > xmax2)h.posicion.y = xmax2;
    if (h.posicion.y < xmin2)h.posicion.y = xmin2;
}

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



Interaccion::Interaccion() {

}
Interaccion::~Interaccion() {


}