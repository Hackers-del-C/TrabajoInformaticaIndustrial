#include "Virus.h"
#include "ETSIDI.h"

#pragma once
class VirusSeta : public Virus 
{
    public:
    VirusSeta(string nombre, int m, int n, float x, float y, float w, float h, int izqder1, int salto1);
    ~VirusSeta();
    void Inicializa(string nombre, int m, int n, float x, float y, float w, float h, int izqder1, int salto1);
    VirusSeta();



};