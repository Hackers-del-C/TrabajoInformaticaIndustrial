#include "Coordinador.h"
#include "glut.h"


Coordinador combate;

void OnDraw(void); 
void OnTimer(int value); 
void OnKeyboardDown(unsigned char key, int x, int y);	
void OnSpecialKeyboardDown(int key, int x, int y);
void OnMouseClick(int button, int state, int x, int y);
void OnMouseMotion(int x, int y);

int main(int argc,char* argv[])
{
	
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("CombateElVirus");

	
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150);

	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);
	glutIgnoreKeyRepeat(1);
	glutSpecialFunc(OnSpecialKeyboardDown);
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(OnMouseClick);
	glutPassiveMotionFunc(OnMouseMotion);
	
	combate.Inicializa();

	glutMainLoop();	

	return 0;   
}

void OnDraw(void)
{
	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	
	combate.Dibuja();
	
	glutSwapBuffers();
}
void OnSpecialKeyboardDown(int key, int x, int y)
{
	combate.teclaEspecial(key);
}


void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	
	combate.tecla(key);

	glutPostRedisplay();
}
void OnMouseClick(int b, int state, int x, int y){ //click del raton
	combate.ClickMouse(b, state);

	glutPostRedisplay();
}
void OnMouseMotion(int x, int y) { //movimiento del raton
	combate.MyMouse(x, y);

	glutPostRedisplay();
}

void OnTimer(int value)
{

	combate.Mueve();
	
	
	glutTimerFunc(25,OnTimer,0);
	glutPostRedisplay();
}
