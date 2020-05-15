
#pragma once

#include "Vector2D.h"
#include "ETSIDI.h"
#include "Disparo.h"

class DisparoEspecial: public Disparo
{
public:

    DisparoEspecial();
    DisparoEspecial(float r, float px, float py, float vx, float vy);
    ~DisparoEspecial();
    void Dibuja();
    void Mueve(float r);
    int Fin();
   // ETSIDI::SpriteSequence* shot;
  
private:

};