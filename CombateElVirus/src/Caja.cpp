#include "Caja.h"
#include "glut.h"

void Caja::Dibuja()
{
    suelo.Dibuja();
    techo.Dibuja();
    pared_izq.Dibuja();
    pared_dcha.Dibuja();
}

Caja::Caja(){
    pared_dcha.SetColor(0, 110, 0);
    pared_izq.SetColor(0, 110, 0);
    techo.SetColor(0, 60, 0);
    suelo.SetColor(0, 60, 0);

    pared_dcha.limite1.x = 10;
    pared_dcha.limite1.y = 0;
    pared_dcha.limite2.x = 10;
    pared_dcha.limite2.y = 15;

    pared_izq.limite1.x = -10;
    pared_izq.limite1.y = 0;
    pared_izq.limite2.x = -10;
    pared_izq.limite2.y = 15;

    techo.limite1.x = -10;
    techo.limite1.y = 15;
    techo.limite2.x = +10;
    techo.limite2.y = 15;

    suelo.limite1.x = -10;
    suelo.limite1.y = 0;
    suelo.limite2.x = +10;
    suelo.limite2.y = 0;
   
}