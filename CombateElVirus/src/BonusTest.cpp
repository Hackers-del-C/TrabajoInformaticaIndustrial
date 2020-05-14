#include"BonusTest.h"
using namespace ETSIDI;
using namespace std;
using ETSIDI::getTexture;

BonusTest::BonusTest() {
	
}


BonusTest::BonusTest(int x, int y, int w, int h) {
	anchura = 0.4 * w;
	altura = 0.4 * h;
	bonus = new Sprite("imagenes/test.png", 0, 0, w, h);
	posicion.x = x;
	posicion.y = y;
	
}

void BonusTest::Inicializa( int x, int y, int w, int h) {
	anchura = 0.4 * w;
	altura = 0.4 * h;
	posicion.x = x;
	posicion.y = y;
	bonus = new Sprite("imagenes/test.png", 0, 0, w, h);
}

void BonusTest::Mueve(float t) {
	
}

bool BonusTest::colision(Hombre& h) {
	if (h.GetMonedas() <= 19) {
		h.SetMonedas(h.GetMonedas() + 1);
		return true;
	}
	else
		return false;
}