#pragma once
#include "Mundo.h"
#include "Entorno.h"
#include "Avion.h"
 

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
	void ClickMouse(int b, int state);
	void MyMouse(int x, int y);
	void SetLevel(int level) {  nivel=level; }
	int Getlevel() { return nivel; }
private:
	int aux;//para resetear la musica
	int aux2; //para usar flechas en el menu
	int nivel;
	Mundo mundo;
	Entorno entorno;
	float xmouse, ymouse;
	int AvanceNivel;
	Avion avion;
};