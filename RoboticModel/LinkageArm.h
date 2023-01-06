#ifndef LINKAGEARM_H
#define LINKAGEARM_H

#include <math.h>

#include "Matrix.h"


const double PI = 4 * atan( 1 ); // exactly 3.14159265....

double deg2rad( double deg );

double rad2deg( double rad );

/*!
 * \brief The LinkageArm class assumes that it is a single degree of freedom
 *  to create complex joints connect my LinkageArm together with length zero.
 * For example, a ball joint would be created with 3 LinkageArm that are
 * revolute with length zero between them. This is base on Robot Modeling and Controls by Sprong
 */
class LinkageArm
{
public:
    LinkageArm( bool jointType = false );
    LinkageArm( bool, double, double, double, double);
    ~LinkageArm();

    double getLength() const;

    double getTwistRad() const;
    double getTwistDegree() const;

    double getOffset() const;

    void setVariable( double );

    double getJointAngleRad() const;
    double getJointAngleDegree() const;

    bool getIsRevoluteJoint() const;
    void setIsRevoluteJoint( bool );

    /*!
     * \brief calcualteDenavitHartenberg
     * Forward kinematics to find endEffector based on joint variables
     */
    void calcualteDenavitHartenberg();
    Matrix& getEndEffector() const;

private:
//#Forward kinematics: Denavit-Hartenberg

//#homogeneous tranformation of Rotation Z, Translation Z, Tranxalation X, Rotation X
//# link lenght - a, fixed
//# link twist - aphla, fixed
//# link offset - d, variable
//# link jointAngle - theta, variable
    double length; //fixed
    double twistRad; //fixed
    double offset; //variable
    double jointAngleRad; //variable
    bool isRevoluteJoint;
    //bool isPrismaticJoint;
    Matrix endEffector;
    Matrix denavitHartenberg;
};

#endif // LINKAGEARM_H
