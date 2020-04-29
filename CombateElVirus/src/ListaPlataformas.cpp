
#include "ListaPlatafomas.h"
#include "Interaccion.h"

#include "glut.h"

ListaPlataformas::ListaPlataformas() {
	numero = 0;
	for (int i = 0; i < NUM_MAX_PLATAFORMAS; i++)
		listarelleno[i] = 0;

}
ListaPlataformas::~ListaPlataformas() {

}

bool ListaPlataformas::Agregar(Plataformas* p) {
	/*if (lista.size() < NUM_MAX_PLATAFORMAS) {  
		lista.push_back(p);
		return true;
	}*/
	if (numero < NUM_MAX_PLATAFORMAS) {
		for (int i = 0; i < numero; i++) {
			if (listarelleno[i] == p) {
				return false;
			}
		}
		listarelleno[numero] = p;
		//bordessube.Agregar(new BordesSube(listarelleno[numero].limite1.x));
		numero++; // algo para que no se guarden dos sobre lamisma memoria
		return true;
	}
	else
		
		//misiles.Agregar(new Misil("imagenes/misilizq.png", 15, -3.0f, -5.0f, 0.0f));
		return false;

}
void ListaPlataformas::Eliminar(int index) {
	if ((index < 0) || (index >= numero)) {
		return;
	}
	delete listarelleno[index];
	numero--;
	for (int i = index; i < numero; i++)
		listarelleno[i] = listarelleno[i + 1];
}
void ListaPlataformas::Eliminar(Plataformas* p)
{
	for (int i = 0; i < numero; i++)
		if (listarelleno[i] == p)
		{
			Eliminar(i);
			return;
		}
}
void ListaPlataformas::DestruirContenido(int ind) {
	/*if ((ind < 0) || (ind >= lista.size())) {
		return;
	}
	delete lista[ind];
	lista.erase(lista.begin() + ind);*/
	for (int i = 0; i < numero; i++) {
		delete listarelleno[i];

	}
	numero = 0;
}
void ListaPlataformas::Dibuja() {
	/*for (int i = 0; i < lista.size(); i++)
		lista[i]->Dibuja();*/
	for (int i = 0; i < numero; i++) {
		listarelleno[i]->Dibuja();
	}
}

//bool ListaPlataformas::Colision(Hombre h) {
//	for (int i = 0; i < lista.size(); i++) {
//
//		if (Interaccion::Colision(h, *(lista[i]))) { // final pagina 14 error -- pondria rebote
//			return true;
//		}
//	}
//	return 0;
//}
	
