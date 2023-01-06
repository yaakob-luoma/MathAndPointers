#ifndef POINT_H
#define POINT_H

#include <string>
//#include <ostream>

/*!
 * \brief The Point class
 * \todo Change int to template
 */
class Point
{
public:
    Point();
    Point( double x, double y );
    ~Point();

    bool operator==( const Point& p2 )const;
    bool operator!=( const Point& p2 )const;
    //ostream& operator<<( ostream& os, Point pt );

    double getX() const;
    double getY() const;
    bool setX( double newX );
    bool setY( double newY );
//    std::string toString() const;
private:
    double x;
    double y;
};

#endif // POINT_H
