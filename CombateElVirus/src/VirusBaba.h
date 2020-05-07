#pragma once
#include "Virus.h"
#include "ETSIDI.h"


class VirusBaba : public Virus
{
public:
    VirusBaba(float x, float y, float w, float h, int lateral, int ataque, int muere);
    ~VirusBaba();
    void Inicializa(float x, float y, float w, float h, int lateral, int ataque, int muere);
    VirusBaba();



};