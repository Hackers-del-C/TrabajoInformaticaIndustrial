#pragma once
#include "ETSIDI.h"
#include "Musica.h"
#include "Imagen.h"
#include "Titulo.h"

using namespace ETSIDI;
using ETSIDI::getTexture;
using ETSIDI::playMusica;
using ETSIDI::play;
class Entorno {
public:
	
	
	void Inicializa(int nivel);
	void Dibuja(int nivel);
	/*SpriteSequence* explosion;
	Sprite* sprite;
	Sprite* ternerito;
	SpriteSequence* virus;
	SpriteSequence* trump;
	//SpriteSequence* pato;
	SpriteSequence* ninja;
	*/
	void Mueve(float t);
	void Tecla(unsigned char key);
	//friend class Mundo;
	
private:
	Imagen fondo;
	Titulo titulo;
	Musica musica;
	Menu menu;

	
};