#include "Listamisiles.h"
#include "Interaccion.h"
#include "glut.h"

ListaMisil::ListaMisil() {

}
ListaMisil::~ListaMisil() {

}

bool ListaMisil::Agregar(Misil* d) {
	lista.push_back(d);
	return true;
}
void ListaMisil::DestruirContenido(int ind) {
	if ((ind < 0) || (ind >= lista.size())) {
		return;
	}
	delete lista[ind];
	lista.erase(lista.begin() + ind);
}
void ListaMisil::Eliminar(Misil* m)
{
	for (int i = 0; i < lista.size(); i++)
		if (lista[i] == m)
		{
			DestruirContenido(i);
			return;
		}
}
void ListaMisil::Mueve(float t) {
	for (int i = 0; i < lista.size(); i++) {

		lista[i]->Mueve(t);
		
	}
}
void ListaMisil::Dibuja() {
	for (int i = 0; i < lista.size(); i++)
		lista[i]->Dibuja();
}
void ListaMisil::Inicializa() {
	for (int i = 0; i < lista.size(); i++)
		lista[i]->Inicializa();
}

Misil* ListaMisil::colision(Hombre& h) {
	for (int i = 0; i < lista.size(); i++)
	{
		if (Interaccion::colision(*(lista[i]), h)) { 
			return lista[i];
		}
	}
	return 0;
}