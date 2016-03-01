#include "gtest/gtest.h"
#include "Punto2D.h"

using namespace sgomez;

TEST(Punto2DTest, NuevoPunto)
{
	Punto2D punto = Punto2D( 1.0, 2.0 );
	ASSERT_FLOAT_EQ( 1.0, punto.getX() );
	ASSERT_FLOAT_EQ( 2.0, punto.getY() );
}

TEST(Punto2DTest, ConfigurarPunto)
{
	Punto2D punto;
	punto.setX( 1.0 ).setY( 2.0 );
	ASSERT_FLOAT_EQ( 1.0, punto.getX() );
	ASSERT_FLOAT_EQ( 2.0, punto.getY() );
}

TEST(Punto2DTest, SonIguales)
{
	Punto2D iguales = Punto2D( 1.0, 2.0 );
	ASSERT_TRUE( iguales.sonIguales( iguales ) );
}
