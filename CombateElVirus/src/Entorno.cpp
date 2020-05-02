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
		auxetsidi.Imagen("menu", -26, 26, -10, 30); //limx1 limx2 limy1 limy2. La textura es cte -0.1		
		//TEXTO
		auxetsidi.Texto("COMBATE EL VIRUS", -23, 16, 0, 0, 0, 50);
		auxetsidi.Texto("Nivel 1. China", -22, 12, 0, 0, 0, 20);
		auxetsidi.Texto("Nivel 2. Italia", -22, 10, 0, 0, 0, 20);
		auxetsidi.Texto("Nivel 3. España", -22, 8, 0, 0, 0, 20);
		
		break;
	case 1:
		//IMAGENES
		auxetsidi.Imagen("banderachina", -4, 4, 22, 27);
		auxetsidi.Imagen("prenivel", -30, 26, -10, 30);
		auxetsidi.Imagen("laboratorio", 26, 156, -18, 45);
		//TEXTO
		auxetsidi.Texto("NIVEL 1", -24, 25, 0, 0, 0, 36);
		auxetsidi.Texto("CHINA", -21, 22, 0, 0, 0, 40);
		
		break;
	case 2:
		//IMAGENES
		auxetsidi.Imagen("banderaitaliana", -4, 4, 22, 27);
		auxetsidi.Imagen("prenivel", -30, 26, -10, 30);
		//TEXTO
		auxetsidi.Texto("NIVEL 2", -24, 25, 0, 0, 0, 36);
		auxetsidi.Texto("ITALIA", -21, 22, 0, 0, 0, 40);
		
		break;
	case 3:
		//IMAGENES
		auxetsidi.Imagen("banderaespañola", -4, 4, 22, 27);
		auxetsidi.Imagen("prenivel", -30, 26, -10, 30);
		//TEXTO
		auxetsidi.Texto("NIVEL 3", -24, 25, 0, 0, 0, 36);
		auxetsidi.Texto("ESPANIA", -21, 22, 0, 0, 0, 40);
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