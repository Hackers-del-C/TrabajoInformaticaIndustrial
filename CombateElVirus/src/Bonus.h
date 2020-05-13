
#pragma once
#include "Etsidi.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Hombre.h"

class Bonus { //CLASE BASE
	   friend class Interaccion;
public:
	Bonus();
	virtual ~Bonus();

	ETSIDI::Vector2D posicion, velocidad, aceleracion; 
	ETSIDI::Sprite* bonus;
	float anchura, altura;
	void Dibuja();
	void SetPos(float ix, float iy);
	virtual void Mueve(float t)=0; //Funcion vitual pura
	virtual bool colision(Hombre& h)=0;//Funcion virtual pura
	//virtual colision(); esta es la que hay que hacer para sumar bien
	ETSIDI::Vector2D GetPos() { return posicion; }
protected:

};

