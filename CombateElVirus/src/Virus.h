#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Hombre.h"

using namespace std;

class Virus {
    friend class Interaccion;
public:
    
    Virus();
    virtual ~Virus();
    void Dibuja(int nivel);
    void Mueve(float t, Hombre hombre);
    void SetVel(float x, float y);
    void Muere(ETSIDI::Vector2D vectormuerte);
    int GetMuerto() { return muere; }
    ETSIDI::Vector2D posicion, velocidad, aceleracion, vectormuerte;
    float anchura, altura;
    // ETSIDI::SpriteSequence* virusazul;
    ETSIDI::SpriteSequence* sprite;
    ETSIDI::SpriteSequence* spriteder;
    ETSIDI::SpriteSequence* spriteizq;
    ETSIDI::SpriteSequence* spritemuere;
    // ETSIDI::SpriteSequence* virusrojo;
protected:

    int salto, izqder, muere;
};
