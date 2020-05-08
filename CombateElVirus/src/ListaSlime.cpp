#include "ListaSlime.h"

#include "Interaccion.h"

ListaSlime::ListaSlime()
{
	numero = 0;
	for (int i = 0; i < MAX_SLIME; i++)
		lista[i] = 0;
}
//
//void ListaVirus::rebote(Limites caja)
//{
//	for (int i = 0; i < numero; i++)
//		Interaccion::rebote(*(lista[i]), caja);
//}

//void ListaVirus::rebote()
//{
//	for (int i = 0; i < numero; i++) {
//
//
//		for (int j = 0; j < numero; j++) {
//
//			Interaccion::rebote(*(lista[i]), *(lista[j]));
//		}
//	}
//}

bool ListaSlime::agregar(Slime* e)
{

	if (numero < MAX_VIRUS) {

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

void ListaSlime::destruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}




ListaSlime::~ListaSlime()
{

}
//
//void ListaVirus::rebote(Pared p)
//{
//	for (int i = 0; i < numero; i++)
//		Interaccion::rebote(*(lista[i]), p);
//}


void ListaSlime::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

//Virus* ListaVirus::colision(Hombre& h)
//{
//	for (int i = 0; i < numero; i++)
//	{
//		if (Interaccion::colision(*(lista[i]), h))
//			return lista[i];
//	}
//	return 0; //no hay colisión
//}

void ListaSlime::eliminar(Slime* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
}


void ListaSlime::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();//nivel
}
void ListaSlime::mueve(float t, Hombre h)
{
	for (int i = 0; i < numero; i++)
		lista[i]->Mueve(t);
}

Slime* ListaSlime::operator [](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}

void ListaSlime::Colision(ListaPlataformas p) {

	for (int i = 0; i < numero; i++)
		p.Colision(*lista[i]);
}

void ListaSlime::Colision(Limites l) {

	for (int i = 0; i < numero; i++)
		Interaccion::Colision(*lista[i], l);
}

//Virus* ListaVirus::Colision(Hombre &h) {
//	for (int i = 0; i < numero; i++) {
//		if (Interaccion::Colision(h,*lista[i])) {
//			return lista[i];
//		}
//	}
//}