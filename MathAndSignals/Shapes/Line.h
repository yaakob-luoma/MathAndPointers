#ifndef LINE_H
#define LINE_H

#include <cmath>
#include <string>

#include "Point3D.h"


class Line
{
public:
    Line( const Point3D& newStartPoint, const Point3D& newEndPoint );
    ~Line();
    Line& operator=(const Line& line );

    std::string toString() const;

    double getMagnitude();
    Point3D getDirection();

    Point3D getStartPoint() const;
    void setStartPoint( Point3D newPoint);

    Point3D getEndPoint() const;
    void setEndPoint( Point3D newPoint );

private:
    Point3D startPoint, endPoint;
};

#endif //LINE_H
