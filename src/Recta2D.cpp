#include "Recta2D.h"

#include <math.h>
#include <stdlib.h>

#include "Punto2D.h"

namespace sgomez {
    Recta2D::Recta2D(): a_(0), b_(0), c_(0) {};

    Recta2D::Recta2D(float a, float b, float c): a_(a), b_(b), c_(c) {};

    Recta2D::Recta2D(const Punto2D point1, const Punto2D point2)
    {
        if (true == point1.sonIguales(point2)) {
            throw "Los puntos no pueden ser iguales.";
        }
        a_ = point2.getY() - point1.getY();
        b_ = point1.getX() - point2.getX();
        c_ = - b_ * point1.getY() - a_ * point1.getX();
    }

    float Recta2D::getA() const
    {
        return a_;
    }

    Recta2D& Recta2D::setA(float value)
    {
        a_ = value;

        return *this;
    }

    float Recta2D::getB() const
    {
        return b_;
    }

    Recta2D& Recta2D::setB(float value)
    {
        b_ = value;

        return *this;
    }

    float Recta2D::getC() const
    {
        return c_;
    }

    Recta2D& Recta2D::setC(float value)
    {
        c_ = value;

        return *this;
    }

    float Recta2D::distancia(Punto2D point)
    {
        return ( 
            fabs ( a_ * point.getX() + b_ * point.getY() + c_ )
            / sqrt ( a_ * a_ + b_ * b_ )
        );
    }
} // namespace sgomez