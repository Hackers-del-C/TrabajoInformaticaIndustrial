
#pragma once

#include "Vector2D.h"


class Disparo
{
public:
    Disparo();
    Disparo(float r, float px, float py, float vx, float vy);
     virtual ~Disparo();
     void Dibuja();
     void Mueve(float r);
     void SetPos(float ix, float iy);
     void SetOri(float ix, float iy);
    

    float radio;


private:
    Vector2D posicion;
    Vector2D velocidad;
    Vector2D aceleracion;
    Vector2D origen;
    
};