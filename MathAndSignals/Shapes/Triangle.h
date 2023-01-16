#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include "Line.h"
class Triangle : public Shape
{
public:
    //static enum trianglesByLength{ UNKOWN, EQUILATERAL, ISOCELES, SCALENE, MAX_NUM };
    //static enum trianglesByAngle{ UNKOWN, RIGHT, OBTUSE, ACUTE, MAX_NUM };

    Triangle( const Point3D& origin = {}
            , const Point3D& newPoint1 = {}
            , const Point3D& newPoint2 = {}
            , const Point3D& newPoint3 = {} );
    ~Triangle();
    std::string toString() const override;

    double getArea();
    bool isRightAngle();

    Point3D getPoint1() const;
    void setPoint1( const Point3D& newPoint );

    Point3D getPoint2() const;
    void setPoint2( const Point3D& newPoint );

    Point3D getPoint3() const;
    void setPoint3( const Point3D& newPoint );

    double getRadAngle1() const;
    double getRadAngle2() const;
    double getRadAngle3() const;

private:
    Point3D point1, point2, point3;
    double radAngle1, radAngle2, radAngle3;
};

#endif
