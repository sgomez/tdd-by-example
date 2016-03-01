#ifndef PRACTICA1_RECTA2D_H_
#define PRACTICA1_RECTA2D_H_ 

#include "Punto2D.h"

namespace sgomez
{
    class Recta2D
    {
    private:
        float a_;
        float b_;
        float c_;

    public:
        Recta2D();
        Recta2D(float a, float b, float c);
        Recta2D(const Punto2D point1, const Punto2D point2);

        float getA() const;
        Recta2D& setA(float value);
        float getB() const;
        Recta2D& setB(float value);
        float getC() const;
        Recta2D& setC(float value);
        float distancia(Punto2D p);
    };
} // namespace sgomez

#endif // PRACTICA1_RECTA2D_H_