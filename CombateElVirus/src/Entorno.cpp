#include "Entorno.h"

#include "glut.h"
#include "ETSIDI.h"
void Entorno::Inicializa(int nivel) {
	musica.SoundOn(nivel);
	
}

void Entorno::Dibuja(int nivel) {

	titulo.Nombre(nivel);
	titulo.Bandera(nivel);
	switch (nivel) {
	case 0:
		fondo.Dibuja("menu", -26, 26, -10, 30); //limx1 limx2 limy1 limy2. La textura es cte -0.1
		break;
	case 1:
		fondo.Dibuja("prenivel", -30, 26, -10, 30);
		fondo.Dibuja("laboratorio", 26, 156, -18, 45);
		break;
	case 2:
		fondo.Dibuja("prenivel", -30, 26, -10, 30);
		break;
	case 3:
		fondo.Dibuja("prenivel", -30, 26, -10, 30);
		break;
	}
}

void Entorno::Mueve(float t) {
/*	explosion->loop();
	trump->loop();
	virus->loop();
	ninja->loop();
	*/
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