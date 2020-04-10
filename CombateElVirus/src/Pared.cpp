#include "Pared.h"
#include "glut.h"

void Pared::Dibuja()
{
    glDisable(GL_LIGHTING);
    glColor3ub(rojo, verde, azul);
    glBegin(GL_POLYGON);
    glVertex3d(limite1.x, limite1.y, 10);
    glVertex3d(limite2.x, limite2.y, 10);
    glVertex3d(limite2.x, limite2.y, -10);
    glVertex3d(limite1.x, limite1.y, -10);
    glEnd();
    glEnable(GL_LIGHTING);
}




Pared::Pared() {


}

Pared:: ~Pared() {


}

void Pared::SetColor(unsigned char r, unsigned char v, unsigned char a) {
    rojo = r;
    verde = v;
    azul = a;

}