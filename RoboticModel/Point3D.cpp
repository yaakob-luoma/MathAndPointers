#include "Point3D.h"

Point3D::Point3D(double x, double y, double z)
{
    ::Matrix(3, 1);
    *this[0][0] = x;
    *this[1][0] = y;
    *this[2][0] = z;
}

Point3D::Point3D( const Point3D& point )
{
    *this[0][0] = point[0][0];
    *this[1][0] = point[1][0];
    *this[2][0] = point[2][0];
}

Point3D::~Point3D()
{

}

Point3D& Point3D::operator=(const Point3D& point )
{
    *this[0][0] = point[0][0];
    *this[1][0] = point[1][0];
    *this[2][0] = point[2][0];
    return *this;
}

double Point3D::getX() const
{
   return *this[0][0];
}
void Point3D::setX( double value )
{
    *this[0][0] = value;
}

double Point3D::getY() const
{
    return *this[1][0];
}
void Point3D::setY( double value )
{
    *this[1][0] = value;
}

double Point3D::getZ() const
{
    return *this[2][0];
}
void Point3D::setZ(double value)
{
    *this[2][0] = value;
}

std::string Point3D::toString() const
{
    std::string returnValue;

    return returnValue;
}
