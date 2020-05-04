#include "Plataformas.h"

#include "glut.h"
Plataformas::Plataformas() {
    limite1.x = 0;
    limite2.x = 0;
    limite1.y = 0;

    limite2.y = 0;
}
Plataformas::Plataformas(float x, float y, float w, float h) {
    posicion.x = x;
    posicion.y = y;
    anchura = w;
    altura = h;
    limite1.x = x-w/2;
    limite1.y = y- h/2;
    limite2.x = x+ w/2;
    limite2.y = y +h/2;
}

//ESTO ES AUXILIAR ANTES DE METERLO EN LISTA
void Plataformas::Inicializa(float x, float y, float w, float h) {
    posicion.x = x;
    posicion.y = y;
    anchura = w;
    altura = h;
    limite1.x = x - w / 2;
    limite1.y = y - h / 2;
    limite2.x = x + w / 2;
    limite2.y = y + h / 2;
}


void Plataformas::Dibuja() {

    glDisable(GL_LIGHTING);
    glColor3f(0, 0, aux);
    glBegin(GL_POLYGON);
    glVertex3d(limite1.x, limite1.y, 0);
    glVertex3d(limite1.x, limite2.y, 0);
    glVertex3d(limite2.x, limite2.y, 0);
    glVertex3d(limite2.x, limite1.y, 0);
    glEnd();
    glColor3f(0, 0, -aux);
    glEnable(GL_LIGHTING);



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