//IMPLEMENTACION DE LA RELACION DE COMPOSICION
#include "Pared.h" //el include no es necesario que ponga “dominio”
 //porque ya estamos en dicha carpeta.
class Caja
{
public:
    Caja();
   //virtual ~Caja();
    Pared suelo;
    Pared techo;
    Pared pared_izq;
    Pared pared_dcha;
    void Dibuja();
};