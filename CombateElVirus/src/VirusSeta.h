#include "Virus.h"
#include "ETSIDI.h"

#pragma once
class VirusSeta : public Virus 
{
    public:
    VirusSeta(float x, float y, float recorrido);
    ~VirusSeta();
    void Inicializa(float x, float y);
    void Seguir(Hombre h);
    VirusSeta();
    void LanzaBonus(ListaBonus& l, int nivel);


};