#include "ListaDisparos.h"
#include "Interaccion.h"
#include "glut.h"

ListaDisparos::ListaDisparos() {

}
ListaDisparos::~ListaDisparos() {

}

bool ListaDisparos::Agregar(Disparo* d) {
	if (lista.size() < NUM_MAX_DISPAROS) {  // solo tiene 20
		lista.push_back(d);
		numero++;
		return true;
	}
}

void ListaDisparos::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaDisparos::eliminar(Disparo* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
}




void ListaDisparos::DestruirContenido(int ind) {
	if ((ind < 0) || (ind >= lista.size())) {
		return;
	}
	delete lista[ind];
	lista.erase(lista.begin() + ind);
}
void ListaDisparos::Mueve(float t) {
	for (int i = 0; i < lista.size(); i++) {
		lista[i]->Mueve(t);
	}
}
void ListaDisparos::Dibuja() {
	for (int i = 0; i < lista.size(); i++)
		lista[i]->Dibuja();
}

Disparo* ListaDisparos::operator [](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}

bool ListaDisparos::Colision(Virus& v)
{
	Disparo* aux;
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::Colision(*(lista[i]), v)) {
			
			//DestruirContenido(i);
			return 1;
		}
	}
	return 0; //no hay colisión
}