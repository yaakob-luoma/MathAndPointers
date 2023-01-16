#include <iostream>

#include "../LinearAlgebra.h"

void runExample1()
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
    example1RowReduction[0][0] = 1;
    example1RowReduction[0][1] = 0;
    example1RowReduction[0][2] = 0;
    example1RowReduction[0][3] = 29;

    example1RowReduction[1][0] = 0;
    example1RowReduction[1][1] = 1;
    example1RowReduction[1][2] = 0;
    example1RowReduction[1][3] = 16;

    example1RowReduction[2][0] = 0;
    example1RowReduction[2][1] = 0;
    example1RowReduction[2][2] = 1;
    example1RowReduction[2][3] = 3;

    LinearAlgebra *matrixHelper = LinearAlgebra::getInstance();

    Matrix result = matrixHelper->rowReduction( example1 );

    std::cout << "Input: " << std::endl << example1
              << "\n\nResult: " << std::endl << result
              << "\n\nExpected: " <<std::endl << example1RowReduction;
    bool rowReductionWorking = example1RowReduction == result;
    std::cout << "Row reduction working: " << rowReductionWorking << std::endl;
}


void runExample2()
{
    Matrix example1( 3, 4 );
    example1[0][0] = 0;
    example1[0][1] = 1;
    example1[0][2] = -4;
    example1[0][3] = 8;

    example1[1][0] = 2;
    example1[1][1] = -3;
    example1[1][2] = 2;
    example1[1][3] = 1;

    example1[2][0] = 5;
    example1[2][1] = -8;
    example1[2][2] = 7;
    example1[2][3] = 1;

    Matrix example1RowReduction( 3, 4 );
    example1RowReduction[0][0] = 2;
    example1RowReduction[0][1] = -3;
    example1RowReduction[0][2] = 2;
    example1RowReduction[0][3] = 1;

    example1RowReduction[1][0] = 0;
    example1RowReduction[1][1] = 1;
    example1RowReduction[1][2] = -4;
    example1RowReduction[1][3] = 8;

    example1RowReduction[2][0] = 0;
    example1RowReduction[2][1] = 0;
    example1RowReduction[2][2] = 0;
    example1RowReduction[2][3] = 5/2.0;

    LinearAlgebra *matrixHelper = LinearAlgebra::getInstance();

    Matrix result = matrixHelper->rowReduction( example1 );

    std::cout << "Input: " << std::endl << example1
              << "\n\nResult: " << std::endl << result
              << "\n\nExpected: " <<std::endl << example1RowReduction;
    bool rowReductionWorking = example1RowReduction == result;
    std::cout << "Row reduction working: " << rowReductionWorking << std::endl;
}

int main( )
{
    runExample1();

    runExample2();

    return 0;
}
