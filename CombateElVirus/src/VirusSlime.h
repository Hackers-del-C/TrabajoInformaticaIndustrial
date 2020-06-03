#pragma once
#include "Virus.h"
#include "ETSIDI.h"

#pragma once
class VirusSlime : public Virus
{
public:
    VirusSlime(float x, float y, float r);
 
    ~VirusSlime();
    void Inicializa(float x, float y);
    void Seguir(Hombre h);
    VirusSlime();
    void LanzaBonus(ListaBonus& l, int nivel);

};