#include "ListaBonusMascarilla.h"

#include "Interaccion.h"

ListaBonusMascarilla::ListaBonusMascarilla()
{
	numero = 0;
	for (int i = 0; i < BONUS; i++)
		lista[i] = 0;
}

void ListaBonusMascarilla::destruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}




ListaBonusMascarilla::~ListaBonusMascarilla()
{

}
//
//void ListaVirus::rebote(Pared p)
//{
//	for (int i = 0; i < numero; i++)
//		Interaccion::rebote(*(lista[i]), p);
//}

bool ListaBonusMascarilla::agregar(BonusMascarilla* e)
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

void ListaBonusMascarilla::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaBonusMascarilla::colision(Hombre& h)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::ColisionBonus(h, *(lista[i])))
			eliminar(i);
	}
}



void ListaBonusMascarilla::eliminar(BonusMascarilla* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
}


void ListaBonusMascarilla::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();//nivel
}
void ListaBonusMascarilla::mueve(float t)
{
	for (int i = 0; i < numero; i++){
		lista[i]->Mueve(t); 
	}
	
}

BonusMascarilla* ListaBonusMascarilla::operator [](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}
void ListaBonusMascarilla::Colision(Limites l) {
	for (int i = 0; i < numero; i++) {
		//Interaccion::Colision(*(lista[i], l));
	}
}