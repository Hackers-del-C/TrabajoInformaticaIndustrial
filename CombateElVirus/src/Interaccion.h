#pragma once
#include "Hombre.h"
#include "Limites.h"
#include "Pared.h"

class Interaccion
{
public:
    static void reboteinterior(Hombre & h, Limites c);
    static void reboteexterior(Hombre& h, Limites c);
    //static bool rebote(Esfera& e, Pared p);
   // static bool rebote(Esfera& e, Caja c);
    Interaccion();
    virtual ~Interaccion();
};