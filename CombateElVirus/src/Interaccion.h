#pragma once
#include "Hombre.h"
#include "Caja.h"
#include "Esfera.h"
#include "Pared.h"

class Interaccion
{
public:
    static void rebote(Hombre & h, Caja c);
    static bool rebote(Esfera& e, Pared p);
    static bool rebote(Esfera& e, Caja c);
    Interaccion();
    virtual ~Interaccion();
};