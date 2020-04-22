#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Virus {
    friend class Interaccion;
public:
    Virus();
    virtual ~Virus();
    void Dibuja(int nivel);
    void Mueve(float t);
    void Inicializa(char perro[20]);
    void SetVel(float x, float y);

    ETSIDI::Vector2D posicion, velocidad, aceleracion;
    // ETSIDI::SpriteSequence* virusazul;
    ETSIDI::SpriteSequence* sprite;
    // ETSIDI::SpriteSequence* virusrojo;
};
