#include "Fondo.h"
#include "ETSIDI.h"
#include "glut.h"
void Fondo::Dibuja(int nivel) {
	 //APUNTES
	/*
	La vision va si tomamos 0,0 
	en x: -10, 10
	en y: ?,15
	entonces. (x) como el muñeco puede ir hasta el -10. El escenario debe empezar en -20 
	
	
	*/
	switch (nivel) {
	case 0:
		menu.Dibuja();
		break;

	case 1:
		//plataforma1//
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/banderachina.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);

		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);		glVertex3f(30, 5, -0.1);//ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
		glTexCoord2d(1, 1);		glVertex3f(60, 5, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(60, 10, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(30, 10, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		//FONDO 1//: LABORATORIO
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo1.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);

		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);		glVertex3f(-20, -10, -0.1);//ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
		glTexCoord2d(1, 1);		glVertex3f(40, -10, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(40, 30, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-20, 30, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		//FONDO 2//: SUPERMERCADO

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo2.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);

		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);		glVertex3f(40, -10, -0.1); //ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
		glTexCoord2d(1, 1);		glVertex3f(90, -10, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(90, 30, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(40, 30, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		//FONDO 3//: UNIVERSIDAD

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo2.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);

		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);		glVertex3f(90, -10, -0.1); //ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
		glTexCoord2d(1, 1);		glVertex3f(160, -10, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(160, 30, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(90, 30, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		//FONDO 4//:HOSPITAL

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/HospitalChina.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);

		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);		glVertex3f(160, -10, -0.1); //ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
		glTexCoord2d(1, 1);		glVertex3f(220, -10, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(220, 30, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(160, 30, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		
		break;
	case 2:

		
		//FONDO 1	//: AEROPUERTO

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/aeropuerto.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);

		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);		glVertex3f(-20, -10, -0.1); //ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
		glTexCoord2d(1, 1);		glVertex3f(50, -10, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(50, 30, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-20, 30, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/aeropuerto.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);

		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);		glVertex3f(50, -10, -0.1); //ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
		glTexCoord2d(1, 1);		glVertex3f(120, -10, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(120, 30, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(50, 30, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		//FONDO 2//: CENTRO COMERCIAL
		//FONDO 3//: PARQUE
		//FONDO 4//: HOSPITAL
		
		break;
	case 3:

	//FONDO 1//: PUERTO

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/PuertoEspaña.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);

		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);		glVertex3f(-20, -10 ,-0.1); //ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.

		glTexCoord2d(1, 1);		glVertex3f(60, -10, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(60,30, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-20, 30, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/aeropuerto.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);

		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);		glVertex3f(60, -10, -0.1); //ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
		glTexCoord2d(1, 1);		glVertex3f(130, -10, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(130, 30, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(60, 30, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		//FONDO 2//: PLAYA
		//FONDO 3//: DISCOTECA
		//FONDO 4//: HOSPITAL
	
		break;

	}
	
}

