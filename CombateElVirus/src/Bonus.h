#pragma once
#include "ETSIDI.h"
class Bonus
{
public:
    Bonus();
    virtual ~Bonus();
    float lado;
    void Dibuja();
    void Mueve(float t);
    void SetPos(float ix, float iy);

private:
    
    ETSIDI::Vector2D posicion;
    ETSIDI::Vector2D velocidad;
    ETSIDI::Vector2D aceleracion;
};