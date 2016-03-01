#include "Punto2D.h"

namespace sgomez {
    Punto2D::Punto2D(): x_(0), y_(0) {};

    Punto2D::Punto2D(float x, float y): x_(x), y_(y) {};


    bool Punto2D::sonIguales(const Punto2D punto) const
    {
        return fabs( x_ - punto.getX() ) < EPSILON && fabs( y_ - punto.getY() ) < EPSILON;
    }

    float Punto2D::getX() const
    {
        return x_;
    }

    Punto2D& Punto2D::setX(float value)
    {
        x_ = value;

        return *this;
    }

    float Punto2D::getY() const
    {
        return y_;
    }

    Punto2D& Punto2D::setY(float value)
    {
        y_ = value;
        
        return *this;
    }
} // namespace sgomez