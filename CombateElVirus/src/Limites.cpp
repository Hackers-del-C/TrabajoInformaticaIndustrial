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
void Limites::SetLimites(Vector2D posicion1, Vector2D posicion2) {

    suelo.SetPos(posicion1.x, posicion1.y, posicion2.x, posicion1.y);

    techo.SetPos(posicion1.x, posicion2.y, posicion2.x, posicion2.y);

    pared_dcha.SetPos(posicion2.x, posicion1.y, posicion2.x, posicion2.y);

    pared_izq.SetPos(posicion1.x, posicion1.y, posicion2.x, posicion2.y);
}




