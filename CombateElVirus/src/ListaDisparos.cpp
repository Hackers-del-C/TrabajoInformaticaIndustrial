#include "ListaDisparos.h"
#include "Interaccion.h"
#include "glut.h"

ListaDisparos::ListaDisparos() {
	numero = 0;
	for (int i = 0; i < MAX_VIRUS; i++)
		lista[i] = 0;
}
ListaDisparos::~ListaDisparos() {

}

bool ListaDisparos::Agregar(Disparo* d) {
	//if (lista.size() < NUM_MAX_DISPAROS) {  // solo tiene 20
	//	lista.push_back(d);
	//	numero++;
	//	ETSIDI::play("mis_sonidos/disparo.wav");
	//	return true;
	//}
	if (numero < NUM_MAX_DISPAROS) {

		for (int i = 0; i < numero; i++) {
			if (lista[i] == d) {
				
				return false;

			}

		}
		ETSIDI::play("mis_sonidos/disparo.wav");
		lista[numero++] =d;
		return true;
	}
	else {
		return false;
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




void ListaDisparos::DestruirContenido() {
	//if ((ind < 0) || (ind >= lista.size())) {
	//	return;
	//}
	//delete lista[ind];
	//lista.erase(lista.begin() + ind);
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}
void ListaDisparos::Mueve(float t) {

	for (int i = 0; i < numero; i++)
		lista[i]->Mueve(t);
}
void ListaDisparos::Dibuja() {
	for (int i = 0; i < numero; i++)
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

bool ListaDisparos::Colision(Virus& v, ListaExplosiones &l)
{
	Disparo* aux;
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::Colision(*(lista[i]), v)) {
			
			/*DestruirContenido(i);
			v.SetVidas(v.GetVidas() - 1);
			if (v.GetVidas() < 1) {
				v.Muere();
			}*/
			l.agregar(new Explosiones(lista[i]->posicion.x, lista[i]->posicion.y));

			eliminar(lista[i]);
			return 1;
		}
	}
	return 0; //no hay colisión
}