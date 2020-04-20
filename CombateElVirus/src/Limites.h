//IMPLEMENTACION DE LA RELACION DE COMPOSICION
#pragma once
#include "Pared.h" //el include no es necesario que ponga “dominio”
 //porque ya estamos en dicha carpeta.
#include "ETSIDI.h"
class Limites
{
    friend class Interaccion;

public:
    Limites();
   virtual ~Limites();
   void Dibuja();
   ETSIDI::Vector2D posicion1, posicion2;

   void SetLimites(float x1, float x2, float y1, float y2);
   void SetLimites(Vector2D posicion1, Vector2D posicion2);

private:
    Pared suelo;
    Pared techo;
    Pared pared_izq;
    Pared pared_dcha;
   
};