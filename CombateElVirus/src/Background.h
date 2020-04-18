#pragma once
#include "ETSIDI.h"
#include "Fondo.h"
using namespace ETSIDI;
using ETSIDI::getTexture;
using ETSIDI::playMusica;
using ETSIDI::play;
class Background {

private:
	Fondo nivel;
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
};