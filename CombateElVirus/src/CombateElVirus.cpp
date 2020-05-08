#include "Mundo.h"
#include "glut.h"


Mundo mundo;

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
//void OnTimer2(int value);
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void OnSpecialKeyboardDown(int key, int x, int y);
void OnMouseClick(int button, int state, int x, int y);
void OnMouseMotion(int x, int y);

int main(int argc,char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("CombateElVirus");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
//	glutTimerFunc(2000, OnTimer2, 1);
	glutIgnoreKeyRepeat(1);
	glutSpecialFunc(OnSpecialKeyboardDown);
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(OnMouseClick);
	glutPassiveMotionFunc(OnMouseMotion);
	mundo.Inicializa();

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	

	return 0;   
}

void OnDraw(void)
{
	//Borrado de la pantalla	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	
	mundo.Dibuja();
	
	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnSpecialKeyboardDown(int key, int x, int y)
{
	mundo.teclaEspecial(key);
}

void SpecialKeyboardUp(int key, int x, int y)
{
	mundo.teclaEspecialsuelta(key);
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado
	mundo.Tecla(key);

	glutPostRedisplay();
}
void OnMouseClick(int b, int state, int x, int y){ //click del raton
	mundo.ClickMouse(b, state);

	glutPostRedisplay();
}
void OnMouseMotion(int x, int y) { //movimiento del raton
	mundo.MyMouse(x, y);

	glutPostRedisplay();
}

void OnTimer(int value)
{
//poner aqui el código de animacion
	mundo.Mueve();
	
	//no borrar estas lineas
	glutTimerFunc(25,OnTimer,0);
	glutPostRedisplay();
}
//void OnTimer2(int value) {
//
//
//	mundo.Interaccion();
//	glutTimerFunc(2000, OnTimer, 1);
//	glutPostRedisplay();
//}

