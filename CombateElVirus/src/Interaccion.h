#pragma once
#
#include "Hombre.h"
#include "Limites.h"
#include "Pared.h"
//#include "ListaDisparos.h"
#include "Listalanzamisiles.h"
#include "Listamisiles.h"
#include "Misil.h"
#include "Mundo.h"
#include "Zapatos.h"
#include "Virus.h"
#include "Disparo.h"
#include "Interaccion.h"
//#include "Bonus.h"
#include"BonusMascarilla.h"

class Interaccion
{
public:
    Interaccion();
    virtual ~Interaccion();
    static void reboteinterior(Hombre & h, Limites c);
    static void reboteexterior(Hombre& h, Limites c);
    static bool colision(Hombre h, Limites l);
    static bool colision(Hombre h, Plataformas p);

    //static bool colision(ListaMisil& misiles, Hombre h);

    static bool Colision (Disparo d,  Virus &v);

    static bool Colision(Hombre h, Virus v);
    static bool colision(Misil misil, Hombre h);
    static bool colision(Hombre h, Bonus b);
    static bool Colision(Hombre h, Plataformas p);
    static bool ColisionSube(Hombre &h, Plataformas p);
    static bool ColisionChoca(Hombre &h, Plataformas p);
    static bool ColisionChocaLado(Hombre &h, Plataformas p);
    static bool ColisionChocaLadoIzq(Hombre& h, Plataformas p);
    static bool ColisionChocaLadoDer(Hombre& h, Plataformas p);
    static bool  Colision(Plataformas p, Zapatos z);

    static void Colision(BonusMascarilla& b, Limites c);



    ETSIDI::Vector2D Distancia;
    
};