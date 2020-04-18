#include "Fondo.h"
#include "ETSIDI.h"
#include "glut.h"
void Fondo::Escenario(int nivel) {
	 //APUNTES
	/*
	La vision va si tomamos 0,0 
	en x: -10, 10
	en y: ?,15
	entonces. (x) como el muñeco puede ir hasta el -10. El escenario debe empezar en -20 
	
	
	*/
	switch (nivel) {
	case 1:

		//BANDERA//
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/banderachina.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);

		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);		glVertex3f(1, 8, -0.1);//ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
		glTexCoord2d(1, 1);		glVertex3f(6, 8, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(6, 11, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(1, 11, -0.1);
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
		glTexCoord2d(0, 1);		glVertex3f(30, -20, -0.1); //ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.

		glTexCoord2d(1, 1);		glVertex3f(90, -20, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(90, 20, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(30, 20, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		//FONDO 3//: UNIVERSIDAD

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo2.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);

		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);		glVertex3f(90, -18, -0.1); //ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.

		glTexCoord2d(1, 1);		glVertex3f(160, -18, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(160, 22, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(90, 22, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		//FONDO 4//:HOSPITAL

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/HospitalChina.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);

		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);		glVertex3f(160, -18, -0.1); //ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.

		glTexCoord2d(1, 1);		glVertex3f(220, -18, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(220, 14, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(160, 14, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		
		break;
	case 2:

		//BANDERA//
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/banderaitaliana.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);

		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);		glVertex3f(1, 8, -0.1);//ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
		glTexCoord2d(1, 1);		glVertex3f(6, 8, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(6, 11, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(1, 11, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		//FONDO 1	//: AEROPUERTO

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/aeropuerto.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);

		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);		glVertex3f(-20, -18, -0.1); //ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.

		glTexCoord2d(1, 1);		glVertex3f(50, -18, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(50, 22, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-20, 22, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/aeropuerto.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);

		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);		glVertex3f(-40, -18, -0.1); //ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.

		glTexCoord2d(1, 1);		glVertex3f(20, -18, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(20, 22, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-40, 22, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		//FONDO 2//: CENTRO COMERCIAL
		//FONDO 3//: PARQUE
		//FONDO 4//: HOSPITAL
		
		break;
	case 3:

		//BANDERA//
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/banderaespañola.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);

		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);		glVertex3f(1, 8.5, -0.1);//ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
		glTexCoord2d(1, 1);		glVertex3f(6, 8.5, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(6, 11.5, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(1, 11.5, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);


		//FONDO 1//: PUERTO

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/PuertoEspaña.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);

		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);		glVertex3f(-20, -8 ,-0.1); //ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.

		glTexCoord2d(1, 1);		glVertex3f(60, -8, -0.1);
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
		glTexCoord2d(0, 1);		glVertex3f(160, -18, -0.1); //ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.

		glTexCoord2d(1, 1);		glVertex3f(230, -18, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(230, 22, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(160, 22, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		//FONDO 2//: PLAYA
		//FONDO 3//: DISCOTECA
		//FONDO 4//: HOSPITAL
	
		break;

	}
	
}


void Fondo::Musica(int nivel) { //NO VA :c
	switch (nivel) {
	case 1:
		ETSIDI::play("mis_sonidos/China.wav");
		break;
	case 2:
		ETSIDI::play("mis_sonidos/Italia.wav");
		break;
	case 3:
		ETSIDI::play("mis_sonidos/Espania.wav");
		break;
	}
	
}
void Fondo::Titulo(int nivel) {
			// TEXTO //
	switch (nivel) {
	case 1:		
		glTranslatef(-8, 9, 0);
		setTextColor(1, 1, 1); //FUNCIONA IGUAL QUE GLUT PERO EN VEZ DE 0-255 DE 0-1
		print("NIVEL 1", "fuentes/Bitwise.ttf", 36);
		setTextColor(1, 1, 1);//Tiene capacidad para un nº mas pero no se pa que sirve
		glTranslated(2, -2, 0); //Como se mueve respecto al texto anterior
		print("CHINA", "fuentes/Bitwise.ttf", 40);
		glTranslatef(8, -9, 0);
		///////////////////////////////////////////////
		break;

	case 2:		
		glTranslatef(-8, 9, 0);
		setTextColor(1, 1, 1); //FUNCIONA IGUAL QUE GLUT PERO EN VEZ DE 0-255 DE 0-1
		print("NIVEL 2", "fuentes/Bitwise.ttf", 36);
		setTextColor(1, 1, 1);//Tiene capacidad para un nº mas pero no se pa que sirve
		glTranslated(2, -2, 0); //Como se mueve respecto al texto anterior
		print("ITALIA", "fuentes/Bitwise.ttf", 40);
		glTranslatef(8, -9, 0);
		break;

	case 3:		
		glTranslatef(-8, 9, 0);
		setTextColor(1, 1, 1); //FUNCIONA IGUAL QUE GLUT PERO EN VEZ DE 0-255 DE 0-1
		print("NIVEL 3", "fuentes/Bitwise.ttf", 36);
		setTextColor(1, 1, 1);//Tiene capacidad para un nº mas pero no se pa que sirve
		glTranslated(2, -2, 0);//Como se mueve respecto al texto anterior
		print("ESPANIA", "fuentes/Bitwise.ttf", 40);
		glTranslatef(8, -9, 0);
		break;
	}
	

}