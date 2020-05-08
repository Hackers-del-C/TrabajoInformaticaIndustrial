#pragma once
#pragma once

#include "ETSIDI.h"


class Slime
{
public:
    Slime(float x, float y);
    ~Slime();
    void Inicializa(float x, float y);
    Slime();
    void Choca();
    void Goto(float x, float y);
    void Mueve(float t);
    void Dibuja();
    void SetVel(float x, float y);
    
    ETSIDI::SpriteSequence* sprite;
    ETSIDI::Vector2D posicion, velocidad, aceleracion;
    float anchura, altura;
    int chocar;

};