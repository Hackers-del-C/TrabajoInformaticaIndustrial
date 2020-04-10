#include "Vector2D.h"
class Hombre
{
public:
    Hombre();
    //virtual ~Hombre();
    float altura;
    Vector2D posicion;
    Vector2D velocidad;
    Vector2D aceleracion;
    void Dibuja();
    void Mueve(float t);
};