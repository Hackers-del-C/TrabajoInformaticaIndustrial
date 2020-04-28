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
    Interaccion();
    virtual ~Interaccion();
    static void reboteinterior(Hombre & h, Limites c);
    static void reboteexterior(Hombre& h, Limites c);
    static bool colision(Hombre h, Limites l);
    static bool colision(Hombre h, Plataformas p);
    static bool colision(ListaMisil& misiles, Hombre h);
};