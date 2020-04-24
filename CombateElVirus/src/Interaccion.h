#pragma once
#
#include "Hombre.h"
#include "Limites.h"
#include "Pared.h"
#include "ListaDisparos.h"
#include "Listalanzamisiles.h"
#include "Listalanzamisiles.h"
#include "Listamisiles.h"
#include "Mundo.h"
class Interaccion
{
public:
    static void reboteinterior(Hombre & h, Limites c);
    static void reboteexterior(Hombre& h, Limites c);
    //static bool rebote(Esfera& e, Pared p);
   // static bool rebote(Esfera& e, Caja c);
    Interaccion();
    virtual ~Interaccion();


    static bool colision(ListaMisil& misiles, Hombre h);
};