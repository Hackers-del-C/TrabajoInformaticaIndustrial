#include "Entorno.h"
#include "glut.h"
#include "ETSIDI.h"
void Entorno::Inicializa(int nivel) {
	//MUSICA
	switch (nivel) {
	case 0:
		ETSIDI::play("mis_sonidos/Menu.wav");
		break;
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

void Entorno::Dibuja(int nivel) {

	switch (nivel) {
	case 1:
		
		break;
	case 2:
		
		break;
	case 3:
		
		break;
	}
	switch (nivel) {
	case 0:	
		//IMAGENES
		fondo.Dibuja("menu", -26, 26, -10, 30); //limx1 limx2 limy1 limy2. La textura es cte -0.1		
		//TEXTO
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
		//IMAGENES
		bandera.Dibuja("banderachina", -4, 4, 22, 27);
		fondo.Dibuja("prenivel", -30, 26, -10, 30);
		fondo.Dibuja("laboratorio", 26, 156, -18, 45);
		//TEXTO
		glTranslatef(-24, 25, 0);
		setTextColor(0, 0, 0); //FUNCIONA IGUAL QUE GLUT PERO EN VEZ DE 0-255 DE 0-1
		print("NIVEL 1", "fuentes/Bitwise.ttf", 36);
		glTranslated(3, -3, 0); //Como se mueve respecto al texto anterior
		print("CHINA", "fuentes/Bitwise.ttf", 40);
		glTranslatef(21, -22, 0);
		break;
	case 2:
		//IMAGENES
		bandera.Dibuja("banderaitaliana", -4, 4, 22, 27);
		fondo.Dibuja("prenivel", -30, 26, -10, 30);
		//TEXTO
		glTranslatef(-24, 25, 0);
		setTextColor(0, 0, 0); //FUNCIONA IGUAL QUE GLUT PERO EN VEZ DE 0-255 DE 0-1
		print("NIVEL 2", "fuentes/Bitwise.ttf", 36);
		glTranslated(3, -3, 0);
		print("ITALIA", "fuentes/Bitwise.ttf", 40);
		glTranslatef(21, -22, 0);
		
		break;
	case 3:
		//IMAGENES
		bandera.Dibuja("banderaespañola", -4, 4, 22, 27);
		fondo.Dibuja("prenivel", -30, 26, -10, 30);
		//TEXTO
		glTranslatef(-24, 25, 0);
		setTextColor(0, 0, 0); //FUNCIONA IGUAL QUE GLUT PERO EN VEZ DE 0-255 DE 0-1
		print("NIVEL 3", "fuentes/Bitwise.ttf", 36);
		glTranslated(3, -3, 0);//Como se mueve respecto al texto anterior
		print("ESPANIA", "fuentes/Bitwise.ttf", 40);
		glTranslatef(21, -22, 0);
		break;
	}
	
}

void Entorno::Mueve(float t) {

}
void Entorno::Tecla(unsigned char key) {

	if (key == 'b') {
		ETSIDI::play("mis_sonidos/imbatman.wav");

	}
	if (key == 'a' || key == 's' || key == 'w' || key == 'd') {
		ETSIDI::play("mis_sonidos/disparo.wav");
	}
	if (key == 'v') {
		ETSIDI::play("mis_sonidos/alicates.wav");
	}


}