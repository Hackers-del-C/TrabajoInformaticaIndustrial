#include "Caja.h"
#include "glut.h"

void Caja::Dibuja()
{ //Evidentemente no dibujamos la caja pero nos sirve para delimitar  el moviiento del hombre
    //suelo.Dibuja();
    //techo.Dibuja();
   // pared_izq.Dibuja();
   // pared_dcha.Dibuja();
}

Caja::Caja(){

       // suelo.SetColor(0, 100, 0);
        suelo.SetPos(-10.0f, 0, 100.0f, 0); //Para cambiar largo del nivel cambiar el 100
        //techo.SetColor(0, 100, 0);
        techo.SetPos(-10.0f, 15.0f, 100.0f, 15.0f);//Para cambiar largo del nivel cambiar el 100

        //pared_dcha.SetColor(0, 150, 0);
        pared_dcha.SetPos(-10.0f, 0, -10.0f, 15.0f);
        //pared_izq.SetColor(0, 150, 0);
        pared_izq.SetPos(100.0f, 0, 100.0f, 15.0f);//Para cambiar largo del nivel cambiar los 100
    
}

Caja::~Caja() {

}

