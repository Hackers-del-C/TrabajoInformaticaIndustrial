#include "Listamisiles.h"

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