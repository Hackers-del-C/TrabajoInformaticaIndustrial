#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
//#include "ListaPlatafomas.h"
//#include "Interaccion.h"
class Hombre
{
    friend class Interaccion;
    int vidas;
    int dir;
public:


    Hombre();
    virtual ~Hombre();
    void Dibuja();
    void Mueve(float t);
    void SetVel(float vx, float vy);
    ETSIDI::Vector2D GetVel() { return velocidad; }

    float altura, anchura;
    void Inicializa();
    void Salta();
    void SetVidas(int v) { vidas = v; }
    //direccion del muñeco
    void SetDir(int d) { dir = d; }
    int GetDir(){return dir;}
    int GetVidas(){ return vidas; }
    void FinPartida();
    ETSIDI::Vector2D GetPos() { return posicion; }
    void SetAceleracion(float ax, float ay) {
        aceleracion.x = ax;
        aceleracion.y = ay;
    }
    ETSIDI::Vector2D GetAceleracion() { return aceleracion; }



   ETSIDI::Vector2D posicion, velocidad, aceleracion;
   ETSIDI::SpriteSequence* trump;
   ETSIDI::SpriteSequence* trumpder;
   ETSIDI::SpriteSequence* trumpizq;

   ETSIDI::SpriteSequence* mario;
   ETSIDI::SpriteSequence* marioder;
   ETSIDI::SpriteSequence* marioizq;

   ETSIDI::SpriteSequence* mariomuerte;
   

  

};