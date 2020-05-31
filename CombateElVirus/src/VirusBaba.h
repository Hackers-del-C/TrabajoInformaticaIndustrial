#pragma once
#include "Virus.h"
#include "ETSIDI.h"
#include "ListaSlime.h"
#include "Slime.h"
#include "ListaDisparos.h"
#include "ListaExplosiones.h"

class VirusBaba : public Virus
{
    enum Estado { normal = 0, ataca, desaparece, aparece};
    
    Estado estado;
public:
    
    VirusBaba(float x, float y);
    ~VirusBaba();
    void Inicializa(float x, float y);
    VirusBaba();
    void Ataca();
    void Desaparece();
    void Disparafinal(ListaSlime& l, Hombre h);
    void Mueve(float t, ListaSlime& l, Hombre h);
    void finsequence(Estado e, ListaSlime& l, Hombre h);
private:
    int mov;
    
    Slime* slime;
};