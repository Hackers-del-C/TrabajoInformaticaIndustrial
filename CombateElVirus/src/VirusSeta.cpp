#include "VirusSeta.h"


using namespace ETSIDI;
using namespace std;
using ETSIDI::getTexture;

VirusSeta::~VirusSeta() {

}

VirusSeta::VirusSeta() {


}

VirusSeta::VirusSeta(string nombre, int m, int n, float x, float y, float w, float h, int izqder1, int salto1) {

    anchura = 0.4*w;//Redimensionamos ya que el recorte de la imagen no es perfecta
    altura = 0.4*h;

    izqder = izqder1; //Si el mu�eco puede ir a la izquierda y a la derecha
    salto = salto1;//Si el mu�eco puede saltar/atacar

    string nombreder = "imagenes/" + nombre + "der.png";
    string nombreizq = "imagenes/" + nombre + "izq.png";
    nombre = "imagenes/" + nombre + ".png";

    char* a = strcpy(new char[nombre.length() + 1], nombre.c_str());
    char* b = strcpy(new char[nombreder.length() + 1], nombreder.c_str());
    char* c = strcpy(new char[nombreizq.length() + 1], nombreizq.c_str());
    // char* b = strcpy(new char[nombrecompletoder.str().length() + 1], nombrecompletoder.str().c_str());
    // char* c = strcpy(new char[nombrecompletoizq.str().length() + 1], nombrecompletoizq.str().c_str());

    sprite = new SpriteSequence(a, m, n, 25, true, x, y, w, h);

    if (izqder == 1) {
        spriteder = new SpriteSequence(b, m, n, 25, true, x, y, w, h);
        spriteizq = new SpriteSequence(c, m, n, 25, true, x, y, w, h);
    }
    if (salto == 1) {
        spritemuere = new SpriteSequence("sangrevirus", m, n, 25, true, x - w / 2, y, w, h);

    }

}


void VirusSeta::Inicializa(string nombre, int m, int n, float x, float y, float w, float h, int izqder1, int salto1) {

  
    izqder = izqder1; //Si el mu�eco puede ir a la izquierda y a la derecha
    salto = salto1;//Si el mu�eco puede saltar/atacar

    anchura = 0.4 * w;//Redimensionamos ya que el recorte de la imagen no es perfecta
    altura = 0.4 * h;

    string nombreder = "imagenes/" + nombre + "der.png";
    string nombreizq = "imagenes/" + nombre + "izq.png";
    nombre = "imagenes/" + nombre + ".png";

    char* a = strcpy(new char[nombre.length() + 1], nombre.c_str());
    char* b = strcpy(new char[nombreder.length() + 1], nombreder.c_str());
    char* c = strcpy(new char[nombreizq.length() + 1], nombreizq.c_str());
    // char* b = strcpy(new char[nombrecompletoder.str().length() + 1], nombrecompletoder.str().c_str());
    // char* c = strcpy(new char[nombrecompletoizq.str().length() + 1], nombrecompletoizq.str().c_str());

    sprite = new SpriteSequence(a, m, n, 25, true, x, y, w, h);
    spritemuere = new SpriteSequence("imagenes/sangrevirus.png", 8, 1, 90, true, x - w / 2, y, 3, 3); //SOLO SE MUESTRA UNA VEZ, poner bien las coordenadas
    if (izqder == 1) {
        spriteder = new SpriteSequence(b, m, n, 25, true, x, y, w, h);
        spriteizq = new SpriteSequence(c, m, n, 25, true, x, y, w, h);
    }
    if (salto == 1) {

    }

}