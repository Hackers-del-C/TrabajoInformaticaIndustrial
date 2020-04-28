#include "Plataformas.h"

#include "glut.h"
Plataformas::Plataformas() {
    limite1.x = 0;
    limite2.x = 0;
    limite1.y = 0;

    limite2.y = 0;
}
Plataformas::Plataformas(float x1, float y1, float x2, float y2) {
    limite1.x = x1;
    limite1.y = y1;

    limite2.x = x2;
    limite2.y = y2;
}

void Plataformas::Dibuja() {
    glDisable(GL_LIGHTING);
    glColor3ub(1, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3d(limite1.x, limite1.y, 0);
    glVertex3d(limite1.x, limite2.y, 0);
    glVertex3d(limite2.x, limite2.y, 0);
    glVertex3d(limite2.x, limite1.y, 0);
    glEnd();
    glEnable(GL_LIGHTING);
}

