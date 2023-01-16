#include "Line.h"

Line::Line( const Point3D& newStartPoint
          , const Point3D& newEndPoint )
    : startPoint( newStartPoint )
    , endPoint( newEndPoint )
{

}

Line::~Line()
{

}

Line& Line::operator=(const Line& line )
{
    startPoint = line.getStartPoint();
    endPoint = line.getEndPoint();
    return *this;
}

std::string Line::toString() const
{

}

double Line::getMagnitude()
{
  double deltaX = (startPoint.getX() - endPoint.getX() );
  double deltaY = ( startPoint.getY() - endPoint.getY() );
  double deltaZ = ( startPoint.getZ() - endPoint.getZ() );

  return sqrt( deltaX * deltaX
             + deltaY * deltaY
             + deltaZ * deltaZ );
}

Point3D Line::getDirection()
{
    double deltaX = (startPoint.getX() - endPoint.getX() );
    double deltaY = ( startPoint.getY() - endPoint.getY() );
    double deltaZ = ( startPoint.getZ() - endPoint.getZ() );

    double magnitude = getMagnitude();

    Point3D direction( deltaX / magnitude
                     , deltaY / magnitude
                     , deltaX / magnitude );

    return direction;
}

Point3D Line::getStartPoint() const
{
    return startPoint;
}

void Line::setStartPoint( Point3D newPoint )
{
  startPoint = newPoint;
}

Point3D Line::getEndPoint() const
{
    return endPoint;
}

void Line::setEndPoint( Point3D newPoint )
{
    endPoint = newPoint;
}
