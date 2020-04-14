#pragma once
#include "ETSIDI.h"
using namespace ETSIDI;
using ETSIDI::getTexture;
using ETSIDI::playMusica;
using ETSIDI::play;
class Background {

private:

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
	SpriteSequence* banderachina;
	void Mueve(float t);
	void Tecla(unsigned char key);
};