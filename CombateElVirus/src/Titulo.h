#pragma once
#include "Menu.h"
#include "ETSIDI.h"
using namespace ETSIDI;
using ETSIDI::getTexture;
class Titulo {

public:
    void Nombre(int nivel);
    void Bandera(int nivel);
private:
    Menu menu;
};