#include "Menu.h"
#include "ETSIDI.h"
#include "glut.h"


void Menu::Dibuja() {

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/menu.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);

	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);		glVertex3f(-26, -10, -0.1);//ancho, alto e identificaciónde de la textura cargada en el Sistema gráfico.
	glTexCoord2d(1, 1);		glVertex3f(26, -10, -0.1);
	glTexCoord2d(1, 0);		glVertex3f(26, 30, -0.1);
	glTexCoord2d(0, 0);		glVertex3f(-26, 30, -0.1);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);


}
void Menu::Texto() {
	glTranslatef(-23, 16, 0);
	setTextColor(0, 0, 0); //FUNCIONA IGUAL QUE GLUT PERO EN VEZ DE 0-255 DE 0-1
	print("COMBATE EL VIRUS ", "fuentes/Bitwise.ttf", 50);
	glTranslated(1, -4, 0); //Como se mueve respecto al texto anterior
	print("Nivel 1. China", "fuentes/Bitwise.ttf", 20);
	glTranslated(0, -2, 0); //Como se mueve respecto al texto anterior
	print("Nivel 2. Italia", "fuentes/Bitwise.ttf", 20);
	glTranslated(0, -2, 0); //Como se mueve respecto al texto anterior
	print("Nivel 3. Espania", "fuentes/Bitwise.ttf", 20);
	glTranslated(0, -2, 0); //Como se mueve respecto al texto anterior
	print("Nivel 4. EEUU", "fuentes/Bitwise.ttf", 20);
	glTranslatef(22, -6, 0);
}
void Menu::Tecla(unsigned char key) {
	switch (key) {
	case '1':
		level = 1;
		break;
	case '2':
		level = 2;
		break;
	case '3':
		level = 3;
		break;
	}
}