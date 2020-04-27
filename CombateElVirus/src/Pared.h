#pragma once
#include "Vector2D.h"
#include"ETSIDI.h"

class Pared
{
  

private:
  
   
    unsigned char rojo;
    unsigned char verde;
    unsigned char azul;
    ETSIDI::Vector2D limite1;
    ETSIDI::Vector2D limite2;

public:
  
    void Dibuja();
    Pared();
    virtual ~Pared();
    void SetColor(unsigned char r, unsigned char v, unsigned char a);
    void SetPos(float x1, float y1, float x2, float y2);
    void SetPos(ETSIDI::Vector2D l1, ETSIDI::Vector2D l2);
    float distancia(ETSIDI::Vector2D punto, ETSIDI::Vector2D* direccion = 0);
    friend class Interaccion;
    float GetSuelo();
};
