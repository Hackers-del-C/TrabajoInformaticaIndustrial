#pragma once
#include "Virus.h"
#include "ETSIDI.h"


class VirusBaba : public Virus
{
public:
    VirusBaba(float x, float y);
    ~VirusBaba();
    void Inicializa(float x, float y);
    VirusBaba();
    void Ataca();
    void Desaparece();
    int Fin();
    void Mueve(float t);

};