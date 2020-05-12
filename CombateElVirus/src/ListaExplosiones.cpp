
#pragma once
#include "ListaExplosiones.h"

ListaExplosiones::ListaExplosiones()
{
	numero = 0;
	for (int i = 0; i < MAX_EXP; i++)
		lista[i] = 0;
}


void ListaExplosiones::destruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}




ListaExplosiones::~ListaExplosiones()
{

}


bool ListaExplosiones::agregar(Explosiones* e)
{

	if (numero < MAX_EXP) {

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

void ListaExplosiones::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}



void ListaExplosiones::eliminar(Explosiones* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
}


void ListaExplosiones::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();//nivel
}
void ListaExplosiones::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->Mueve(t);
}

Explosiones* ListaExplosiones::operator [](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}



