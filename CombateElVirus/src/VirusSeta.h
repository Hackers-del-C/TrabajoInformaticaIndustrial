#include "Virus.h"
#include "ETSIDI.h"

#pragma once
class VirusSeta : public Virus 
{
    public:
    VirusSeta(float x, float y);
    ~VirusSeta();
    void Inicializa(float x, float y);
    void Seguir(Hombre h);
    VirusSeta();



};