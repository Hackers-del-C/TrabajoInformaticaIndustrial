#include "ListaBordesSube.h"
#include "glut.h"

ListaBordesSube::ListaBordesSube() {
	numero = 0;
	for (int i = 0; i < NUM_MAX_PLATAFORMAS; i++)
		lista[i] = 0;

}
ListaBordesSube::~ListaBordesSube() {

}

bool ListaBordesSube::Agregar(BordesSube* b) {
	/*if (lista.size() < NUM_MAX_PLATAFORMAS) {
		lista.push_back(p);
		return true;
	}*/
	if (numero < NUM_MAX_PLATAFORMAS) {
		for (int i = 0; i < numero; i++) {
			if (lista[i] == b) {
				return false;
			}
		}
		lista[numero] =b;
		numero++; // algo para que no se guarden dos sobre lamisma memoria
		return true;
	}
	else
		return false;

}
void ListaBordesSube::Eliminar(int index) {
	if ((index < 0) || (index >= numero)) {
		return;
	}
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}
void ListaBordesSube::Eliminar(BordesSube* b)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == b)
		{
			Eliminar(i);
			return;
		}
}
void ListaBordesSube::DestruirContenido(int ind) {
	/*if ((ind < 0) || (ind >= lista.size())) {
		return;
	}
	delete lista[ind];
	lista.erase(lista.begin() + ind);*/
	for (int i = 0; i < numero; i++) {
		delete lista[i];

	}
	numero = 0;
}
void ListaBordesSube::Dibuja() {
	/*for (int i = 0; i < lista.size(); i++)
		lista[i]->Dibuja();*/
	for (int i = 0; i < numero; i++) {
		lista[i]->Dibuja();
	}
}