#pragma once
#include "Mundo.h"
enum { MOUSE_LEFT_BUTTON, MOUSE_MIDDLE_BUTTON, MOUSE_RIGHT_BUTTON }; //para el raton

class Coordinador {
protected:
	enum Estado { MENU, JUEGO, PAUSA, MUERTE, GANAR };
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
	void SetLevel(int level) {  nivel=level; }
private:
	int nivel;
	Mundo mundo;
	Entorno entorno;
	float xmouse, ymouse;
	
};