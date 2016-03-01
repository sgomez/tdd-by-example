#include <iostream>
#include <libgen.h>
#include <stdlib.h>

#include "Figura2D.h"

using namespace std;

int main(int argc, char* argv[])
{
    if ( 3 != argc ) {
        std::cout 
            << "Uso: " 
            << basename( argv[0] ) 
            << " fichero_de_contorno.txt fichero_de_aproximaxion.txt" 
            << endl
        ;
        exit (1);
    }

    sgomez::Figura2D figura;
    try {
        figura.cargarContorno( argv[1] )
              .cargarAproximacionPoligonal( argv[2] )
        ;
        cout << "El error es de: " << figura.getErrorContorno() << endl;
    } catch (const char *s) {
        std::cout << "Error al cargar los archivos: " << s << endl;
        exit (-1);
    }

}