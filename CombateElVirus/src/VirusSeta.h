#include "Virus.h"
#include "ETSIDI.h"

#pragma once
class VirusSeta : public Virus 
{
    public:
    VirusSeta(float x, float y, float w, float h, int lateral, int ataque, int muere);
    ~VirusSeta();
    void Inicializa(float x, float y, float w, float h, int lateral, int ataque, int muere);
    void Seguir(Hombre h);
    VirusSeta();



};