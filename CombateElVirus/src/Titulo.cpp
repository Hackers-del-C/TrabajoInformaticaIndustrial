#include "Titulo.h"

#include "ETSIDI.h"
#include "glut.h"

void Titulo::Nombre(int nivel) {
	// TEXTO //
	
	switch (nivel) {
	case 0:
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

		break;
	case 1:
		glTranslatef(-24, 25, 0);
		setTextColor(0, 0, 0); //FUNCIONA IGUAL QUE GLUT PERO EN VEZ DE 0-255 DE 0-1
		print("NIVEL 1", "fuentes/Bitwise.ttf", 36);
		glTranslated(3, -3, 0); //Como se mueve respecto al texto anterior
		print("CHINA", "fuentes/Bitwise.ttf", 40);
		glTranslatef(21, -22, 0);
		
		break;

	case 2:
		glTranslatef(-24, 25, 0);
		setTextColor(0, 0,0); //FUNCIONA IGUAL QUE GLUT PERO EN VEZ DE 0-255 DE 0-1
		print("NIVEL 2", "fuentes/Bitwise.ttf", 36);
		glTranslated(3, -3, 0);
		print("ITALIA", "fuentes/Bitwise.ttf", 40);
		glTranslatef(21, -22, 0);
		break;

	case 3:
		glTranslatef(-24, 25, 0);
		setTextColor(0, 0, 0); //FUNCIONA IGUAL QUE GLUT PERO EN VEZ DE 0-255 DE 0-1
		print("NIVEL 3", "fuentes/Bitwise.ttf", 36);
		glTranslated(3, -3, 0);//Como se mueve respecto al texto anterior
		print("ESPANIA", "fuentes/Bitwise.ttf", 40);
		glTranslatef(21, -22, 0);
		break;
	}
}
void Titulo::Bandera(int nivel) {
	switch (nivel) {
	case 1:
		bandera.Dibuja("banderachina", -4, 4, 22, 27);
		break;
	case 2:
		bandera.Dibuja("banderaitaliana", -4, 4, 22, 27);
		break;
	case 3:
		bandera.Dibuja("banderaespañola", -4, 4, 22, 27);
		break;
	}
}