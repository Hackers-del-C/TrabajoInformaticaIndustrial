#pragma once
#include"ETSIDI.h"
#include "Zapatos.h"
#include "glut.h"
Zapatos::Zapatos(){}
Zapatos::~Zapatos(){}
//void Zapatos::Inicializa(Hombre& h){
//    ETSIDI::Vector2D pos;
//    limite1.x = pos.x - 1.3;
//    limite2.x = pos.x - 1.2;
//    limite1.y = pos.y + 1.6;
//    limite2.y = pos.y + 1.5;
//}
void Zapatos::Dibuja(Hombre& h) {
    glColor3ub(255, 255,255);
    posicion.x = h.GetPos().x - 1.6;
    posicion.y = h.GetPos().y +0.2;
    glTranslatef(posicion.x, posicion.y, 0);
    glutSolidSphere(radio, 20, 20);
    glTranslatef(-posicion.x, -posicion.y, 0);
}
/*
void Zapatos::Mueve(float t, Hombre& h) {
    limite1 = limite1 + h.GetVel() * t;
    limite2 = limite2 + h.GetVel() * t;
}*/
