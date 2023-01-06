#include "LinkageArm.h"

double deg2rad( double deg )
{
    return deg * PI  / 180;
}

double rad2deg( double rad )
{
    return rad / 180 * PI;
}

LinkageArm::LinkageArm( bool jointType )
    : length( 0 )
    , twistRad( 0 )
    , offset( 0 )
    , jointAngleRad( 0 )
    , isRevoluteJoint( jointType )
{

}

LinkageArm::LinkageArm( bool isRevoluteJoint, double length, double twistRad, double offset, double jointAngleRad)
    : length( length )
    , twistRad( twistRad )
    , offset( offset )
    , jointAngleRad( jointAngleRad )
    , isRevoluteJoint( isRevoluteJoint )
{

}

LinkageArm::~LinkageArm()
{

}

void LinkageArm::calcualteDenavitHartenberg()
{

//        [ cos( deg2rad( theta ) ), -sin( deg2rad( theta ) )*cos( deg2rad( alpha ) ),  sin( deg2rad( theta ) )*sin( deg2rad( alpha ) ), link.a*cos( deg2rad( theta ) );
//          sin( deg2rad( theta ) ),  cos( deg2rad( theta ) )*cos( deg2rad( alpha ) ), -cos( deg2rad( theta ) )*sin( deg2rad( alpha ) ), length*sin( deg2rad( theta ) );
//                                0,                          sin( deg2rad( alpha ) ),                          cos( deg2rad( alpha ) ),                              d;
//                                0,                                                0,                                                0,                             1];
    denavitHartenberg[0][0] = cos( jointAngleRad );
    denavitHartenberg[0][1] = -sin( jointAngleRad ) * cos( twistRad );
    denavitHartenberg[0][2] = sin( jointAngleRad ) * sin( twistRad );
    denavitHartenberg[0][3] = length * cos( jointAngleRad );

    denavitHartenberg[1][0] = sin( jointAngleRad );
    denavitHartenberg[1][1] = cos( jointAngleRad ) * cos( twistRad );
    denavitHartenberg[1][2] = -cos( jointAngleRad ) * sin( twistRad );
    denavitHartenberg[1][3] = length * sin( jointAngleRad );

    denavitHartenberg[2][0] = 0.0;
    denavitHartenberg[2][1] = sin( twistRad );
    denavitHartenberg[2][2] = cos( twistRad );
    denavitHartenberg[2][3] = offset;

    denavitHartenberg[3][0] = 0.0;
    denavitHartenberg[3][1] = 0.0;
    denavitHartenberg[3][2] = 0.0;
    denavitHartenberg[3][3] = 1.0;
}

Matrix &LinkageArm::getEndEffector() const
{

}


double LinkageArm::getLength() const
{
    return length;
}

double LinkageArm::getTwistRad() const
{
    return twistRad;
}

double LinkageArm::getTwistDegree() const
{
    return rad2deg( twistRad );
}

void LinkageArm::setVariable(double value)
{
    if ( isRevoluteJoint )
    {
        jointAngleRad = deg2rad( value );
    }
    else
    {
        offset = value;
    }
}

double LinkageArm::getOffset() const
{
    return offset;
}

double LinkageArm::getJointAngleRad() const
{
    return jointAngleRad;
}

double LinkageArm::getJointAngleDegree() const
{
    return rad2deg( jointAngleRad );
}

bool LinkageArm::getIsRevoluteJoint() const
{
    return isRevoluteJoint;
}
void LinkageArm::setIsRevoluteJoint( bool isEnabled)
{
    isRevoluteJoint = isEnabled;
}

