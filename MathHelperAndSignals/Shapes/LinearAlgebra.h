#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#include <mutex>
#include <string>

#include "Matrix.h"

/**
 * @brief The LinearAlgebra class
 * Math helper for Matrix class and a singleton class
 */
class LinearAlgebra
{
public:
    LinearAlgebra( LinearAlgebra& other ) = delete;
    void operator=( const LinearAlgebra& other ) = delete;

    static LinearAlgebra* getInstance();

    Matrix identityMatrix( const Matrix& rhs ) const;

    double determinant( const Matrix& matrix, unsigned int ) const;

    Matrix cofactor( const Matrix& matrix, unsigned int ) const;

    Matrix transpose( const Matrix& matrix, unsigned int ) const;

    Matrix inverse( const Matrix& matrix ) const;

    Matrix inverse2x2( const Matrix& matrix ) const;

    Matrix solveAugmentedMatrix( const Matrix& matrix) const;

protected:
    LinearAlgebra();
    ~LinearAlgebra(){}


private:
    static LinearAlgebra *instance_ptr;
    static std::mutex mutex;

    bool isAugmentedMatrixContradiction( const Matrix& matrix ) const;
    unsigned int findFirstNoneZero( const Matrix& matrix, unsigned int row ) const;
    Matrix solveAugmentedMatrixReplacement( const Matrix& matrix, unsigned int row1, unsigned int row2 ) const;
    Matrix solveAugmentedMatrixInterchange( const Matrix& matrix, unsigned int row1, unsigned int row2 ) const;
    Matrix solveAugmentedMatrixScaling( const Matrix& matrix, unsigned int row ) const;
};

#endif
