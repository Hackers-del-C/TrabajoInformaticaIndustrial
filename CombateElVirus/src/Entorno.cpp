#include "Entorno.h"
#include "glut.h"
#include "ETSIDI.h"
void Entorno::Inicializa(int nivel) {
	//MUSICA
	switch (nivel) {
	case 0:
		stopMusica();
		ETSIDI::play("mis_sonidos/menu.wav");//marco no toques por dios
		
		break;
	case 1:
		stopMusica();
		ETSIDI::play("mis_sonidos/China.wav");
		break;
	case 2:
		stopMusica();
		ETSIDI::play("mis_sonidos/Italia.wav");
		break;
	case 3:
		stopMusica();
		ETSIDI::play("mis_sonidos/Espania.wav");
		break;		
	}	
}
void Entorno::Fin(int pantalla) {
	switch (pantalla) {
	case 1:
		//MUSICA 
		stopMusica();
		ETSIDI::play("mis_sonidos/Muerte.wav");
	case 2:
		stopMusica();
		ETSIDI::play("mis_sonidos/Ganador.wav");
	}
}

void Entorno::Dibuja(int nivel) {

	switch (nivel) {
	case 0:
		//IMAGENES
		auxetsidi.Imagen("menu", -26, 26, -10, 30); //limx1 limx2 limy1 limy2. La textura es cte -0.1		
		//TEXTO
		auxetsidi.Texto("COMBATE EL VIRUS", -23, 16, 0, 0, 0, 50);
		auxetsidi.Texto("Nivel 1. China", -22, 12, 0, 0, 0, 20);
		auxetsidi.Texto("Nivel 2. Italia", -22, 10, 0, 0, 0, 20);
		auxetsidi.Texto("Nivel 3. Espanita", -22, 8, 0, 0, 0, 20);

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
		auxetsidi.Imagen("banderaespa�ola", -4, 4, 22, 27);
		auxetsidi.Imagen("prenivel", -30, 26, -10, 30);
		//TEXTO
		auxetsidi.Texto("NIVEL 3", -24, 25, 0, 0, 0, 36);
		auxetsidi.Texto("ESPANIA", -21, 22, 0, 0, 0, 40);
		break;


	}
}
void Entorno::Aviso(int pantalla, int x, int y) {
	//IMAGEN:es un cuadro negro para que salga bien los datos que queramos en medio but no consigo que vaya
	
	switch(pantalla){
	case 1: //pantalla si mueres
		auxetsidi.Imagen("aviso", x - 10, x + 10, y + 10, y + 20);
		//TEXTO
		auxetsidi.Texto("F", x , y + 18, 1, 0, 0, 10);
		auxetsidi.Texto("PULSA 8 PARA REINICIAR EL NIVEL", x-8, y+16, 1, 1, 1, 8); //obv habr� que hacerlo con otras teclas u otra cosa
		auxetsidi.Texto("PULSA 7 PARA VOLVER AL MENU PRINCIPAL", x-8,y+13, 1, 1, 1, 8);
		
		break;
	case 2: //pantalla si ganas	
		auxetsidi.Imagen("aviso", x - 10, x + 10, y + 10, y + 20);
		//TEXTO
		auxetsidi.Texto("CONGRATULATIONS BRO", x-3, y + 18, 1, 0, 0, 10);
		auxetsidi.Texto("PULSA 8 PARA PASAR AL SIGUIENTE NIVEL", x - 8, y + 16, 1, 1, 1, 8);
		auxetsidi.Texto("PULSA 7 PARA VOLVER AL MENU PRINCIPAL", x - 8, y + 13, 1, 1, 1, 8);
		
		break;
	}
}

void Entorno::Tecla(unsigned char key) {

	if (key == 'b') {
		ETSIDI::play("mis_sonidos/imbatman.wav");

	}
	/*if (key == 'a' || key == 's' || key == 'w' || key == 'd') {
		ETSIDI::play("mis_sonidos/disparo.wav");
	}*/
	if (key == 'v') {
		ETSIDI::play("mis_sonidos/alicates.wav");
	}
	if (key == 'g') {
		ETSIDI::play("mis_sonidos/nivel1.wav");
	}
	
}