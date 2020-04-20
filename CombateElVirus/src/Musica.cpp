#include "Musica.h"
#include "ETSIDI.h"
void Musica::SoundOn(int nivel) {
	switch (nivel) {
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


