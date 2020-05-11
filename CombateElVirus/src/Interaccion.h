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
#include "Virus.h"
#include "Slime.h"
#include "Disparo.h"
#include "Interaccion.h"
//#include "Bonus.h"
#include"BonusMascarilla.h"

class Interaccion
{
public:
    Interaccion();
    virtual ~Interaccion();
    static bool reboteinterior(Hombre & h, Limites c);
    static void reboteexterior(Hombre& h, Limites c);
    static bool caida(Hombre& h, Limites l);
    static bool colision(Hombre h, Plataformas p);
    
    //static bool colision(ListaMisil& misiles, Hombre h);

    static bool Colision (Disparo d,  Virus &v);

    static bool Colision(Hombre h, Virus v);
    static bool colision(Misil misil, Hombre h);
    static bool ColisionBonus(Hombre &h, Bonus b);
    static bool Colision(Hombre h, Plataformas p);
    static bool ColisionSube(Hombre &h, Plataformas p);
    static bool ColisionChoca(Hombre &h, Plataformas p);
    static bool ColisionChocaLado(Hombre &h, Plataformas p);

    static bool Colision(Slime &s, Plataformas p);
    
    static bool Colision(Slime& s, Limites l);
    static void Colision(BonusMascarilla& b, Limites c);
    static void Colision(BonusMascarilla& b, Plataformas p);


    ETSIDI::Vector2D Distancia;
    
};