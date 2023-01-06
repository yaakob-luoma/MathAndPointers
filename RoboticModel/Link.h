#ifndef LINK_H
#define LINK_H

#include "Point3D.h"
#include "Limit.h"



class Link
{

public:
    enum JointType
    {
        REVOLUTE,
        PRISMATIC
    };

    Link ( double jointAngleRad = 0
         , double linkOffset = 0
         , double linkLength = 0
         , double linkTwistRad = 0
         , JointType type = JointType::REVOLUTE
         , double offsetVariable = 0
         , Limit< double > limit = Limit<double>()
         , double mass = 1
         , Point3D centerOfGravity = Point3D()
         , Matrix intertia = Matrix(3, 3)
         , double viscousFriction = 0
         , double coulombFriction = 0
         , double gearRatio = 1
         , double motorInertia = 0 );

    Link( const Link& link );
    ~Link();
    Link& operator=(const Link& point );

    bool operator==( const Link& rhs );
    bool operator!=( const Link& rhs );

    Matrix denavitHartenberg();
    void setVariable( double value );
    double getVariable() const;

    double getJointAngleRad() const;
    void setJointAngleRad(double value);

    double getLinkOffset() const;
    void setLinkOffset(double value);

    double getLinkLength() const;
    void setLinkLength(double value);

    double getLinkTwistRad() const;
    void setLinkTwistRad(double value);

    JointType getType() const;
    void setType(const JointType &value);

    std::string toString() const;
    void display();
private:
    // kinematic
    double jointAngleRad;
    double linkOffset;
    double linkLength;
    double linkTwistRad;
    JointType type; 
    double offsetVariable;
    Limit< double > limit;

    // dynamic
    double mass;
    Point3D centerOfGravity;
    Matrix intertia;
    double viscousFriction;
    double coulombFriction;
    double gearRatio;
    double motorInertia;
};

#endif // LINK_H
