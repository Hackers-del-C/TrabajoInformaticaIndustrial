//IMPLEMENTACION DE LA RELACION DE COMPOSICION
#pragma once
#include "Pared.h" //el include no es necesario que ponga “dominio”
 //porque ya estamos en dicha carpeta.
class Caja
{
    friend class Interaccion;

public:
    Caja();
   virtual ~Caja();
   void Dibuja();
   void SetCaja(float x1, float x2, float y1, float y2);
  

private:
    Pared suelo;
    Pared techo;
    Pared pared_izq;
    Pared pared_dcha;
   
};