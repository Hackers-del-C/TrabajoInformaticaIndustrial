#include"BonusTest.h"
using namespace ETSIDI;
using namespace std;
using ETSIDI::getTexture;

BonusTest::BonusTest() {
	
}


BonusTest::BonusTest(string nombre, int x, int y, int w, int h) {
	anchura = 0.4 * w;
	altura = 0.4 * h;
	nombre = "imagenes/" + nombre + ".png";

	char* name = strcpy(new char[nombre.length() + 1], nombre.c_str());
	bonus = new Sprite(name, 0, 0, w, h);
	posicion.x = x;
	posicion.y = y;
}

void BonusTest::Inicializa(string nombre, int x, int y, int w, int h) {
	anchura = 0.4 * w;
	altura = 0.4 * h;
	posicion.x = x;
	posicion.y = y;
	nombre = "imagenes/" + nombre + ".png";
	char* name = strcpy(new char[nombre.length() + 1], nombre.c_str());
	bonus = new Sprite(name, 0, 0, w, h);
}