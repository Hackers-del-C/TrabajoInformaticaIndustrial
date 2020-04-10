#pragma once
#include "Vector2D.h"
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

    Vector2D posicion;
    Vector2D velocidad;
    Vector2D aceleracion;
};