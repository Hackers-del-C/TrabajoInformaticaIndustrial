#include "AuxEtsidi.h"
#include "ETSIDI.h"
#include "glut.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

	

void AuxEtsidi::Imagen(string nombre, float limx1, float limx2, float limy1, float limy2) {
	//Similar a la función creada para los sprites de los virus
	nombre = "imagenes/" + nombre + ".png";

	char* name = strcpy(new char[nombre.length() + 1], nombre.c_str());

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(name).id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);

	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);		glVertex3f(limx1, limy1, -0.1);
	glTexCoord2d(1, 1);		glVertex3f(limx2, limy1, -0.1);
	glTexCoord2d(1, 0);		glVertex3f(limx2, limy2, -0.1);
	glTexCoord2d(0, 0);		glVertex3f(limx1, limy2, -0.1);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

}
void AuxEtsidi::Texto(string nombre,float x, float y,float red,float verde,float azul,float tamanio) {
	char* name = strcpy(new char[nombre.length() + 1], nombre.c_str());
	glTranslatef(x,y,0);
	setTextColor(red, verde, azul); //FUNCIONA IGUAL QUE GLUT PERO EN VEZ DE 0-255 DE 0-1
	print(name, "fuentes/Bitwise.ttf", tamanio);
	glTranslatef(-x,-y,0);
}
//// templo chino

		/*templo = new Sprite("imagenes/templo.png", 0, 3, 10, 20);
		templo->draw();
		templo->loop();*/


