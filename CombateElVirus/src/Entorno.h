#pragma once
#include "ETSIDI.h"

#include "Musica.h"
#include "Fondo.h"
#include "Titulo.h"

using namespace ETSIDI;
using ETSIDI::getTexture;
using ETSIDI::playMusica;
using ETSIDI::play;
class Entorno {
public:
	int level = 3; // va en public, no? weno xd
	void Dibuja();
	void Inicializa();
	SpriteSequence* explosion;
	Sprite* sprite;
	Sprite* ternerito;
	SpriteSequence* virus;
	SpriteSequence* trump;
	//SpriteSequence* pato;
	SpriteSequence* ninja;

	void Mueve(float t);
	void Tecla(unsigned char key);
	friend class Mundo;
	void SetLevel(int nivel) { level = nivel; }
private:
	Fondo fondo;
	Titulo titulo;
	Musica musica;

	
};