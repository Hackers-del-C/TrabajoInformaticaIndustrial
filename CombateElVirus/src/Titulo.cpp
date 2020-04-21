#include "Titulo.h"
#include "ETSIDI.h"
#include "glut.h"

void Titulo::Nombre(int nivel) {
	// TEXTO //
	switch (nivel) {
	case 0:
		menu.Texto();
		break;
	case 1:
		glTranslatef(-24, 25, 0);
		setTextColor(0, 0, 0); //FUNCIONA IGUAL QUE GLUT PERO EN VEZ DE 0-255 DE 0-1
		print("NIVEL 1", "fuentes/Bitwise.ttf", 36);
		glTranslated(3, -3, 0); //Como se mueve respecto al texto anterior
		print("CHINA", "fuentes/Bitwise.ttf", 40);
		glTranslatef(21, -22, 0);
		///////////////////////////////////////////////
		break;

	case 2:
		glTranslatef(12, 25, 0);
		setTextColor(1, 1, 1); //FUNCIONA IGUAL QUE GLUT PERO EN VEZ DE 0-255 DE 0-1
		print("NIVEL 2", "fuentes/Bitwise.ttf", 36);
		glTranslated(3, -3, 0);
		print("ITALIA", "fuentes/Bitwise.ttf", 40);
		glTranslatef(-15, -22, 0);
		break;

	case 3:
		glTranslatef(12, 25, 0);
		setTextColor(1, 1, 1); //FUNCIONA IGUAL QUE GLUT PERO EN VEZ DE 0-255 DE 0-1
		print("NIVEL 3", "fuentes/Bitwise.ttf", 36);
		glTranslated(-1, -3, 0);//Como se mueve respecto al texto anterior
		print("ESPANIA", "fuentes/Bitwise.ttf", 40);
		glTranslatef(-11, -22, 0);
		break;
	}


}
void Titulo::Bandera(int nivel) {
	switch (nivel) {
	case 1:

		//BANDERA//
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/banderachina.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);

		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);		glVertex3f(-4, 22, -0.1);//ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
		glTexCoord2d(1, 1);		glVertex3f(4, 22, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(4, 27, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-4, 27, -0.1);
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
		glTexCoord2d(0, 1);		glVertex3f(27, 22, -0.1);//ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
		glTexCoord2d(1, 1);		glVertex3f(35, 22, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(35, 27, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(27, 27, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;
	case 3:
		//BANDERA//
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/banderaespañola.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);

		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);		glVertex3f(27, 22, -0.1);//ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
		glTexCoord2d(1, 1);		glVertex3f(35, 22, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(35, 27, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(27, 27, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;
	}

}