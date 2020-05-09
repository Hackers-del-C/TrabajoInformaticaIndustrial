#pragma once
#include "Virus.h"
#include "ETSIDI.h"

#pragma once
class VirusGusano : public Virus
{
public:
    VirusGusano(float x, float y);
    ~VirusGusano();
    void Inicializa(float x, float y);
    void Seguir(Hombre h);
    VirusGusano();



};