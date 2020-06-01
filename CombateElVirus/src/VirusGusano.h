#pragma once
#include "Virus.h"



class VirusGusano : public Virus
{
    enum Estado { normal = 0, desaparece, aparece };

    Estado estado;
public:

    VirusGusano(float x, float y);
    ~VirusGusano();
    void Inicializa(float x, float y);
    VirusGusano();
  
    void Aparece();
   
    void Mueve(float t, ListaSlime& l, Hombre h);
    void finsequence(Estado e);
private:
    int mov;
};