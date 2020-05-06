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
    int monedas;
public:


    Hombre();
    virtual ~Hombre();
    void Dibuja(int pantalla);
    void Mueve(float t);
    void SetVel(float vx, float vy);
    ETSIDI::Vector2D GetVel() { return velocidad; }

    float altura, anchura;
    void Inicializa();
    void Salta();
    void SetVidas(int v) { vidas = v; }
    void SetMonedas(int m) { monedas = m; }
    //direccion del mu�eco
    void SetDir(int d) { dir = d; }
    void SetPos(float x, float y) { posicion.x = x; posicion.y = y; }
    int GetDir(){return dir;}
    int GetVidas(){ return vidas; }
    int GetMonedas() { return monedas; }
    void FinPartida();
    ETSIDI::Vector2D GetPos() { return posicion; }
    int GetPosX() { return posicion.x; }
    void SetAceleracion(float ax, float ay) {
        aceleracion.x = ax;
        aceleracion.y = ay;
    }
    ETSIDI::Vector2D GetAceleracion() { return aceleracion; }

   ETSIDI::Vector2D posicion, velocidad, aceleracion;

   ETSIDI::SpriteSequence* mario;
   ETSIDI::SpriteSequence* marioder;
   ETSIDI::SpriteSequence* marioizq;

   ETSIDI::SpriteSequence* mariomuerte;
   ETSIDI::SpriteSequence* mariovictoria;

  

};