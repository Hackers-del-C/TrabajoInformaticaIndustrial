#pragma once
#include "Plataformas.h"
//#include "Interaccion.h"
//#include "Hombre.h"
#include "Slime.h"
#include "ListaBordesSube.h"

//#include <vector>
#define NUM_MAX_PLATAFORMAS 1000

class ListaPlataformas{

public:
	ListaPlataformas();
	
	~ListaPlataformas();

	bool Agregar(Plataformas* p);
	void DestruirContenido(int ind);
	void Dibuja();
	int GetNumero() { return numero; }
	void Eliminar(int index);
	void Eliminar(Plataformas* p);

	Plataformas* ColisionSube(Hombre &h);
	Plataformas* ColisionChoca(Hombre &h);
	Plataformas* ColisionChocaLado(Hombre &h);
	Plataformas* operator [](int i);
	void Colision(Slime& s);
private:
	int numero;
	Plataformas* lista[NUM_MAX_PLATAFORMAS];
	
	//std::vector<Plataformas*>lista;
	
	//Disparo* lista[NUM_MAX_DISPAROS];
	//int numero;

};