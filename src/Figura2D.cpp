#include "Figura2D.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

#include "Punto2D.h"
#include "Recta2D.h"

using namespace std;

namespace sgomez 
{
    Figura2D& Figura2D::cargarContorno(const char* filename)
    {
        ifstream fichero;

        fichero.open( filename );
        if ( fichero.fail() ) {
            throw "No se pudo abrir el fichero de contorno";
        }

        int x, y;
        Punto2D punto;

        while( ! fichero.eof() ) {
            while(fichero >> x >> y) {
                contorno_.push_back( punto.setX(x).setY(y) );
            }
        }

        fichero.close();

        return *this;
    }

    Figura2D& Figura2D::cargarAproximacionPoligonal(const char* filename)
    {
        ifstream fichero;

        fichero.open( filename );
        if ( fichero.fail() ) {
            throw "No se pudo abrir el fichero de aproximacion";
        }

        int x;

        while( fichero >> x ) {
            aproximacion_.push_back( x );
        }

        fichero.close();

        return *this;
    }

    int Figura2D::getContornoLength() const
    {
        return contorno_.size();
    }

    int Figura2D::getAproximacionPoligonalLength() const
    {
        return aproximacion_.size();
    }

    double Figura2D::getErrorSegmento(int inicio, int fin)
    {
        double error = 0.0;

        Recta2D recta = Recta2D( contorno_[inicio], contorno_[fin] );

        if (fin < inicio) {

            for (int i = inicio + 1; i < getContornoLength() ; i++) {
                error += pow ( recta.distancia( contorno_[i] ), 2 );
            }

            for (int i = 0 ; i < fin; i++) {
                error += pow ( recta.distancia( contorno_[i] ), 2 );
            }


        } else {

            for (int i = inicio + 1; i < fin; i++) {
                error += pow ( recta.distancia( contorno_[i] ), 2 );
            }
        }

        return error;
    }

    double Figura2D::getErrorContorno()
    {
        double error = 0.0;

        for ( int i = 0 ; i < getAproximacionPoligonalLength() - 1; i++) {
            error += getErrorSegmento( aproximacion_[i], aproximacion_[i+1] );
        }

        return error;
    }
}











