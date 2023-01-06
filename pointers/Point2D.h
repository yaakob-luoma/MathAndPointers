#ifndef POINT2D_H
#define POINT2D_H

#include <string>

#include "Matrix.h"

class Point2D : public Matrix
{
public:
    Point2D(double x = 0.0, double y = 0.0);
    Point2D( const Point2D& point );
    ~Point2D();
    Point2D& operator=(const Point2D& point );

    bool operator==( const Point2D& rhs );

    double getX() const;
    void setX( double value );

    double getY() const;
    void setY( double value );

    std::string toString() const;

};

#endif // POINT2D_H
