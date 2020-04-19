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

private:
	Fondo fondo;
	Titulo titulo;
	Musica musica;
	int level = 1; // va en public, no? weno xd

public:
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
};