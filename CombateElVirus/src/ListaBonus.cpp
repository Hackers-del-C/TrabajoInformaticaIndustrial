#include "ListaBonus.h"
#include "Interaccion.h"

ListaBonus::ListaBonus()
{
	numero = 0;
	for (int i = 0; i < BONUS; i++)
		lista[i] = 0;
}

void ListaBonus::destruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}


ListaBonus::~ListaBonus()
{

}


bool ListaBonus::agregar(Bonus* e)
{

	if (numero < BONUS) {

		for (int i = 0; i < numero; i++) {
			if (lista[i] == e) {
				return false;

			}

		}

		lista[numero++] = e;
		return true;
	}
	else {
		return false;
	}
}


void ListaBonus::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaBonus::colision(Hombre& h)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::ColisionBonus(h, *(lista[i])))

			if (lista[i]->colision(h) == 1)
				eliminar(lista[i]);
	}
}



void ListaBonus::eliminar(Bonus* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
}


void ListaBonus::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();//nivel
}

void ListaBonus::mueve(float t)
{
	for (int i = 0; i < numero; i++) {
		lista[i]->Mueve(t);
	}

}

Bonus* ListaBonus::operator [](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}

void ListaBonus::Colision(Limites c) {
	for (int i = 0; i < numero; i++) {
		Interaccion::Colision(*lista[i], c);
	}
}

void ListaBonus::Colision(Plataformas p) {
	for (int i = 0; i < numero; i++) {
		Interaccion::Colision(*lista[i], p);
	}
}