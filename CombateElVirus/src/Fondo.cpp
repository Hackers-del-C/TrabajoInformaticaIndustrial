#include "Fondo.h"
#include "ETSIDI.h"
#include "glut.h"
void Fondo::Dibuja(float nivel) {
	if (nivel == 1) {

		//FONDO 1//
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo1.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);

		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);		glVertex3f(-30, -20, -0.1);//ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
		glTexCoord2d(1, 1);		glVertex3f(30, -20, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(30, 20, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-30, 20, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		//FONDO 2//

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

		//FONDO 3//: AEROPUERTO

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/aeropuerto.png").id);
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
	}
}