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



    /*glDisable(GL_LIGHTING);
    glColor3ub(1, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3d(limite1.x, 2, 10);
    glVertex3d(limite1.x, 2, -10);
    glVertex3d(limite2.x, 2,-10);
    glVertex3d(limite2.x, 2, 10);
    glEnd();
    glEnable(GL_LIGHTING);*/


    //glDisable(GL_LIGHTING);
    //glColor3ub(1, 0, 1);
    //glBegin(GL_POLYGON);
    //glVertex3d(limite1.x, 5, limite1.y);
    //glVertex3d(limite1.x, 5, limite2.y);
    //glVertex3d(limite2.x, 5, limite2.y);
    //glVertex3d(limite2.x, 5, limite1.y);
    //glEnd();
    //glEnable(GL_LIGHTING);



    /*
    glDisable(GL_LIGHTING);
    glColor3ub(1, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3d(limite1.x - 0.5, limite1.y, 0);
    glVertex3d(limite1.x - 0.5, limite2.y+0.4, 0);
    glVertex3d(limite1.x, limite2.y+0.4, 0);
    glVertex3d(limite1.x, limite1.y, 0);
    glEnd();
    glEnable(GL_LIGHTING);

    glDisable(GL_LIGHTING);
    glColor3ub(1, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3d(limite2.x, limite1.y, 0);
    glVertex3d(limite2.x, limite2.y + 0.4, 0);
    glVertex3d(limite2.x + 0.5, limite2.y + 0.4, 0);
    glVertex3d(limite2.x + 0.5, limite1.y, 0);
    glEnd();
    glEnable(GL_LIGHTING);
    */
}

float Plataformas::distancia(ETSIDI::Vector2D punto, ETSIDI::Vector2D* direccion)
{
    ETSIDI::Vector2D u = (punto - limite1);
    ETSIDI::Vector2D v = (limite2 - limite1).unit();
    float longitud = (limite1 - limite2).module();
    ETSIDI::Vector2D dir;
    float valor = u * v;
    float distancia = 0;
    if (valor < 0)
        dir = u;
    else if (valor > longitud)
        dir = (punto - limite2);
    else
        dir = u - v * valor;
    distancia = dir.module();
    if (direccion != 0) //si nos dan un vector…
        *direccion = dir.unit();
    return distancia;
}