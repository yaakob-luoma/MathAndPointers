#include <cmath>

/**
 * @brief pi, return value of pi
 * proof: sin( pi/4) = cos( pi/4) = sqrt( 2 ) / 2, so tan( pi / 4) = 1
 *   then: pi = 4 * atan( 1 )
 * @return pi as 4 * atan( 1 ), which allows for truncation if a differnt size of pi is neeed
 * physical simulations need 6+ digits after the decimal
 */
double pi()
{
    return 4 * atan( 1 );
}

/**
 * @brief deg2rad, convert degrees to radians.
 *   180 deg = pi radians, 1 radian = 180 deg / pi
 * @param deg
 * @return rad
 */
double deg2rad( double deg )
{
  return deg *  pi() / 180;
}

/**
 * @brief rad2deg convert radians to degrees
 * @param rad
 * @return
 */
double rad2deg( double rad )
{
    return rad / 180 * pi();
}

namespace Triangle
{
    namespace rightAngle
    {
        // soh: Sin( theta ) = o / h
        double sohGetAngle( double o, double h )
        {
          return asin( o / h );
        }

        double sohGetH( double o, double theta )
        {
            // TODO: check that sin( deg2rad( theta ) ) != 0
            return o / sin( deg2rad( theta ) );
        }

        double sohGetO( double h, double theta )
        {
            return h * sin( deg2rad( theta ) );
        }

        // cah: cos( theta ) = a / h
        double cahGetAngle( double a, double h )
        {
          return acos( a / h );
        }

        double cahGetH( double a, double theta )
        {
            // TODO: check that cos( deg2rad( theta ) ) != 0
            return a / cos( deg2rad( theta ) );
        }

        double cahGetA( double h, double theta )
        {
            return h * cos( deg2rad( theta ) );
        }

        // toa: tan( theta ) = o / a
        double toaGetAngle( double o, double a )
        {
          return atan( o / a );
        }

        double toaGetA( double o, double theta )
        {
            // TODO: check that tan( deg2rad( theta ) ) != 0
            return o / tan( deg2rad( theta ) );
        }

        double toaGetO( double a, double theta )
        {
            return a * tan( deg2rad( theta ) );
        }
        /**
         * @brief pythagorean, only works for right angle triangle
         * @param a
         * @param b
         * @return a^2 + b^2
         */
        double pythagoreanC( double a, double b )
        {
            return sqrt( a*a + b*b );
        }

        /**
         * @brief pythagoreanA, only works for right angle triangle
         * @param c
         * @param b
         * @return
         */
        int pythagoreanA( int c, int b )
        {
            return sqrt( c*c - b*b );
        }
    }

    double areaTriangle( double a, double b )
    {
        return  ( a * b ) / 2.0;
    }

    /**
     * @brief isRightAngleTriangleAngles
     * @param alpha
     * @param beta
     * @param gamma
     * @return
     */
    bool isRightAngleTriangleAngles( double alpha, double beta, double gamma )
    {
        // cos( A ) * cos( B ) * cos( C ) = 0
        //double result = cos( deg2rad( alpha ) ) * cos( deg2rad( beta ) ) * cos( deg2rad( gamma ) );
        //this will cause issues as double pre
        if( alpha == 90.0 || beta == beta || gamma == 90 )
        {
            return true;
        }
        return false;
    }

    /**
     * @brief isRightAngleTriangleSides, checks
     * @param a
     * @param b
     * @param c
     * @return
     */
    bool isRightAngleTriangleSides( double a, double b, double c )
    {
        bool isResult = false;

        if ( c == rightAngle::pythagoreanC( a, b )
             || b == rightAngle::pythagoreanC( a, c )
             || a == rightAngle::pythagoreanC( b, c )
           )
        {
            isResult = true;
        }

        return isResult;
    }





    /**
     * @brief lawOfCosine c^2 = a^2 + b^2 - 2*a*b*cos(gamma)
     * @param a
     * @param b
     * @param gamma is the angle between the edge b and a in degrees
     * @return c^2 = a^2 + b^2 - 2*a*b*cos(gamma)
     */
    double lawOfCosineC( double a, double b, double gamma )
    {
        return a*a + b*b - 2*a*b*cos( deg2rad( gamma ) );
    }
}

namespace Circle
{
  double radius2diameter( double radius )
  {
      return radius * 2.0;
  }

  double diameter2radius( double diameter )
  {
      return diameter / 2.0;
  }

  double circumference( double radius )
  {
      return 2 * pi() * radius;
  }

  double area( double radius )
  {
      return pi() * radius * radius;
  }

  /**
   * @brief equationOfCircle
   * @param a, center x-axis
   * @param b, center y-axis
   * @param radius
   */
  void equationOfCircle( double a, double b, double radius )
  {
      //circle edge
      //double x, y;
      //(x - a)*(x-a) + (y-b)*(y-b) = r*r
  }

  /**
   * @brief parametricFormXAxis
   * @param a
   * @param radius
   * @param t, is a parametric variable in the range of 0 to 2*pi()
   * @return
   */
  double parametricFormXAxis( double a, double radius, double t )
  {
      //alternative form
      //return a + radius * cos( t );
      return a + radius * ( (1 - t * t ) / ( 1 + t * t ) );
  }

  /**
   * @brief parametricFormYAxis
   * @param b
   * @param radius
   * @param t, is a parametric variable in the range of 0 to 2*pi()
   * @return
   */
  double parametricFormYAxis( double b, double radius, double t )
  {
      //alternative form
      //return b + radius * sin( t );
      return b + radius * ( ( 2 * t )/( 1 + t * t ) );
  }
}

/*
 * polar and cartesian coordinates
 * x = r * cos( gamma )
 * y = r * sin( gamma )
 * r = sqrt( x*x + y*y )
 * gamma = atan2( y, x )
 *
 * complex number
 * z = x + iy
 * z = r* (cos( gamma ) + i * sin( gamma ) )
 * z = r*pow( e,  i * gamma )
 * angle notation
 * z = r < gamma
 */
