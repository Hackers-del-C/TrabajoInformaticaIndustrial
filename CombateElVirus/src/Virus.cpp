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

    if (velocidad.x > 0) {
        spriteder->draw();
    }
    if (velocidad.x < 0) {
        spriteizq->draw();
    }
    if (velocidad.x == 0) {
        sprite->draw();
    }
   

    glTranslatef(-posicion.x, -posicion.y, 0);

}
void Virus::Inicializa(string nombre) {

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
   
    string nombreder = "imagenes/" +nombre + "der.png";
    string nombreizq ="imagenes/"+ nombre + "izq.png";
    nombre = "imagenes/"+ nombre + ".png";

    char* a = strcpy(new char[nombre.length() + 1], nombre.c_str());
    char* b = strcpy(new char[nombreder.length() + 1], nombreder.c_str());
    char* c = strcpy(new char[nombreizq.length() + 1], nombreizq.c_str());
    // char* b = strcpy(new char[nombrecompletoder.str().length() + 1], nombrecompletoder.str().c_str());
    // char* c = strcpy(new char[nombrecompletoizq.str().length() + 1], nombrecompletoizq.str().c_str());

    sprite = new SpriteSequence(a, 6, 1, 25, true, 4, 4, 3, 3);
    spriteder = new SpriteSequence(b, 6, 1, 25, true, 4, 4, 3, 3);
    spriteizq = new SpriteSequence(c, 6, 1, 25, true, 4, 4, 3, 3);
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
    spriteder->loop();
    spriteizq->loop();

    

}


