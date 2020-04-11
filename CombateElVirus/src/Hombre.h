#pragma once
#include "Vector2D.h"


class Hombre
{
    friend class Interaccion;
public:
    Hombre();
    virtual ~Hombre();
    void Dibuja();
    void Mueve(float t);
    void SetVel(float vx, float vy);
    float altura;
    Vector2D posicion;
    Vector2D velocidad;
    Vector2D aceleracion;

};