#include "Virus.h"
#include "ETSIDI.h"
#include "glut.h"
using namespace ETSIDI;
using ETSIDI::getTexture;
Virus::Virus() {

}
Virus::~Virus() {

}
void Virus::Dibuja(int nivel)
{
   /* glTranslatef(5, -5, 0);

    switch (nivel) {
    case 1:
        
        virusamarillo->draw();
        break;
 
    case 2:
        virusazul->draw();
        break;
    case 3:
        virusrojo->draw();
        break;
    }
    glTranslatef(-5, 5, 0);*/

}
void Virus::Inicializa() {
   /*virusamarillo = new SpriteSequence("imagenes/Virusamarillo.png", 1, 1, 1, true, 4, 10, 10, 10);
   virusazul = new SpriteSequence("imagenes/Virusazul.png", 1, 3, 25, true, -2, 2, 5, 5);
   virusrojo = new SpriteSequence("imagenes/Virusrojo.png", 1, 3, 25, true, -2, 2, 5, 5);
   */
}
void Virus::Mueve(float t) {
   /* virusamarillo->loop();
    virusazul->loop();
    virusamarillo->loop();*/
}