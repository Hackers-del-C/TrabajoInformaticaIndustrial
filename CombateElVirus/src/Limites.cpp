#include "Limites.h"
#include "glut.h"

Limites::~Limites() {

}
Limites::Limites() {


}

void Limites::Dibuja()
{ 

}

void Limites::SetLimites(float x1, float x2, float y1, float y2) {


    suelo.SetPos(x1, y1, x2, y1);

    techo.SetPos(x1, y2, x2, y2);

    pared_dcha.SetPos(x2, y1, x2, y2);

    pared_izq.SetPos(x1, y1, x2, y2);

}



