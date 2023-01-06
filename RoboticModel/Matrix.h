#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <stdexcept> // for std::runtime_error
#include <string> // used in exception

/*!
 * \brief The matrixException class
 * a helper class to bundle a message with any thrown exceptions. To use,
 * simply 'throw matrixException( "descriptive message" )'
 * This will throw the exception object by value. Recommendation is to catch by reference to prevent slicing.
 */
class matrixException:public std::runtime_error
{
public:
    matrixException( std::string message )
        :std::runtime_error( ( std::string( "Matrix Exception: ") + message).c_str() )
    {}
};

class rowVector
{
public:
    rowVector( unsigned int size )
    {
        cols = size;
        the_row = new double[ cols ];
        for( unsigned int j = 0; j < cols; j++ )
        {
            the_row[ j ] = 0;
        }
    }

    void setValue( unsigned int position, double value )
    {
        the_row[ position ] = value;
    }

    unsigned int getSize()
    {
        return cols;
    }

    double operator[]( unsigned int col ) const
    {
        if( col >= cols )
        {
            throw matrixException("operator[], index out of range");
        }
        return the_row[ col ];
    }

private:
    unsigned int cols;
    double* the_row;
};

class Matrix
{
public:
    /*!
     * \brief Matrix, create 1x1 default Matrix
     */
    Matrix();

    /*!
     * \brief Matrix,
     * \param rows
     * \param cols
     */
    Matrix(unsigned int numRows, unsigned int numCols );

    Matrix( const Matrix& copy );

    Matrix& operator=( const Matrix& rhs );

    ~Matrix();



    double* operator[]( unsigned int row );

    double* operator[]( unsigned int row) const;

    std::ostream& out( std::ostream& os ) const;

    Matrix operator+( const Matrix& rhs ) const;

    /*!
     * \brief operator *, support someMatrixObject * scaleValue but not scaleValue * someMatrixObject
     * \param rhs
     * \return
     */
    Matrix operator*( const Matrix& rhs ) const;

    Matrix operator*( const double scale ) const;

    Matrix operator!() const;

    Matrix identityMatrix( const Matrix& rhs ) const;

    double determinant( unsigned int ) const;

    Matrix cofactor( unsigned int ) const;

    Matrix transpose( unsigned int ) const;

    void clear();

private:

    double** the_matrix;
    unsigned int rows;
    unsigned int cols;

    void memoryInit( unsigned int numRows, unsigned int numCols );
    void deleteMemory();
    Matrix inverse2x2( const Matrix& rhs) const;
};

/*!
 * \brief operator << overloaded global, the method generates ouput compatible with an ostream which is commonly used with console (cout) and files
 * Format is as follows:
 * [[ r0c0, r0c1, r0c2 ]
 *  [ r1c0, r1c1, r1c2 ]
 *  [ r2c0, r2c1, r2c2 ]]
 * \param os
 * \param rhs
 * \return
 */
std::ostream& operator<<( std::ostream& os, const Matrix& rhs );

/*!
 * \brief operator *, Support scaleValue * someMatrixObject but not someMatrixObject * scaleValue
 * \param scale
 * \param rhs
 * \return
 */
Matrix operator*( const double scale, const Matrix& rhs );


#endif // MATRIX_H
