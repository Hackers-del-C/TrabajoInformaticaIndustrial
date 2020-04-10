#include "Interaccion.h"


void Interaccion::rebote(Hombre& h, Caja c)
{
    float xmax = c.suelo.limite2.x;
    float xmin = c.suelo.limite1.x;
    if (h.posicion.x > xmax)h.posicion.x = xmax;
    if (h.posicion.x < xmin)h.posicion.x = xmin;
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
    Vector2D dir;
    float dif1 = c.suelo.distancia(e.posicion, &dir) - e.radio;
    float dif2 = c.pared_dcha.distancia(e.posicion, &dir) - e.radio;
    float dif3 = c.pared_izq.distancia(e.posicion, &dir) - e.radio;
    float dif4 = c.techo.distancia(e.posicion, &dir) - e.radio;
    if (dif1 <= 0.1f)
    {
        Vector2D v_inicial = e.velocidad;
        e.velocidad = v_inicial - dir * 2.0 * (v_inicial * dir);
        e.posicion = e.posicion - dir * dif1;
        return true;
    }

    if (dif2 <= 0.1f)
    {
        Vector2D v_inicial = e.velocidad;
        e.velocidad = v_inicial - dir * 2.0 * (v_inicial * dir);
        e.posicion = e.posicion - dir * dif2;
        return true;
    }
    if (dif3 <= 0.1f)
    {
        Vector2D v_inicial = e.velocidad;
        e.velocidad = v_inicial - dir * 2.0 * (v_inicial * dir);
        e.posicion = e.posicion - dir * dif3;
        return true;
    }
    if (dif4 <= 0.1f)
    {
        Vector2D v_inicial = e.velocidad;
        e.velocidad = v_inicial - dir * 2.0 * (v_inicial * dir);
        e.posicion = e.posicion - dir * dif4;
        return true;
    }

    return false;
}



Interaccion::Interaccion() {

}
Interaccion::~Interaccion() {


}