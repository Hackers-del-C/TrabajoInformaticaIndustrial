#pragma once

#include "Vector2D.h"
class Esfera
{
private:
    
   // virtual ~Esfera();
    unsigned char rojo;
    unsigned char verde;
    unsigned char azul;
    float radio;
    Vector2D posicion;
    Vector2D velocidad;
    Vector2D aceleracion;

public:
    void Mueve(float t);
    float GetRadio();
    void SetRadio(float r);
    void Dibuja();
    Esfera();
    void SetColor(unsigned char r, unsigned char v, unsigned char a);
    void SetPos(float ix, float iy);
};

