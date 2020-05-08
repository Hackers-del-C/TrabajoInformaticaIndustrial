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

void Entorno::Dibuja(int nivel,int xraton,int yraton) {

	switch (nivel) {
	case 0:
		//IMAGENES
		auxetsidi.Imagen("menu", -26, 26, -10, 30); //limx1 limx2 limy1 limy2. La textura es cte -0.1		
		if (yraton > 250 && yraton<270) {
			gl1 = 1;
			gl2 = 0;
			gl3 = 0;
		}
		else if (yraton > 280 && yraton <= 300) {
			gl1 = 0;
			gl2 = 1;
			gl3 = 0;
		}
		else if (yraton > 310 && yraton <= 330) {
			gl1 = 0;
			gl2 = 0;
			gl3 = 1;
		}
		else {
			gl1 = 0;
			gl2 = 0;
			gl3 = 0;
		}			
		//TEXTO
		auxetsidi.Texto("COMBATE EL VIRUS", -23, 16, 0, 0, 0, 50);
		auxetsidi.Texto("Nivel 1. China", -22, 12, 0, gl1, 0, 20);
		auxetsidi.Texto("Nivel 2. Italia", -22, 10, 0, gl2, 0, 20);
		auxetsidi.Texto("Nivel 3. Espanita", -22, 8, 0, gl3, 0, 20);
		break;

	case 1:
		//IMAGENES
		auxetsidi.Imagen("banderachina", -4, 4, 22, 27);
		auxetsidi.Imagen("AvionMiguelAvion", 245, 255, 22, 27);
		auxetsidi.Imagen("prenivel", -30, 26, -10, 30);
		auxetsidi.Imagen("fondobasico", 26, 82, -10, 30);
		auxetsidi.Imagen("fondobasico", 82, 138, -10, 30);
		auxetsidi.Imagen("fondobasico", 138, 194, -10, 30);
		auxetsidi.Imagen("fondobasico", 194, 250, -10, 30);
		auxetsidi.Imagen("fondobasico", 250, 306, -10, 30);
		
		//auxetsidi.Imagen("laboratorio", 26, 156, -18, 45);
		//TEXTO
		auxetsidi.Texto("NIVEL 1", -24, 25, 0, 0, 0, 36);
		auxetsidi.Texto("CHINA", -21, 22, 0, 0, 0, 40);

		break;
	case 2:
		//IMAGENES
		auxetsidi.Imagen("banderaitaliana", -4, 4, 22, 27);
		auxetsidi.Imagen("prenivel", -30, 26, -10, 30);
		auxetsidi.Imagen("fondobasico", 26, 82, -10, 30);
		auxetsidi.Imagen("fondobasico", 82, 138, -10, 30);
		auxetsidi.Imagen("fondobasico", 138, 194, -10, 30);
		auxetsidi.Imagen("fondobasico", 194, 250, -10, 30);
		auxetsidi.Imagen("fondobasico", 250, 306, -10, 30);
		//TEXTO
		auxetsidi.Texto("NIVEL 2", -24, 25, 0, 0, 0, 36);
		auxetsidi.Texto("ITALIA", -21, 22, 0, 0, 0, 40);

		break;
	case 3:
		//IMAGENES
		auxetsidi.Imagen("banderaespañola", -4, 4, 22, 27);
		auxetsidi.Imagen("prenivel", -30, 26, -10, 30);
		auxetsidi.Imagen("fondobasico", 26, 82, -10, 30);
		auxetsidi.Imagen("fondobasico", 82, 138, -10, 30);
		auxetsidi.Imagen("fondobasico", 138, 194, -10, 30);
		auxetsidi.Imagen("fondobasico", 194, 250, -10, 30);
		auxetsidi.Imagen("fondobasico", 250, 306, -10, 30);
		//TEXTO
		auxetsidi.Texto("NIVEL 3", -24, 25, 0, 0, 0, 36);
		auxetsidi.Texto("ESPANIA", -21, 22, 0, 0, 0, 40);
		break;


	}
}
void Entorno::Aviso(int pantalla, int x, int y,int xraton, int yraton) {
	//IMAGEN:es un cuadro negro para que salga bien los datos que queramos en medio but no consigo que vaya
	
	switch(pantalla){
	case 1: //pantalla si mueres
		auxetsidi.Imagen("aviso", x - 12.5, x + 12.5, y + 5, y + 20);
		//TEXTO
		auxetsidi.Texto("F", x , y + 17, 1, 0, 0, 10);
		auxetsidi.Texto("REINICIAR EL NIVEL", x-6, y+16, 1, 1, 1, 10); //obv habrá que hacerlo con otras teclas u otra cosa
		auxetsidi.Texto("MENU PRINCIPAL", x-6,y+15, 1, 1, 1, 10);
		
		break;
	case 2: //pantalla si ganas	
		auxetsidi.Imagen("aviso", x - 12.5, x + 12.5, y + 5, y + 20);
		//TEXTO
		auxetsidi.Texto("CONGRATULATIONS BRO", x-3, y + 18, 1, 0, 0, 10);
		auxetsidi.Texto("SIGUIENTE NIVEL", x - 8, y + 16, 1, 1, 1, 8);
		auxetsidi.Texto("MENU PRINCIPAL", x - 8, y + 13, 1, 1, 1, 8);
		
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