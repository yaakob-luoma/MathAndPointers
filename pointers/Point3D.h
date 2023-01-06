#ifndef POINT3D_H
#define POINT3D_H

#include "Matrix.h"

class Point3D : public Matrix
{
public:
    Point3D(double x = 0.0, double y = 0.0, double z = 0.0);
    Point3D( const Point3D& point );
    ~Point3D();
    Point3D& operator=(const Point3D& point );

    double getX() const;
    void setX( double value );

    double getY() const;
    void setY( double value );

    double getZ() const;
    void setZ(double value);

    std::string toString() const;

};

#endif // POINT3D_H
