#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"

class Hombre
{
    friend class Interaccion;
public:
    int vidas;
   
    Hombre();
    virtual ~Hombre();
    void Dibuja(int nivel);
    void Mueve(float t);
    void SetVel(float vx, float vy);
    float altura;
    void Inicializa();
    void Salta();
    void SetVidas(int v) { vidas = v; }
    int dir; //direccion del mu�eco

    ETSIDI::Vector2D GetPos() { return posicion; }
    void SetAceleracion(float ax, float ay) {
        aceleracion.x = ax;
        aceleracion.y = ay;
    }
   ETSIDI::Vector2D posicion, velocidad, aceleracion;
   ETSIDI::SpriteSequence* trump;
   ETSIDI::SpriteSequence* trumpder;
   ETSIDI::SpriteSequence* trumpizq;

   ETSIDI::SpriteSequence* goku;
   ETSIDI::SpriteSequence* gokuder;
   ETSIDI::SpriteSequence* gokuizq;

   ETSIDI::SpriteSequence* mu�eco;
   ETSIDI::SpriteSequence* mu�ecoder;
   ETSIDI::SpriteSequence* mu�ecoizq;

  

};