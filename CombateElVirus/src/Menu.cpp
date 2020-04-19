#include "Menu.h"
#include "ETSIDI.h"
#include "glut.h"


void Menu::Dibuja() {

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/menu.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);

	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);		glVertex3f(-40, -10, -0.1);//ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
	glTexCoord2d(1, 1);		glVertex3f(40, -10, -0.1);
	glTexCoord2d(1, 0);		glVertex3f(40, 30, -0.1);
	glTexCoord2d(0, 0);		glVertex3f(-40, 30, -0.1);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);


}