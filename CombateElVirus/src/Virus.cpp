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

Virus::Virus(){

    posicion.x = 15;
    posicion.y = -7.5;

}

Virus::Virus(string nombre, int m, int n, float x, float y, float w, float h, int izqder1, int salto1) {

    anchura = w;
    altura = h;

    posicion.x = 15;
    posicion.y = -7.5;
    izqder = izqder1; //Si el muñeco puede ir a la izquierda y a la derecha
    salto = salto1;//Si el muñeco puede saltar/atacar

    string nombreder = "imagenes/" + nombre + "der.png";
    string nombreizq = "imagenes/" + nombre + "izq.png";
    nombre = "imagenes/" + nombre + ".png";

    char* a = strcpy(new char[nombre.length() + 1], nombre.c_str());
    char* b = strcpy(new char[nombreder.length() + 1], nombreder.c_str());
    char* c = strcpy(new char[nombreizq.length() + 1], nombreizq.c_str());
    // char* b = strcpy(new char[nombrecompletoder.str().length() + 1], nombrecompletoder.str().c_str());
    // char* c = strcpy(new char[nombrecompletoizq.str().length() + 1], nombrecompletoizq.str().c_str());

    sprite = new SpriteSequence(a, m, n, 25, true, x, y, w, h);

    if (izqder == 1) {
        spriteder = new SpriteSequence(b, m, n, 25, true, x, y, w, h);
        spriteizq = new SpriteSequence(c, m, n, 25, true, x, y, w, h);
    }
    if (salto == 1) {
        spritemuere = new SpriteSequence("sangrevirus", m, n, 25, true, x-w/2, y, w, h);
        
    }
 
}

Virus::~Virus() {

}
void Virus::Dibuja(int nivel)
{
    glTranslatef(posicion.x, posicion.y, 0);
   
   
    if (muere == 0) {
        if (izqder == 1) {
            if (velocidad.x > 0) {
                spriteder->draw();
            }
            if (velocidad.x < 0) {
                spriteizq->draw();
            }
            if (velocidad.x == 0) {
                sprite->draw();
            }
        }
        else {
            sprite->draw();
        }
    }


    if (muere == 1) {
        glTranslatef(-0.5, 0, 0); //Para que la sangre salga del lateral, estaria mejor con W
        spritemuere->draw();
        glTranslatef(+0.5, 0, 0);
        if (izqder == 1) {
            spriteizq->draw();
        }
        else { sprite->draw(); }
    }
    glTranslatef(-posicion.x, -posicion.y, 0);

}
void Virus::Inicializa(string nombre, int m, int n, float x, float y, float w, float h, int izqder1, int salto1) {

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
    izqder = izqder1; //Si el muñeco puede ir a la izquierda y a la derecha
    salto = salto1;//Si el muñeco puede saltar/atacar
   
    string nombreder = "imagenes/" +nombre + "der.png";
    string nombreizq ="imagenes/"+ nombre + "izq.png";
    nombre = "imagenes/"+ nombre + ".png";

    char* a = strcpy(new char[nombre.length() + 1], nombre.c_str());
    char* b = strcpy(new char[nombreder.length() + 1], nombreder.c_str());
    char* c = strcpy(new char[nombreizq.length() + 1], nombreizq.c_str());
    // char* b = strcpy(new char[nombrecompletoder.str().length() + 1], nombrecompletoder.str().c_str());
    // char* c = strcpy(new char[nombrecompletoizq.str().length() + 1], nombrecompletoizq.str().c_str());

    sprite = new SpriteSequence(a, m, n, 25, true, x, y, w, h);
    spritemuere = new SpriteSequence("imagenes/sangrevirus.png", 8, 1, 90, true, x-w/2, y, 3, 3); //SOLO SE MUESTRA UNA VEZ, poner bien las coordenadas
    if(izqder==1){
    spriteder = new SpriteSequence(b, m, n, 25, true, x, y, w, h);
    spriteizq = new SpriteSequence(c, m, n, 25, true, x, y, w, h);
    }
    if (salto == 1) {
       
    }

}

void Virus::Muere()
{
    
    muere = 1;
    
}

void Virus::SetVel(float vx, float vy)
{
    velocidad.x = vx;
    velocidad.y = vy;
}

void Virus::Mueve(float t, Hombre h) {

    posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
    velocidad = velocidad + aceleracion * t;



    if (muere == 1) {
        spritemuere->loop();
        sprite->pause();

        if (izqder == 1) {
            spriteder->pause();
            spriteizq->pause();
        }
        
        velocidad.x = 0;

    }
    if (muere == 0) {

        sprite->loop();

        if (izqder == 1) {
            spriteder->loop();
            spriteizq->loop();
        }

        if (posicion.x + 5 < h.posicion.x) {
            velocidad.x = 3;
        }
        if (posicion.x + 5 > h.posicion.x) {
            velocidad.x = -3;
        }
    }
   
    

}


