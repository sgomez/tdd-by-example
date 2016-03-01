#ifndef PRACTICA1_PUNTO2D_H_
#define PRACTICA1_PUNTO2D_H_

#include <limits>
#include <cmath>

#define EPSILON std::numeric_limits<float>::epsilon()

namespace sgomez 
{
    class Punto2D
    {
    private:
        float x_;
        float y_;

    public:
        Punto2D();
        Punto2D(float x, float y);

        float getX() const;
        Punto2D& setX(float value);
        float getY() const;
        Punto2D& setY(float value);
        bool sonIguales(const Punto2D punto) const;
    };
} // namespace sgomez
#endif // PRACTICA1_PUNTO2D_H_