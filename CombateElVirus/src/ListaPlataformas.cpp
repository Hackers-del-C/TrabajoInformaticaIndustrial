
#include "ListaPlatafomas.h"
#include "Interaccion.h"

#include "glut.h"

ListaPlataformas::ListaPlataformas() {
	numero = 0;
	for (int i = 0; i < NUM_MAX_PLATAFORMAS; i++)
		lista[i] = 0;

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
			if (lista[i] == p) {
				return false;
			}
		}
		lista[numero] = p;
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
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}
void ListaPlataformas::Eliminar(Plataformas* p)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == p)
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
		delete lista[i];

	}
	numero = 0;
}
void ListaPlataformas::Dibuja() {
	/*for (int i = 0; i < lista.size(); i++)
		lista[i]->Dibuja();*/
	for (int i = 0; i < numero; i++) {
		lista[i]->Dibuja();
	}
}

Plataformas* ListaPlataformas::ColisionSube(Hombre& h) {
	for (int i = 0; i < numero; i++) {
		if (Interaccion::ColisionSube(h ,*(lista[i]))) {
			return lista[i];
		}
	}
	return 0;
}
Plataformas* ListaPlataformas::ColisionChoca(Hombre &h) {
	for (int i = 0; i < numero; i++) {
		if (Interaccion::ColisionChoca(h, *(lista[i]))) {
			return lista[i];
		}
	}
	return 0;
}
Plataformas* ListaPlataformas::ColisionChocaLado(Hombre &h) {
	for (int i = 0; i < numero; i++) {
		if (Interaccion::ColisionChocaLado(h, *(lista[i]))) {
			return lista[i];
		}
	}
	return 0;
}
Plataformas* ListaPlataformas::operator [](int i) {
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
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
	
