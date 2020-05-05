#pragma once
#include "ETSIDI.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
class Bonus
{
    friend class Interaccion;
public:
    Bonus();
    virtual ~Bonus();
    float lado;
    void Dibuja();
    void Mueve(float t);
    void SetPos(float ix, float iy);
    float anchura, altura;
private:
   
    ETSIDI::Sprite* bonus;
    ETSIDI::Vector2D posicion;
    ETSIDI::Vector2D velocidad;
    ETSIDI::Vector2D aceleracion;
};