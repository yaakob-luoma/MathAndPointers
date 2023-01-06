#include "MathHelper.h"

const double MathHelper::PI = 4 * atan( 1 );


MathHelper::MathHelper()
{

}

double MathHelper::deg2rad(double deg)
{
    return deg * PI / 180.0;
}

double MathHelper::rad2deg(double rad)
{
    return rad / 180.0 * PI;
}
