#include "Listamisiles.h"
#include "Interaccion.h"
#include "glut.h"

ListaMisil::ListaMisil() {

}
ListaMisil::~ListaMisil() {

}

bool ListaMisil::Agregar(Misil* d) {
	if (numero < NUM_MAX_PLATAFORMAS) {
		for (int i = 0; i < numero; i++) {
			if (lista[i] == d) {
				return false;
			}
		}
		lista[numero] = d;
		//bordessube.Agregar(new BordesSube(listarelleno[numero].limite1.x));
		numero++; // algo para que no se guarden dos sobre lamisma memoria
		return true;
	}
	else

		//misiles.Agregar(new Misil("imagenes/misilizq.png", 15, -3.0f, -5.0f, 0.0f));
		return false;
}
void ListaMisil::DestruirContenido(int ind) {
	for (int i = 0; i < numero; i++) {
		delete lista[i];

	}
	numero = 0;
}
void ListaMisil::Eliminar(int index) {
	if ((index < 0) || (index >= numero)) {
		return;
	}
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}
void ListaMisil::Eliminar(Misil* m)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == m)
		{
			Eliminar(i);
			return;
		}
}
void ListaMisil::Mueve(float t) {
	for (int i = 0; i < numero; i++) {

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
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();
}


Misil* ListaMisil::colision(Hombre& h) {
	for (int i = 0; i < numero; i++)
	{
	
			if (Interaccion::colision(*(lista[i]), h)) {
				return lista[i];
			}
		
	}
	return 0;
}

void ListaMisil::limpiar() {

	for (int i = 0; i < numero; i++) {
		if (lista[i]->posicion.x <= 0) {

			DestruirContenido(i);
		}
	}
}