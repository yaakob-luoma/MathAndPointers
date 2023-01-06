#include "Link.h"

#include <math.h>

Link::Link()
    :
      jointAngleRad
      linkOffset;
      linkLength;
      linkTwistRad;
      type;
      offsetVariable;
      minVariable;
      maxVariable;

      // dynamic
      mass;
      centerOfGravity;
      intertia;
      viscousFriction;
      coulombFriction;
      gearRatio;
      motorInertia;
{

}

Matrix Link::denavitHartenberg()
{
    Matrix dh(4, 4);
    dh[0][0] = cos( jointAngleRad );
    dh[0][1] = -sin( jointAngleRad ) * cos( linkTwistRad );
    dh[0][2] = sin( jointAngleRad ) * sin( linkTwistRad );
    dh[0][3] = linkLength * cos( jointAngleRad );

    dh[1][0] = sin( jointAngleRad );
    dh[1][1] = cos( jointAngleRad ) * cos( linkTwistRad );
    dh[1][2] = -cos( jointAngleRad ) * sin( linkTwistRad );
    dh[1][3] = linkLength * sin( jointAngleRad );

    dh[2][0] = 0.0;
    dh[2][1] = sin( linkTwistRad );
    dh[2][2] = cos( linkTwistRad );
    dh[2][3] = linkOffset;

    dh[3][0] = 0.0;
    dh[3][1] = 0.0;
    dh[3][2] = 0.0;
    dh[3][3] = 1.0;

    endEffector = new Point3D( dh[0][3], dh[1][3], dh[2][3] );
    return dh;
}

void Link::setVariable(double value)
{
    if ( type == REVOLUTE )
    {
        jointAngleRad = value;
    }
    else
    {
        linkOffset = value;
    }
}

double Link::getJointAngleRad() const
{
    return jointAngleRad;
}

void Link::setJointAngleRad(double value)
{
    jointAngleRad = value;
}

double Link::getLinkOffset() const
{
    return linkOffset;
}

void Link::setLinkOffset(double value)
{
    linkOffset = value;
}

double Link::getLinkLength() const
{
    return linkLength;
}

void Link::setLinkLength(double value)
{
    linkLength = value;
}

double Link::getLinkTwistRad() const
{
    return linkTwistRad;
}

void Link::setLinkTwistRad(double value)
{
    linkTwistRad = value;
}

JointType Link::getType() const
{
    return type;
}

void Link::setType(const JointType &value)
{
    type = value;
}

Point3D *Link::getEndEffector() const
{
    return endEffector;
}

Link *Link::getPrevJoint() const
{
    return prevJoint;
}

void Link::setPrevJoint(Link *value)
{
    prevJoint = value;
}

Link *Link::getNextJoint() const
{
    return nextJoint;
}

void Link::setNextJoint(Link *value)
{
    nextJoint = value;
}
