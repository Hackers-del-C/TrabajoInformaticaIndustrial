#include "Listalanzamisiles.h"

#include "glut.h"

ListaLanzamisiles::ListaLanzamisiles() {
	
}
ListaLanzamisiles::~ListaLanzamisiles() {

}

bool ListaLanzamisiles::Agregar(Lanzamisiles* d) {
	lista.push_back(d);
	return true;
}
void ListaLanzamisiles::DestruirContenido(int ind) {
	if ((ind < 0) || (ind >= lista.size())) {
		return;
	}
	delete lista[ind];
	lista.erase(lista.begin() + ind);
}
/*void ListaDisparos::Mueve(float t) {
	for (int i = 0; i < lista.size(); i++) {
		lista[i]->Mueve(t);
	}*/

void ListaLanzamisiles::Dibuja() {
	for (int i = 0; i < lista.size(); i++)
		lista[i]->Dibuja();
}
void ListaLanzamisiles::Eliminar(Lanzamisiles* m)
{
	for (int i = 0; i < lista.size(); i++)
		if (lista[i] == m)
		{
			DestruirContenido(i);
			return;
		}
}