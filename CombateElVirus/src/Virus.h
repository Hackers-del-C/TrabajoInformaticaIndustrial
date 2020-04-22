#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
class Virus {
    friend class Interaccion;
public:
   Virus();
    virtual ~Virus();
    void Dibuja(int nivel);
    void Mueve(float t);
    void Inicializa();
    
    ETSIDI::Vector2D posicion, velocidad, aceleracion;
    ETSIDI::SpriteSequence* virusazul;
    ETSIDI::SpriteSequence* virusamarillo;
    ETSIDI::SpriteSequence* virusrojo;
};