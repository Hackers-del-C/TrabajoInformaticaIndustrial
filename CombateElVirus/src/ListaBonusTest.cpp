#include "ListaBonusTest.h"
#include "Interaccion.h"

ListaBonusTest::ListaBonusTest()
{
	numero = 0;
	for (int i = 0; i < BONUS; i++)
		lista[i] = 0;
}

void ListaBonusTest::destruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}


ListaBonusTest::~ListaBonusTest()
{

}

bool ListaBonusTest::agregar(BonusTest* t)
{

	if (numero < BONUSTEST) {

		for (int i = 0; i < numero; i++) {
			if (lista[i] == t) {
				return false;

			}

		}

		lista[numero++] = t;
		return true;
	}
	else {
		return false;
	}
}

void ListaBonusTest::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

BonusTest* ListaBonusTest::colision(Hombre& h)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::ColisionBonus(h, *(lista[i])))
			//eliminar(i);
			return lista[i];
	}
	return false;
}


void ListaBonusTest::eliminar(BonusTest* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
}

void ListaBonusTest::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();//nivel
}

BonusTest* ListaBonusTest::operator [](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}
