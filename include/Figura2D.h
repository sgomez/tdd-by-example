#ifndef PRACTICA1_FIGURA2D_H_
#define PRACTICA1_FIGURA2D_H_ 

#include <vector>

#include "Punto2D.h"

using namespace std;

namespace sgomez
{
    class Figura2D
    {
    private:
        vector<Punto2D> contorno_;
        vector<int> aproximacion_;

    public:
        Figura2D& cargarContorno(const char* filename);
        Figura2D& cargarAproximacionPoligonal(const char* filename);
        int getContornoLength() const;
        int getAproximacionPoligonalLength() const;
        double getErrorSegmento(int inicio, int fin);
        double getErrorContorno();
    };
}
#endif // PRACTICA1_FIGURA2D_H_