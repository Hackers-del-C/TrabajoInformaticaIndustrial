#pragma once
#include "ETSIDI.h"
#include "BordesSube.h"
class Plataformas {
public:
	enum plat_t{SUELO,PLATAFORMA_CHOCA, PLATAFORMA_ATRAVIESA};

	Plataformas();
	Plataformas(float x1, float y1, float w, float h);
	Plataformas(plat_t tipo, float x1, float y1, float w, float h);
	//~Plataformas();

	plat_t GetTipo() { return tipo; }
	void Dibuja();
	void SetPos(ETSIDI::Vector2D l1,ETSIDI::Vector2D l2) {
		limite1 = l1;
		limite2 = l2;
	}
	void Inicializa(float x, float y, float w, float h);
	float aux;
	float distancia(ETSIDI::Vector2D punto, ETSIDI::Vector2D* direccion);
	ETSIDI::Vector2D posicion;
	float anchura, altura;


	friend class Interaccion;

protected:
	plat_t tipo;
	ETSIDI::Vector2D limite1, limite2;
};