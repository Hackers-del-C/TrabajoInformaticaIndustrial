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
	/*numero = 0;
	for (int i = 0; i < MAX_VIRUS; i++)
		lista[i] = 0;*/
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
//void ListaMisil::Explota() {
//	for (int i = 0; i < lista.size(); i++) {
//		lista[i]->Explota();
//		lista[i]->SetVel(0);
//	}
//}
void ListaMisil::Dibuja() {
	for (int i = 0; i < lista.size(); i++)
		lista[i]->Dibuja();
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

void ListaMisil::limpiar() {

	for (int i = 0; i < lista.size(); i++) {
		if (lista[i]->posicion.x < 0) {

			DestruirContenido(i);
		}
	}
}