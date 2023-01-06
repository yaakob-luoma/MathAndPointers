#include "Point.h"

Point::Point()
    : x( 0.0 )
    , y( 0.0 )
{

}

Point::Point(double x, double y)
    : x( x )
    , y( y )
{

}

Point::~Point()
{

}

bool Point::operator==(const Point& p2) const
{
    bool isEqual = false;
    if ( this->x == p2.x && this->y == p2.y )
    {
        isEqual = true;
    }
    return isEqual;
}

bool Point::operator!=(const Point& p2) const
{
    return !(this->operator ==(p2));
}

//ostream &Point::operator<<(ostream& os, Point pt)
//{
//    os << p2.toString();
//}

double Point::getX() const
{
    return x;
}

double Point::getY() const
{
    return y;
}

bool Point::setX(double newX)
{
    bool isChanged = false;
    if ( newX != x )
    {
        x = newX;
        isChanged = true;
    }
    return isChanged;
}

bool Point::setY(double newY)
{
    bool isChanged = false;
    if ( newY != y )
    {
        y = newY;
        isChanged = true;
    }
    return isChanged;
}

//std::string Point::toString() const
//{
//    std::string point;
//    point = "( " + x + ", " + y + " )";
//    return point;
//}

