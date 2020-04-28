
#include "ListaPlatafomas.h"
#include "Interaccion.h"
#include "glut.h"

ListaPlataformas::ListaPlataformas() {


}
ListaPlataformas::~ListaPlataformas() {

}

bool ListaPlataformas::Agregar(Plataformas* p) {
	if (lista.size() < NUM_MAX_PLATAFORMAS) {  
		lista.push_back(p);
		return true;
	}
}
void ListaPlataformas::DestruirContenido(int ind) {
	if ((ind < 0) || (ind >= lista.size())) {
		return;
	}
	delete lista[ind];
	lista.erase(lista.begin() + ind);
}
void ListaPlataformas::Dibuja() {
	for (int i = 0; i < lista.size(); i++)
		lista[i]->Dibuja();
}

