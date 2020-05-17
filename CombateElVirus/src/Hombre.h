#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include "string.h"
//#include "ListaPlatafomas.h"
//#include "Interaccion.h"
class Hombre
{
    friend class Interaccion;
    int vidas;
    int dir;
    int monedas;
    bool agachado;
    int control;
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
    void Setagachado(unsigned char key);
    void SetControl(int c) { control = c; }
    int GetControl() { return control; }
    void Stop();
    void Victoria();
    void Agacha();
    int GetAgacha() { return agachado; }
    void SetVidas(int v) { vidas = v; }
    void Dañar();
    void SetMonedas(int m) { monedas = m; }
    //direccion del muñeco
    void SetDir(int d);
    void SetPos(float x, float y) { posicion.x = x; posicion.y = y; }
    int GetDir(){return dir;}
    int GetVidas(){ return vidas; }
    int GetMonedas() { return monedas; }
    void FinPartida();
    void SetSprite(int n);
    
    ETSIDI::Vector2D GetPos() { return posicion; }
    int GetPosX() { return posicion.x; }
    void SetAceleracion(float ax, float ay) {
        aceleracion.x = ax;
        aceleracion.y = ay;
    }

    void caida(int caida,int level);
    ETSIDI::Vector2D GetAceleracion() { return aceleracion; }

   ETSIDI::Vector2D posicion, velocidad, aceleracion;

   ETSIDI::SpriteSequence* mario;
   ETSIDI::SpriteSequence* mariomuerte;
   int mariorojo, test;


};