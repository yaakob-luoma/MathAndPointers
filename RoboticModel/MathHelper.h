#ifndef MATHHELPER_H
#define MATHHELPER_H

#include <math.h>

class MathHelper
{
public:
    static const double PI;
    MathHelper();

    double deg2rad( double deg );
    double rad2deg( double rad );

private:
    MathHelper* singleInstance;
};

#endif // MATHHELPER_H
