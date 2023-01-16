#include "Shape.h"

Shape::Shape( const Point3D& newOrigin )
    : origin( newOrigin )
{

}

Shape::~Shape()
{

}

Point3D Shape::getOrigin() const
{
    return origin;
}

void Shape::setOrigin( Point3D newPoint )
{
  origin = newPoint;
}
