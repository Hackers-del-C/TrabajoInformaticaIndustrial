#include "AuxEtsidi.h"
#include "ETSIDI.h"
#include "glut.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
//Clase auxiliar para hacer el codigo más corto y entendible en caso de necesitar imagenes o texto. 
	

void AuxEtsidi::Imagen(string nombre, float limx1, float limx2, float limy1, float limy2,float z){
	//Similar a la función creada para los sprites de los virus
	//string nombre: nombre de la imagen
	//limites:
	//son las dimensiones la imagen en x e y
	nombre = "imagenes/entorno/" + nombre + ".png";

	char* name = strcpy(new char[nombre.length() + 1], nombre.c_str());

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(name).id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);

	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);		glVertex3f(limx1, limy1, z);
	glTexCoord2d(1, 1);		glVertex3f(limx2, limy1, z);
	glTexCoord2d(1, 0);		glVertex3f(limx2, limy2, z);
	glTexCoord2d(0, 0);		glVertex3f(limx1, limy2, z);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

}
void AuxEtsidi::Texto(string nombre,float x, float y,float red,float verde,float azul,float tamanio) {
	//string nombre es lo que se quiere imprimir
	//x e y son la posicion
	//red, verde, azul esla combinacion de colores del texto
	//tamanio es el tamaño de la fuente
	
	char* name = strcpy(new char[nombre.length() + 1], nombre.c_str());
	glTranslatef(x,y,0.4);
	setTextColor(red, verde, azul); //FUNCIONA IGUAL QUE GLUT PERO EN VEZ DE 0-255 DE 0-1
	print(name, "fuentes/Bitwise.ttf", tamanio);
	glTranslatef(-x,-y,-0.4);
}

