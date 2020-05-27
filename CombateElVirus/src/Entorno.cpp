#include "Entorno.h"
#include "glut.h"
#include "ETSIDI.h"
void Entorno::Musica(int nivel) {
	//MUSICA
	switch (nivel) {
	case 0:
		ETSIDI::playMusica("mis_sonidos/menu.wav",false);
		
		break;
	case 1:
		stopMusica();
		ETSIDI::playMusica("mis_sonidos/China.wav",false);
		
		break;
	case 2:
		stopMusica();
		ETSIDI::playMusica("mis_sonidos/Italia.wav",false);
		
		break;
	case 3:
		stopMusica();
		ETSIDI::playMusica("mis_sonidos/Espania.wav",false);
		
		break;		
	}	
}

void Entorno::Fin(int pantalla) {
	switch (pantalla) {
	case 1:
		//MUSICA 
		stopMusica();
		ETSIDI::play("mis_sonidos/Muerte.wav");
		break;
	case 2:
		stopMusica();
		ETSIDI::play("mis_sonidos/Ganador.wav");
		break;
	}
}
void Entorno::DibujaMenu(int xraton, int yraton,int aux,int avance_nivel) {
	//IMAGENES
	auxetsidi.Imagen("menu", -26, 26, -10, 30); //limx1 limx2 limy1 limy2. La textura es cte -0.1		
	if ((yraton > 11 && yraton < 13)|| aux==1) {
		gl1 = 1;
		gl2 = 0;
		gl3 = 0;
		
	}
	else if (((yraton > 9 && yraton <= 11)|| aux == 2)&& avance_nivel>=1) {		
			gl1 = 0;
			gl2 = 1;
			gl3 = 0;	
		
		
	}
	else if (((yraton > 7 && yraton <= 9)|| aux == 3) && avance_nivel>=2) {
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
	auxetsidi.Texto("-Nivel 1. China", -22, 12, 0, gl1, 0, 20);
	auxetsidi.Texto("-Nivel 2. Italia", -22, 10, 0, gl2, 0, 20);
	auxetsidi.Texto("-Nivel 3. Espanita", -22, 8, 0, gl3, 0, 20);
	auxetsidi.Texto("-Pulsa S para salir", -12, 0,0,0,0, 20);
	
}
void Entorno::AvisoAvanceNivel() {
	
		auxetsidi.Texto("Tienes que pasarte el nivel anterior",2, 12, 0.44, 0.87, 0.45, 10);

}
void Entorno::DibujaJuego(int nivel) {

	switch (nivel) {

	case 1:
		//IMAGENES
		auxetsidi.Imagen("banderachina", -4, 4, 22, 27);
		//auxetsidi.Imagen("AvionMiguelAvion", 245, 255, 22, 27); -- IDIOTA
		auxetsidi.Imagen("PrenivelChina", -30, 26, -10, 30);
		auxetsidi.Imagen("NivelChina", 26, 82, -10, 30);
		auxetsidi.Imagen("NivelChina", 82, 138, -10, 30);
		auxetsidi.Imagen("NivelChina", 138, 194, -10, 30);
		auxetsidi.Imagen("BatallaFinalChina", 194, 250, -10, 30);
		auxetsidi.Imagen("NivelChina", 250, 306, -10, 30);
		
		//auxetsidi.Imagen("laboratorio", 26, 156, -18, 45);
		//TEXTO
		auxetsidi.Texto("NIVEL 1", -24, 25, 0, 0, 0, 36);
		auxetsidi.Texto("CHINA", -21, 22, 0, 0, 0, 40);

		break;
	case 2:
		//IMAGENES
		auxetsidi.Imagen("banderaitaliana", -4, 4, 19, 24);
		auxetsidi.Imagen("PrenivelItalia", -30, 26, -10, 30);
		auxetsidi.Imagen("NivelItalia", 26, 82, -10, 30);
		auxetsidi.Imagen("NivelItalia", 82, 138, -10, 30);
		auxetsidi.Imagen("NivelItalia", 138, 194, -10, 30);
		auxetsidi.Imagen("BatallaFinalItalia", 194, 250, -10, 30);
		auxetsidi.Imagen("NivelItalia", 250, 306, -10, 30);
		//TEXTO
		auxetsidi.Texto("NIVEL 2", -24, 22, 0, 0, 0, 36);
		auxetsidi.Texto("ITALIA", -21, 19, 0, 0, 0, 40);

		break;
	case 3:
		//IMAGENES
		auxetsidi.Imagen("banderaespañola", -4, 4, 19, 24);
		auxetsidi.Imagen("PrenivelEspaña", -30, 26, -10, 30);
		auxetsidi.Imagen("NivelEspaña", 26, 82, -10, 30);
		auxetsidi.Imagen("NivelEspaña", 82, 138, -10, 30);
		auxetsidi.Imagen("NivelEspaña", 138, 194, -10, 30);
		auxetsidi.Imagen("BatallaFinalEspaña", 194, 250, -10, 30);
		auxetsidi.Imagen("NivelEspaña", 250, 306, -10, 30);
		//TEXTO
		auxetsidi.Texto("NIVEL 3", -24, 22, 0, 0, 0, 36);
		auxetsidi.Texto("ESPANIA", -21, 19, 0, 0, 0, 40);
		break;


	}
}

void Entorno::Aviso(int pantalla, int x, int y) {
	//IMAGEN:es un cuadro negro para que salga bien los datos que queramos en medio but no consigo que vaya

	switch (pantalla) {
	case 1: //pantalla si mueres
		auxetsidi.Imagen("aviso", x - 12.5, x + 12.5, 2, 17);
		auxetsidi.Texto("F Perdiste...", x - 5.5, 13, 0.44, 0.87, 0.45, 20);
		auxetsidi.Texto("Pulsa 8  para REINICIAR EL NIVEL", x - 10, 9, 1, 1, 1, 12); //obv habrá que hacerlo con otras teclas u otra cosa
		auxetsidi.Texto("Pulsa 7 ir al MENU PRINCIPAL", x - 10, 7, 1, 1, 1, 12);
		break;

	case 2: //pantalla si ganas	
		auxetsidi.Imagen("aviso", x - 12.5, x + 12.5, 2, 17);
		//TEXTO
		auxetsidi.Texto("HAS GANADO", x - 5.5, 13, 0.44, 0.87, 0.45, 20);
		auxetsidi.Texto("Pulsa 8 para ir al SIGUIENTE NIVEL", x - 10, 9, 1, 1, 1, 12);
		auxetsidi.Texto("Pulsa 7 para ir al MENU PRINCIPAL", x - 10, 7, 1, 1, 1, 12);
		break;
	case 3:
		auxetsidi.Imagen("aviso", x - 12.5, x + 12.5, 2, 17);
		//TEXTO

		auxetsidi.Texto("PAUSA", x - 3, 13, 0.44, 0.87, 0.45, 20);
		auxetsidi.Texto("Pulsa C para reiniciar", x - 7, 9, 1, 1, 1, 15);
		auxetsidi.Texto("Pulsa M para ir al menu", x - 7, 7, 1, 1, 1, 15);
		break;

	case 4:
		auxetsidi.Imagen("aviso", x - 12.5, x + 12.5, 2, 17);
		//TEXTO

		auxetsidi.Texto("HAS GANADO", x - 5, 13, 0.44, 0.87, 0.45, 20);
		auxetsidi.Texto("CONSEGUISTE LA CURA ", x - 8, 11, 0.44, 0.87, 0.45, 15);
		auxetsidi.Texto("AL CORONAVIRUS ", x - 8, 9, 0.44, 0.87, 0.45, 15);		
		auxetsidi.Texto("Pulsa 7 para ir al menu", x - 7, 7, 1, 1, 1, 15);
	}
}
