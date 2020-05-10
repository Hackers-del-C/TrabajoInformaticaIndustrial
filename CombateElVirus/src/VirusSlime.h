#pragma once
#include "Virus.h"
#include "ETSIDI.h"

#pragma once
class VirusSlime : public Virus
{
public:
    VirusSlime(float x, float y);
    ~VirusSlime();
    void Inicializa(float x, float y);
    void Seguir(Hombre h);
    VirusSlime();



};