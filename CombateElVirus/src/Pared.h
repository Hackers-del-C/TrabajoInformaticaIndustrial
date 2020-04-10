#include "Vector2D.h"
class Pared
{
private:
  
   
    unsigned char rojo;
    unsigned char verde;
    unsigned char azul;
   

public:
    Vector2D limite1;
    Vector2D limite2;
    void Dibuja();
    Pared();
    virtual ~Pared();
    void SetColor(unsigned char r, unsigned char v, unsigned char a);
};
