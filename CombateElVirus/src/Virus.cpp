#include "Virus.h"
#include "ETSIDI.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "glut.h"

using namespace ETSIDI;
using namespace std;
using ETSIDI::getTexture;
Virus::Virus() {

    posicion.x = 15;
    posicion.y = -7.5;
    

}
Virus::~Virus() {

}
void Virus::Dibuja(int nivel)
{
    glTranslatef(posicion.x, posicion.y, 0);

    sprite->draw();

    glTranslatef(-posicion.x, -posicion.y, 0);

}
void Virus::Inicializa(char nombre[20]) {

    //DEBERIAMOS CREAR UN PUNTERO QUE UNA UN FLUJO A LA IMAGEN, QUE SE LE PASE EL NOMBRE DEL VIRUS Y NOS CREE LA IMAGEN DIRECTAMENTE
    //EL CODIGO QUE HAY ABAJO ES ELEGANTE
    /*
    std::ostringstream cadena;
    //char perro[10];
    string img;

    cadena << "imagenes/" << img << ".png" << endl;

    char* pString = new char[cadena.str().length() + 1];

    std::copy(cadena.str().c_str(), cadena.str().c_str() + cadena.str().length() + 1, pString);
    */

    sprite = new SpriteSequence(nombre, 8, 1, 25, true, 4, 4, 3, 3);

}

void Virus::SetVel(float vx, float vy)
{
    velocidad.x = vx;
    velocidad.y = vy;
}

void Virus::Mueve(float t) {

    posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
    velocidad = velocidad + aceleracion * t;
    
    sprite->loop();

    

}


