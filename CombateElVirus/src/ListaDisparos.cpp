#include "ListaDisparos.h"

#include "glut.h"

ListaDisparos::ListaDisparos() {

}
ListaDisparos::~ListaDisparos() {

}

bool ListaDisparos::Agregar(Disparo* d) {
	lista.push_back(d);
	return true;
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