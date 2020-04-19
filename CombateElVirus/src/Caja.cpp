#include "Caja.h"
#include "glut.h"

void Caja::Dibuja()
{ 
}

Caja::Caja(){

      
        suelo.SetPos(-20, 0, 500, 0);
       
        techo.SetPos(-10.0f, 15.0f, 500.0f, 15.0f);

        pared_dcha.SetPos(-10.0f, 0, -10.0f, 15.0f);
 
        pared_izq.SetPos(300.0f, 0, 500.0f, 15.0f);
    
}

Caja::~Caja() {

}

