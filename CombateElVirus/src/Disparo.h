
#pragma once
#include "Vector2D.h"

class Disparo
{
public:
    Disparo();
     virtual ~Disparo();
     void Dibuja();
     void Mueve(float r);
     void SetPos(float ix, float iy);
     void SetOri(float ix, float iy);

private:
    float radio;
    Vector2D posicion;
    Vector2D velocidad;
    Vector2D aceleracion;
    Vector2D origen;
   
};