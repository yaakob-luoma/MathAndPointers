#include "Point2D.h"

Point2D::Point2D(double x, double y)
{
    ::Matrix( 2, 1);
    *this[0][0] = x;
    *this[1][0] = y;
}

Point2D::~Point2D()
{

}

Point2D &Point2D::operator=(const Point2D &point)
{
    *this[0][0] = point[0][0];
    *this[1][0] = point[1][0];
    return *this;
}

bool Point2D::operator==( const Point2D& rhs )
{
    return *this[0][0] == rhs[0][0]
        && *this[1][0] == rhs[1][0]
         ? true : false;
}

double Point2D::getX() const
{
    return *this[0][0];
}

void Point2D::setX(double value)
{
    *this[0][0] = value;
}

double Point2D::getY() const
{
    return *this[1][0];
}

void Point2D::setY(double value)
{
    *this[1][0] = value;
}

std::string Point2D::toString() const
{
    std::string returnValue;

    return returnValue;
}
