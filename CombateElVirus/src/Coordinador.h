#pragma once
#include "Mundo.h"

class Coordinador {
public:
	void Mueve();
	void Dibuja();
	void teclaEspecial(unsigned char key);
	void teclaEspecialsuelta(unsigned char key);
	void ClickMouse(int b, int state);
	void MyMouse(int x, int y);
private:

};