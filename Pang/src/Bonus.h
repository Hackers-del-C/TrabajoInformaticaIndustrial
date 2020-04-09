
#include "Vector2D.h"
class Bonus
{
public:
    Bonus();
  // virtual ~Bonus();
    float lado;
    Vector2D posicion;
    Vector2D velocidad;
    Vector2D aceleracion;
    void Dibuja();
    void Mueve(float t);
};