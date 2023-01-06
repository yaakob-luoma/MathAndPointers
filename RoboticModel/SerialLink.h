#ifndef SERIALLINK_H
#define SERIALLINK_H

#include "Node.h"
#include "Matrix.h"
#include "Link.h"

class SerialLink
{
public:
    SerialLink();
    SerialLink( const SerialLink& arm );
    ~SerialLink();
    SerialLink& operator=( const SerialLink& arm);

    bool add( Link link );
    bool insert( Link link, unsigned int index );
    bool remove( Link link );
    void clear();
    unsigned int size();

    void forwardKinematic( double variablePositions[] );
    void inverseKinematic(Point3D desiredEndEffector, double variableGuess[] );

    Point3D linkEnd( unsigned int linkNum );
    double linkVariable( unsigned int linkNum );

    Point3D* allLinkEnds();
    double* allLinkVariables();

private:
    Node<Link>* head;
    Node<Link>* tail;
    unsigned int numberOfLinks;


    const double DEFAULT_REV_MIN_DEG = 0.0;
    const double DEFAULT_REV_MAX_DEG = 360.0;
    const double DEFAULT_PRI_MIN = 0.0;
    const double DEFUALT_PRI_MAX = 100.0;
    const double INCREMENT = 0.001;
};

#endif // ARMKINEMATIC_H
