#pragma once
#include "Mundo.h"

class Coordinador {
protected:
	enum Estado { INICIO, JUEGO, PAUSA, MUERTE, GANAR };
	Estado estado;
public:
	Coordinador();
	~Coordinador();
	void Inicializa();
	void Mueve();
	void Dibuja();
	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void teclaEspecialsuelta(unsigned char key);
	void ClickMouse(int b, int state);
	void MyMouse(int x, int y);
private:
	Mundo mundo;
	Entorno entorno;
	float xmouse, ymouse;
	int level;
};