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
    Virus::Virus(string nombre, int m, int n, float x, float y, float w, float h, int izqder1, int salto1);
    virtual ~Virus();
    void Dibuja(int nivel);
    void Mueve(float t, Hombre hombre);
    void Inicializa(string nombre, int m, int n, float x, float y, float w, float h, int izqder, int salto);
    void SetVel(float x, float y);
    void Muere();
    ETSIDI::Vector2D posicion, velocidad, aceleracion;
    // ETSIDI::SpriteSequence* virusazul;
    ETSIDI::SpriteSequence* sprite;
    ETSIDI::SpriteSequence* spriteder;
    ETSIDI::SpriteSequence* spriteizq;
    ETSIDI::SpriteSequence* spritemuere;
    // ETSIDI::SpriteSequence* virusrojo;
private:

    int salto, izqder, muere;
};
