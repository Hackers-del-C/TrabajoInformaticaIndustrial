#include"Misil.h"
#include <iostream>
#include <string>
#include <sstream>
#include"glut.h"

/*Misil::Misil() {

}*/
Misil::Misil(char nombre [20], float x, float y, float vx, float vy) {

	/*
	stringstream sstr;
	string cadena = "imagenes/";
	sstr << cadena << nombre << ".png";
	cadena = sstr.str();
	char nombreimagen[20];
	for (int i = 0; i != '\0'; i++) {
		nombreimagen[i] = cadena[i];

	}*/
	misil = new Sprite(nombre, x, y, 2, 2);
	posicion.x = x;
	posicion.y = x;
	velocidad.x = vx;
	velocidad.y = vy;
}


/*void Misil::Inicializader() {
	//lanzamisiles1 = new Sprite("imagenes/lanzamisiles.png", 30, -4, 4, 4);

	misilder = new Sprite("imagenes/misilder.png", 31, 0, 2, 2);
	
}*/
void Misil::Inicializa() {
	//lanzamisiles1 = new Sprite("imagenes/lanzamisiles.png", 30, -4, 4, 4);

	misilizq = new Sprite("imagenes/misilizq.png", 29, 0, 2, 2);
}
/*void Misil::Dibujader() {
	misilder->draw();

}*/
void Misil::Dibuja() {
	
	misil->draw();
}
/*void Misil::Mueveder(float t) {
	posicion = posicion + velocidad * t;

	misilder->loop();

}*/
void Misil::Mueve(float t) {
	posicion = posicion + velocidad * t;


	misil->loop();
}
void Misil::SetVel(float v) {
	velocidad.x = v;
}