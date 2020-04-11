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

private:
    Pared suelo;
    Pared techo;
    Pared pared_izq;
    Pared pared_dcha;
   
};