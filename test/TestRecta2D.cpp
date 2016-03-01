#include "gtest/gtest.h"
#include "Recta2D.h"

using namespace sgomez;

TEST(Recta2DTest, NuevaRectaPorCoeficientes)
{
    Recta2D recta = Recta2D( 1.0, 2.0, 3.0 );
    ASSERT_FLOAT_EQ( 1.0, recta.getA() );
    ASSERT_FLOAT_EQ( 2.0, recta.getB() );
    ASSERT_FLOAT_EQ( 3.0, recta.getC() );
}

TEST(Recta2DTest, NuevaRectaPorPuntos)
{
    Punto2D point1 = Punto2D( 1, 3 );
    Punto2D point2 = Punto2D( 2, -5 );
    Recta2D recta = Recta2D( point1, point2 );
    ASSERT_FLOAT_EQ( -8.0, recta.getA() );
    ASSERT_FLOAT_EQ( -1.0, recta.getB() );
    ASSERT_FLOAT_EQ( 11.0, recta.getC() );
}

TEST(Recta2DTest, NuevaRectaPorPuntosIguales)
{
    Punto2D point = Punto2D( 1, 3 );
    ASSERT_ANY_THROW( Recta2D( point, point ) );
}

TEST(Recta2DTest, ModificarValoresRecta)
{
    Recta2D recta = Recta2D();
    recta.setA( 1.0 ).setB( 2.0 ).setC( 3.0 );
    ASSERT_FLOAT_EQ( 1.0, recta.getA() );
    ASSERT_FLOAT_EQ( 2.0, recta.getB() );
    ASSERT_FLOAT_EQ( 3.0, recta.getC() );
}

TEST(Recta2DTest, DistanciaDePuntoARecta)
{
    Recta2D recta = Recta2D( 3, 4, 0);
    Punto2D point = Punto2D( 2, -1 );
    ASSERT_FLOAT_EQ( 0.4, recta.distancia( point ) );
    point = Punto2D( 2.5, -1 );
    ASSERT_FLOAT_EQ( 0.7, recta.distancia( point ) );
}