#include "Plataformas.h"

#include "glut.h"
Plataformas::Plataformas() {
    limite1.x = 0;
    limite2.x = 0;
    limite1.y = 0;

    limite2.y = 0;

    velocidad.x = 0;
    velocidad.y = 0;
    aceleracion.y = 0;
    aceleracion.x = 0;
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
Plataformas::Plataformas(plat_t tipo, float x, float y, float w, float h) :tipo(tipo) {
    posicion.x = x;
    posicion.y = y;
    anchura = w;
    altura = h;
    limite1.x = x - w / 2;
    limite1.y = y - h / 2;
    limite2.x = x + w / 2;
    limite2.y = y + h / 2;
    velocidad.x = 0;
    velocidad.y = 0;
    aceleracion.y = 0;
    aceleracion.x = 0;
}

Plataformas::Plataformas(plat_t tipo, float x, float y, float w, float h,float xi, float xf):tipo(tipo) {
    posicion.x = x;
    posicion.y = y;
    anchura = w;
    altura = h;
    limite1.x = x - w / 2;
    limite1.y = y - h / 2;
    limite2.x = x + w / 2;
    limite2.y = y + h / 2;
    velocidad.x = 0;
    velocidad.y = 0;
    aceleracion.y = 0;
    aceleracion.x = 0;
    this->xi = xi;
    this->xf = xf;
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

  
    switch (tipo) {
    case Plataformas::PLATAFORMA_ATRAVIESA:
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/plataformachoca.png").id);
        glDisable(GL_LIGHTING);
        glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);
        glTexCoord2d(0, 1); glVertex3f(limite2.x, limite1.y, 0);
        glTexCoord2d(1, 1); glVertex3f(limite1.x, limite1.y, 0);
        glTexCoord2d(1, 0); glVertex3f(limite1.x, limite2.y, 0);
        glTexCoord2d(0, 0); glVertex3f(limite2.x, limite2.y, 0);
        glEnd();
        glEnable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);

        break;
    case Plataformas::PLATAFORMA_CHOCA:
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/plataformachoca.png").id);
        glDisable(GL_LIGHTING);
        glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);
        glTexCoord2d(0, 1); glVertex3f(limite2.x, limite1.y, 0);
        glTexCoord2d(1, 1); glVertex3f(limite1.x, limite1.y, 0);
        glTexCoord2d(1, 0); glVertex3f(limite1.x, limite2.y, 0);
        glTexCoord2d(0, 0); glVertex3f(limite2.x, limite2.y, 0);
        glEnd();
        glEnable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);

        break;
    case Plataformas::SUELO:
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/suelo.png").id);
        glDisable(GL_LIGHTING);
        glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);
        glTexCoord2d(0, 1); glVertex3f(limite2.x, limite1.y, 0);
        glTexCoord2d(1, 1); glVertex3f(limite1.x, limite1.y, 0);
        glTexCoord2d(1, 0); glVertex3f(limite1.x, limite2.y, 0);
        glTexCoord2d(0, 0); glVertex3f(limite2.x, limite2.y, 0);
        glEnd();
        glEnable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);

        break;
    case Plataformas::PLATAFORMA_MUEVE:
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/plataformachoca.png").id);
        glDisable(GL_LIGHTING);
        glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);
        glTexCoord2d(0, 1); glVertex3f(limite2.x, limite1.y, 0);
        glTexCoord2d(1, 1); glVertex3f(limite1.x, limite1.y, 0);
        glTexCoord2d(1, 0); glVertex3f(limite1.x, limite2.y, 0);
        glTexCoord2d(0, 0); glVertex3f(limite2.x, limite2.y, 0);
        glEnd();
        glEnable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);

        break;
        break;
    case Plataformas::PLATAFORMA_MUEVE2:
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/plataformachoca.png").id);
        glDisable(GL_LIGHTING);
        glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);
        glTexCoord2d(0, 1); glVertex3f(limite2.x, limite1.y, 0);
        glTexCoord2d(1, 1); glVertex3f(limite1.x, limite1.y, 0);
        glTexCoord2d(1, 0); glVertex3f(limite1.x, limite2.y, 0);
        glTexCoord2d(0, 0); glVertex3f(limite2.x, limite2.y, 0);
        glEnd();
        glEnable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);

        break;
    }
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
void Plataformas::Mueve(float t){
    if (tipo == PLATAFORMA_MUEVE) {
        if (posicion.x <= xi) {
            velocidad.x = 4;
        }
        if (posicion.x >= xf) {
            velocidad.x = -4;
        }
        posicion=posicion+ velocidad * t + aceleracion * (0.5f * t * t);
        limite1 = limite1 + velocidad * t + aceleracion * (0.5f * t * t);
        limite2 = limite2 + velocidad * t + aceleracion * (0.5f * t * t);
        velocidad = velocidad + aceleracion * t;
    }
    if (tipo == PLATAFORMA_MUEVE2) {
        if (posicion.y <= xi) {
            velocidad.y = 4;
        }
        if (posicion.y >= xf) {
            velocidad.y = -4;
        }
        posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
        limite1 = limite1 + velocidad * t + aceleracion * (0.5f * t * t);
        limite2 = limite2 + velocidad * t + aceleracion * (0.5f * t * t);
        velocidad = velocidad + aceleracion * t;
    }
   }