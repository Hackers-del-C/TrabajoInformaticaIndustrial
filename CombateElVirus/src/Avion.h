#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Hombre.h"
#include "ListaSlime.h"
#include "ListaBonus.h"


using namespace std;

class Avion {
  
public:
    Avion();
    void Inicializa(float x, float y);
    Avion(float x, float y);
    ~Avion();
    void Mueve(float t);
    void Dibuja();
    ETSIDI::Vector2D posicion, velocidad;
    float anchura, altura;
    // ETSIDI::SpriteSequence* virusazul;
    ETSIDI::Sprite* sprite;
  

};
