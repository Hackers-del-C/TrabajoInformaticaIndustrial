#include "Vector2D.h"

class Disparo
{
public:
    Disparo();
  //  virtual ~Disparo();
    float radio;
    Vector2D posicion;
    Vector2D velocidad;
    Vector2D aceleracion;
    Vector2D origen;
    void Dibuja();
    void Mueve(float r);
};