////plataforma1//
//		glEnable(GL_TEXTURE_2D);
//		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/banderachina.png").id);
//		glDisable(GL_LIGHTING);
//		glBegin(GL_POLYGON);
//
//		glColor3f(1, 1, 1);
//		glTexCoord2d(0, 1);		glVertex3f(30, 5, -0.1);//ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
//		glTexCoord2d(1, 1);		glVertex3f(60, 5, -0.1);
//		glTexCoord2d(1, 0);		glVertex3f(60, 10, -0.1);
//		glTexCoord2d(0, 0);		glVertex3f(30, 10, -0.1);
//		glEnd();
//		glEnable(GL_LIGHTING);
//		glDisable(GL_TEXTURE_2D);
//	/*
//
////PRENIVEL
//
//		glEnable(GL_TEXTURE_2D);
//		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/prenivel.png").id);
//		glDisable(GL_LIGHTING);
//		glBegin(GL_POLYGON);
//
//		glColor3f(1, 1, 1);
//		glTexCoord2d(0, 1);		glVertex3f(-30, -10, -0.1);//ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
//		glTexCoord2d(1, 1);		glVertex3f(26, -10, -0.1);
//		glTexCoord2d(1, 0);		glVertex3f(26, 30, -0.1);
//		glTexCoord2d(0, 0);		glVertex3f(-30, 30, -0.1);
//		glEnd();
//		glEnable(GL_LIGHTING);
//		glDisable(GL_TEXTURE_2D);
//		
////FONDO 1//: LABORATORIO
//		glEnable(GL_TEXTURE_2D);
//		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/laboratorio.png").id);
//		glDisable(GL_LIGHTING);
//		glBegin(GL_POLYGON);
//
//		glColor3f(1, 1, 1);
//		glTexCoord2d(0, 1);		glVertex3f(26, -18, -0.1);//ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
//		glTexCoord2d(1, 1);		glVertex3f(156, -18, -0.1);
//		glTexCoord2d(1, 0);		glVertex3f(156, 45, -0.1);
//		glTexCoord2d(0, 0);		glVertex3f(26, 45, -0.1);
//		glEnd();
//		glEnable(GL_LIGHTING);
//		glDisable(GL_TEXTURE_2D);
//		/*
//		glEnable(GL_TEXTURE_2D);
//		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo1.png").id);
//		glDisable(GL_LIGHTING);
//		glBegin(GL_POLYGON);
//
//		glColor3f(1, 1, 1);
//		glTexCoord2d(0, 1);		glVertex3f(-20, -10, -0.1);//ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
//		glTexCoord2d(1, 1);		glVertex3f(40, -10, -0.1);
//		glTexCoord2d(1, 0);		glVertex3f(40, 30, -0.1);
//		glTexCoord2d(0, 0);		glVertex3f(-20, 30, -0.1);
//		glEnd();
//		glEnable(GL_LIGHTING);
//		glDisable(GL_TEXTURE_2D);
//		*/
////FONDO 2//: SUPERMERCADO
//
//		glEnable(GL_TEXTURE_2D);
//		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/supermercado.png").id);
//		glDisable(GL_LIGHTING);
//		glBegin(GL_POLYGON);
//
//		glColor3f(1, 1, 1);
//		glTexCoord2d(0, 1);		glVertex3f(156, -10, -0.1); //ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
//		glTexCoord2d(1, 1);		glVertex3f(266, -10, -0.1);
//		glTexCoord2d(1, 0);		glVertex3f(266, 30, -0.1);
//		glTexCoord2d(0, 0);		glVertex3f(156, 30, -0.1);
//		glEnd();
//
//		glEnable(GL_LIGHTING);
//		glDisable(GL_TEXTURE_2D);
//		/*
//		glEnable(GL_TEXTURE_2D);
//		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo2.png").id);
//		glDisable(GL_LIGHTING);
//		glBegin(GL_POLYGON);
//
//		glColor3f(1, 1, 1);
//		glTexCoord2d(0, 1);		glVertex3f(40, -10, -0.1); //ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
//		glTexCoord2d(1, 1);		glVertex3f(90, -10, -0.1);
//		glTexCoord2d(1, 0);		glVertex3f(90, 30, -0.1);
//		glTexCoord2d(0, 0);		glVertex3f(40, 30, -0.1);
//		glEnd();
//
//		glEnable(GL_LIGHTING);
//		glDisable(GL_TEXTURE_2D);
//		*/
//
////FONDO 3//: UNIVERSIDAD
//		glEnable(GL_TEXTURE_2D);
//		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Universidad.png").id);
//		glDisable(GL_LIGHTING);
//		glBegin(GL_POLYGON);
//
//		glColor3f(1, 1, 1);
//		glTexCoord2d(0, 1);		glVertex3f(266, -10, -0.1); //ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
//		glTexCoord2d(1, 1);		glVertex3f(366, -10, -0.1);
//		glTexCoord2d(1, 0);		glVertex3f(366, 33, -0.1);
//		glTexCoord2d(0, 0);		glVertex3f(266, 33, -0.1);
//		glEnd();
//		glEnable(GL_LIGHTING);
//		glDisable(GL_TEXTURE_2D);
//		/*
//		glEnable(GL_TEXTURE_2D);
//		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo2.png").id);
//		glDisable(GL_LIGHTING);
//		glBegin(GL_POLYGON);
//
//		glColor3f(1, 1, 1);
//		glTexCoord2d(0, 1);		glVertex3f(90, -13, -0.1); //ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
//		glTexCoord2d(1, 1);		glVertex3f(160, -13, -0.1);
//		glTexCoord2d(1, 0);		glVertex3f(160, 30, -0.1);
//		glTexCoord2d(0, 0);		glVertex3f(90, 30, -0.1);
//		glEnd();
//		glEnable(GL_LIGHTING);
//		glDisable(GL_TEXTURE_2D);
//		*/
//
////FONDO 4//:HOSPITAL
//
//		glEnable(GL_TEXTURE_2D);
//		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/HospitalChina.png").id);
//		glDisable(GL_LIGHTING);
//		glBegin(GL_POLYGON);
//
//		glColor3f(1, 1, 1);
//		glTexCoord2d(0, 1);		glVertex3f(366, -10, -0.1); //ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
//		glTexCoord2d(1, 1);		glVertex3f(426, -10, -0.1);
//		glTexCoord2d(1, 0);		glVertex3f(426, 30, -0.1);
//		glTexCoord2d(0, 0);		glVertex3f(366, 30, -0.1);
//		glEnd();
//		glEnable(GL_LIGHTING);
//		glDisable(GL_TEXTURE_2D);
//		
//		break;
//	case 2:
//
////PRENIVEL
//
//		glEnable(GL_TEXTURE_2D);
//		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/prenivel.png").id);
//		glDisable(GL_LIGHTING);
//		glBegin(GL_POLYGON);
//
//		glColor3f(1, 1, 1);
//		glTexCoord2d(0, 1);		glVertex3f(-30, -10, -0.1);//ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
//		glTexCoord2d(1, 1);		glVertex3f(26, -10, -0.1);
//		glTexCoord2d(1, 0);		glVertex3f(26, 30, -0.1);
//		glTexCoord2d(0, 0);		glVertex3f(-30, 30, -0.1);
//		glEnd();
//		glEnable(GL_LIGHTING);
//		glDisable(GL_TEXTURE_2D);
//		//FONDO 1	//: AEROPUERTO
//
//		glEnable(GL_TEXTURE_2D);
//		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/aeropuerto.png").id);
//		glDisable(GL_LIGHTING);
//		glBegin(GL_POLYGON);
//
//		glColor3f(1, 1, 1);
//		glTexCoord2d(0, 1);		glVertex3f(26, -10, -0.1); //ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
//		glTexCoord2d(1, 1);		glVertex3f(126, -10, -0.1);
//		glTexCoord2d(1, 0);		glVertex3f(126, 45, -0.1);
//		glTexCoord2d(0, 0);		glVertex3f(26, 45, -0.1);
//		glEnd();
//
//
//		glEnable(GL_LIGHTING);
//		glDisable(GL_TEXTURE_2D);
//		//FONDO 2//: CENTRO COMERCIAL
//		glEnable(GL_TEXTURE_2D);
//		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/CentroComercial.png").id);
//		glDisable(GL_LIGHTING);
//		glBegin(GL_POLYGON);
//
//		glColor3f(1, 1, 1);
//		glTexCoord2d(0, 1);		glVertex3f(126, -9, -0.1); //ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
//		glTexCoord2d(1, 1);		glVertex3f(250, -9, -0.1);
//		glTexCoord2d(1, 0);		glVertex3f(250, 60, -0.1);
//		glTexCoord2d(0, 0);		glVertex3f(126, 60, -0.1);
//		glEnd();
//
//
//		glEnable(GL_LIGHTING);
//		glDisable(GL_TEXTURE_2D);
//		//FONDO 3//: PARQUE
//		glEnable(GL_TEXTURE_2D);
//		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Parque.png").id);
//		glDisable(GL_LIGHTING);
//		glBegin(GL_POLYGON);
//
//		glColor3f(1, 1, 1);
//		glTexCoord2d(0, 1);		glVertex3f(250, -9, -0.1); //ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
//		glTexCoord2d(1, 1);		glVertex3f(350, -9, -0.1);
//		glTexCoord2d(1, 0);		glVertex3f(350, 60, -0.1);
//		glTexCoord2d(0, 0);		glVertex3f(250, 60, -0.1);
//		glEnd();
//
//
//		glEnable(GL_LIGHTING);
//		glDisable(GL_TEXTURE_2D);
//		//FONDO 4//: HOSPITAL
//
//		
//		break;
//	case 3:
//
//	//FONDO 1//: PUERTO
//
//		glEnable(GL_TEXTURE_2D);
//		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/PuertoEspaña.png").id);
//		glDisable(GL_LIGHTING);
//		glBegin(GL_POLYGON);
//
//		glColor3f(1, 1, 1);
//		glTexCoord2d(0, 1);		glVertex3f(-20, -10 ,-0.1); //ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
//
//		glTexCoord2d(1, 1);		glVertex3f(60, -10, -0.1);
//		glTexCoord2d(1, 0);		glVertex3f(60,30, -0.1);
//		glTexCoord2d(0, 0);		glVertex3f(-20, 30, -0.1);
//		glEnd();
//
//		glEnable(GL_LIGHTING);
//		glDisable(GL_TEXTURE_2D);
//
//		glEnable(GL_TEXTURE_2D);
//		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/aeropuerto.png").id);
//		glDisable(GL_LIGHTING);
//		glBegin(GL_POLYGON);
//
//		glColor3f(1, 1, 1);
//		glTexCoord2d(0, 1);		glVertex3f(60, -10, -0.1); //ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
//		glTexCoord2d(1, 1);		glVertex3f(130, -10, -0.1);
//		glTexCoord2d(1, 0);		glVertex3f(130, 30, -0.1);
//		glTexCoord2d(0, 0);		glVertex3f(60, 30, -0.1);
//		glEnd();
//
//		glEnable(GL_LIGHTING);
//		glDisable(GL_TEXTURE_2D);
//
//		//FONDO 2//: PLAYA
//		//FONDO 3//: DISCOTECA
//		//FONDO 4//: HOSPITAL
//	
//		break;
//
//	}
	
