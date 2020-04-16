#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"

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
    void Inicializa();
    int dir; //direccion del muñeco
   ETSIDI::Vector2D posicion, velocidad, aceleracion;
   ETSIDI::SpriteSequence* trump;
   ETSIDI::SpriteSequence* trumpder;
   ETSIDI::SpriteSequence* trumpizq;

};