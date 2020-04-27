#include "Pared.h"
#include "glut.h"


//LA CLASE PARED CREA UNA LINEA SIMPLE CON DOS PUNTOS

void Pared::Dibuja()
{
 
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

float Pared::distancia(ETSIDI::Vector2D punto, ETSIDI::Vector2D* direccion)
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

void Pared::SetPos(ETSIDI::Vector2D l1, ETSIDI::Vector2D l2) {
    limite1 = l1;

    limite2 = l2;
}
void Pared::SetPos(float x1, float y1, float x2, float y2) 
{
    limite1.x = x1;
    limite1.y = y1;
    limite2.x = x2;
    limite2.y = y2;
}

float Pared::GetSuelo()
{
    return limite1.y;
    
}