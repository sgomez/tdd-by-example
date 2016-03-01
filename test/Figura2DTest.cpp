#include "gtest/gtest.h"
#include "Figura2D.h"

using namespace sgomez;
using namespace testing;

TEST(Figura2DTest, CargarContorno)
{
    Figura2D figura;
    ASSERT_NO_THROW( figura.cargarContorno( "data/test-contorno-01.txt" ) );
    ASSERT_EQ( 6, figura.getContornoLength() );
}

TEST(Figura2DTest, CargarAproximacionPoligonal)
{
    Figura2D figura;
    ASSERT_NO_THROW( figura.cargarAproximacionPoligonal( "data/test-aproximacion-01.txt" ) );
    ASSERT_EQ( 5, figura.getAproximacionPoligonalLength() );
}

TEST(Figura2DTest, CalcularErrorEntreDosPuntos)
{
    Figura2D figura;
    figura.cargarContorno( "data/test-contorno-01.txt" );
    ASSERT_FLOAT_EQ( 0.5, figura.getErrorSegmento( 2, 4 ) );
    ASSERT_FLOAT_EQ( 2, figura.getErrorSegmento( 1, 4 ) );
    ASSERT_FLOAT_EQ( 2, figura.getErrorSegmento( 4, 1 ) );
}

TEST(Figura2DTest, CalculaErrorContorno)
{
    Figura2D figura;
    figura.cargarContorno( "data/test-contorno-01.txt" )
          .cargarAproximacionPoligonal( "data/test-aproximacion-01.txt" )
    ;
    ASSERT_FLOAT_EQ( 1, figura.getErrorContorno() );
}