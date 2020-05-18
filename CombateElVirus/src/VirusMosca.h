#pragma once
#include "Virus.h"
#include "ListaSlime.h"
#include "ListaBonus.h"
#include "ETSIDI.h"

#pragma once
class VirusMosca : public Virus
{
public:
    VirusMosca(float x, float y);
    ~VirusMosca();
    void Inicializa(float x, float y);
    void Seguir(Hombre h);
    VirusMosca();
    void Dispara(ListaSlime &l);
    void Muere();
    bool Billete();
private:
    bool billete;
};