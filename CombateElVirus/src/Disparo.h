
#pragma once

#include "Vector2D.h"
#include "ETSIDI.h"

class Disparo
{
public:
    Disparo();
    Disparo(float r, float px, float py, float vx, float vy);
     virtual ~Disparo();
     virtual void Dibuja();
     virtual void Mueve(float r);
     void SetPos(float ix, float iy);
     void SetOri(float ix, float iy);
     virtual int Fin();
     ETSIDI::Vector2D posicion;
     ETSIDI::SpriteSequence* shot;
    float radio;


protected:
   
    ETSIDI::Vector2D velocidad;
    ETSIDI::Vector2D aceleracion;
    ETSIDI::Vector2D origen;
    
};