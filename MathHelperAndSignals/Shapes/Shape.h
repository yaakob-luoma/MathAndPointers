#ifndef SHAPE_H
#define SHAPE_H

#include <string.h>

#include "Point3D.h"

class Shape
{
public:
    Shape( const Point3D& newOrigin = {} );
    ~Shape();

    Point3D getOrigin() const;
    void setOrigin( Point3D newPoint );

    virtual std::string toString() const = 0;

protected:
    Point3D origin;
};

#endif //SHAPE_H
