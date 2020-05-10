#include "ListaVirus.h"

#include "Interaccion.h"

ListaVirus::ListaVirus()
{
	numero = 0;
	for (int i = 0; i < MAX_VIRUS; i++)
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

void ListaVirus::destruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}




ListaVirus::~ListaVirus()
{

}
//
//void ListaVirus::rebote(Pared p)
//{
//	for (int i = 0; i < numero; i++)
//		Interaccion::rebote(*(lista[i]), p);
//}

bool ListaVirus::agregar(Virus* e)
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

void ListaVirus::eliminar(int index)
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






void ListaVirus::eliminar(Virus* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
}


void ListaVirus::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja(0);//nivel
}
void ListaVirus::mueve(float t, Hombre h)
{
	for (int i = 0; i < numero; i++)
		lista[i]->Mueve(t);
}

Virus* ListaVirus::operator [](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}

void ListaVirus::Sigue(Hombre h)
{
	for (int i = 0; i < numero; i++)
		lista[i]->Seguir(h);
}

void ListaVirus::Colision(ListaDisparos &l) {

	for (int i = 0; i < numero; i++) {

		if (l.Colision(*lista[i])) {

			if (lista[i]->GetVidas() < 1) {
				eliminar(i);
			}
			
		}
		
	}
}

//Virus* ListaVirus::Colision(Hombre &h) {
//	for (int i = 0; i < numero; i++) {
//		if (Interaccion::Colision(h,*lista[i])) {
//			return lista[i];
//		}
//	}
//}ç


