#include "Triangle.h"

Triangle::Triangle( const Point3D& origin
                  , const Point3D& newPoint1
                  , const Point3D& newPoint2
                  , const Point3D& newPoint3 )
    : point1( newPoint1 )
    , point2( newPoint2 )
    , point3( newPoint3 )
{
    Shape( origin );
}

Triangle::~Triangle()
{

}

std::string Triangle::toString() const
{

}

double Triangle::getArea()
{
  Point3D ab( point2 - point1 );
  Point3D ac( point3 - point1 );

  return (ab * ac).magnitude() / ab.magnitude();

}

bool Triangle::isRightAngle()
{

}

Point3D Triangle::getPoint1() const
{

}

void Triangle::setPoint1( const Point3D& newPoint )
{

}

Point3D Triangle::getPoint2() const
{

}

void Triangle::setPoint2( const Point3D& newPoint )
{

}

Point3D Triangle::getPoint3() const
{

}

void Triangle::setPoint3( const Point3D& newPoint )
{

}

double Triangle::getRadAngle1() const
{

}

double Triangle::getRadAngle2() const
{

}

double Triangle::getRadAngle3() const
{

}
