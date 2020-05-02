#include "Menu.h"
#include "ETSIDI.h"
#include "glut.h"
Menu::Menu() {
	level = 0;
}
void Menu::Texto() {	
	
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
