#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Hombre.h"
#include "ListaSlime.h"


using namespace std;

class Virus {
    friend class Interaccion;
public:
    void OnTimer(int value);
    Virus();
    virtual ~Virus();
    void Dibuja(int nivel);
    void Mueve(float t);
    void SetVel(float x, float y);
    virtual void Muere();
    virtual void Dispara(ListaSlime& l); //Para la mosca
    void Ataca();
    void Anda();
    int GetVidas();

    void SetVidas(int v);
    virtual void Seguir(Hombre h);
    int GetMuerto() { return muere; }
    ETSIDI::Vector2D posicion, velocidad, aceleracion, vectormuerte, posicionini;
    float anchura, altura;
    // ETSIDI::SpriteSequence* virusazul;
    ETSIDI::SpriteSequence* sprite;
    ETSIDI::SpriteSequence* spriteder;
    ETSIDI::SpriteSequence* spriteizq;
    ETSIDI::SpriteSequence* spritemuere;
    ETSIDI::SpriteSequence* spriteataca;
    // ETSIDI::SpriteSequence* virusrojo;
protected:
    //Acciones
    int muere, vidas, recorrido;
 
};
