#include <iostream>

#include "LinearAlgebra.h"

int main( int argc, char** argv )
{
    Matrix example1( 3, 4 );
    example1[0][0] = 1;
    example1[0][1] = -2;
    example1[0][2] = 1;
    example1[0][3] = 0;

    example1[1][0] = 0;
    example1[1][1] = 2;
    example1[1][2] = -8;
    example1[1][3] = 8;

    example1[2][0] = -4;
    example1[2][1] = 5;
    example1[2][2] = 9;
    example1[2][3] = -9;

    Matrix example1RowReduction( 3, 4 );
    example1[0][0] = 1;
    example1[0][1] = 0;
    example1[0][2] = 0;
    example1[0][3] = 29;

    example1[1][0] = 0;
    example1[1][1] = 1;
    example1[1][2] = 0;
    example1[1][3] = 16;

    example1[2][0] = 0;
    example1[2][1] = 0;
    example1[2][2] = 0;
    example1[2][3] = 3;

    LinearAlgebra *matrixHelper;
    matrixHelper->getInstance();

    Matrix result = matrixHelper->rowReduction( example1 );
    std::cout << "Input: " << example1 << "\n\nResult: " << result << "\n\nExpected: " << example1RowReduction;
    bool rowReductionWorking = example1RowReduction == result;
    std::cout << "Row reduction working: " << rowReductionWorking;
}
