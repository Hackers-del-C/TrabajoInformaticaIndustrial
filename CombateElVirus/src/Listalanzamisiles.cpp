#include "Listalanzamisiles.h"

#include "glut.h"

ListaLanzamisiles::ListaLanzamisiles() {
	
}
ListaLanzamisiles::~ListaLanzamisiles() {

}

bool ListaLanzamisiles::Agregar(Lanzamisiles* d) {
	if (numero < NUM_MAX_lanzamisiles) {
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
void ListaLanzamisiles::DestruirContenido(int ind) {
	for (int i = 0; i < numero; i++) {
		delete lista[i];

	}
	numero = 0;
}
/*void ListaDisparos::Mueve(float t) {
	for (int i = 0; i < lista.size(); i++) {
		lista[i]->Mueve(t);
	}*/

void ListaLanzamisiles::Dibuja() {
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();
}
void ListaLanzamisiles::Eliminar(int index) {
	if ((index < 0) || (index >= numero)) {
		return;
	}
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}
void ListaLanzamisiles::Eliminar(Lanzamisiles* m)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == m)
		{
			Eliminar(i);
			return;
		}
}