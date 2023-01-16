#include "Matrix.h"

#include <math.h>
#include <string>

double* Matrix::operator[]( unsigned int row )
{
    if( row >= rows )
    {
        throw matrixException("operator[] index out of range" );
    }
    return the_matrix[row];
}

double* Matrix::operator[]( unsigned int row) const
{
    if( row >= rows )
    {
        throw matrixException( "operator[] index out of range" );
    }
    return the_matrix[row];
}

/**
 * @brief Matrix::clear, sets matrix to have all 0.0 in it's cells
 */
void Matrix::clear()
{
    for( unsigned int i = 0; i < rows; i++ )
    {
        for( unsigned int j = 0; j < cols; j++ )
        {
            the_matrix[i][j] = 0.0;
        }
    }
}

void Matrix::memoryInit(unsigned int numRows, unsigned int numCols )
{
    the_matrix = new double*[ numRows ];
    for( unsigned int i = 0; i < numRows; i++ )
    {
        the_matrix[ i ] = new double[ numCols ];
    }
    clear();
}

/*!
* \brief Matrix,
* \param rows
* \param cols
*/
Matrix::Matrix(unsigned int numRows, unsigned int numCols )
{
    if( numRows != 0 )
    {
        this->rows = numRows;
    }
    else
    {
        this->rows = 1;
    }

    if( numCols != 0 )
    {
        this->cols = numCols;
    }
    else
    {
        this->cols = 1;
    }

    memoryInit( this->rows, this->cols );
}

Matrix::Matrix( const Matrix& copy )
    : rows( copy.rows )
    , cols( copy.cols )
{
    memoryInit( rows, cols );
    (*this) = copy;
}

void Matrix::deleteMemory()
{
    for( unsigned int i = 0; i < rows; i++ )
    {
        delete[] the_matrix[i];
    }
    delete[] the_matrix;
}

Matrix& Matrix::operator=( const Matrix& rhs )
{
    if( &rhs != this )
    {
        if( (rhs.rows != rows ) && ( rhs.cols != cols ) )
        {
            deleteMemory();
            rows = rhs.rows;
            cols = rhs.cols;
            memoryInit( rows, cols );
        }

        for( unsigned int i = 0; i < rows; i++ )
        {
            for( unsigned int j = 0; j < cols; j++ )
            {
                the_matrix[i][j] = rhs.the_matrix[i][j];
            }
        }
    }
    return *this;
}

Matrix::~Matrix()
{
    deleteMemory();
}

std::ostream& Matrix::out( std::ostream& os ) const
{
    for( unsigned int i = 0; i < rows; i++ )
    {
        os << "[ ";
        for( unsigned int j = 0; j < cols; j++ )
        {
            os << the_matrix[i][j] << " ,";
        }
        os <<" ]" << std::endl;
    }
    return os;
}

// global
std::ostream& operator<<( std::ostream& os, const Matrix& rhs )
{
    rhs.out( os );
    return os;
}

Matrix Matrix::operator+( const Matrix& rhs ) const
{
    if( rhs.rows != rows || rhs.cols != cols )
    {
        throw matrixException( "operator[], size mismatch" );
    }
    Matrix newMatrix( rows, cols );
    for( unsigned int i = 0; i < rows; i++ )
    {
        for( unsigned int j = 0; j < cols; j++ )
        {
            newMatrix[i][j] = the_matrix[i][j] + rhs.the_matrix[i][j];
        }
    }
    return newMatrix;
}

/**
 * @brief Matrix::operator *, cross product
 * @param rhs
 * @return
 */
Matrix Matrix::operator*( const Matrix& rhs ) const
{
    if( cols != rhs.rows )
    {
        throw matrixException(" operator*, matrixA cols not equal matrixB rows" );
    }

    Matrix newMatrix( rows, rhs.cols );
    for( unsigned int i = 0; i < rows; i++ )
    {
        for( unsigned int j = 0; j < rhs.cols; j++ )
        {
            for( unsigned int m = 0; m < cols; m++ )
            {
                newMatrix[i][j] += the_matrix[i][m] * rhs.the_matrix[m][j];
            }
        }
    }
    return newMatrix;
}

/*!
 * \brief operator *, support someMatrixObject * scaleValue but not scaleValue * someMatrixObject
 * \param rhs
 * \return
 */
Matrix Matrix::operator*( const double scale ) const
{
    Matrix newMatrix( rows, cols );
    for( unsigned int i = 0; i < rows; i++ )
    {
        for( unsigned int j = 0; j < cols; j++ )
        {
            newMatrix[i][j] = the_matrix[i][j] * scale;
        }
    }
    return newMatrix;
}

/**
 * @brief Matrix::operator *, dot product
 * @param rhs
 * @return
 */
double Matrix::dotProduct( const Matrix& rhs ) const
{
    if( cols != rhs.rows )
    {
        throw matrixException(" operator*, matrixA cols not equal matrixB rows" );
    }

    double dotProduct = 0.0;
    for( unsigned int i = 0; i < rows; i++ )
    {
        for( unsigned int j = 0; j < rhs.cols; j++ )
        {
           dotProduct += the_matrix[i][j] * rhs.the_matrix[i][j];
        }
    }
    return dotProduct;
}

Matrix Matrix::crossProduct( const Matrix& rhs ) const
{
    return ( ( *this ) * rhs );
}

//global
Matrix operator*( const double scale, const Matrix& rhs )
{
    return rhs * scale;
}

double Matrix::determinant( unsigned int size ) const
{
    double det = 0;

    Matrix m( size - 1, size - 1 );

    if( size < 1 )
    {
        throw matrixException( "determinant, size is zero" );
    }
    else if( size == 1 )
    {
        det = this->the_matrix[0][0];
    }
    else if( size == 2 )
    {
        det = this->the_matrix[0][0] * this->the_matrix[1][1] - this->the_matrix[1][0] * this->the_matrix[0][1];
    }
    else
    {
        unsigned int i;
        unsigned int j;
        unsigned int j1;
        unsigned int j2;
        for( j1 = 0; j1 < size; j1++ )
        {
            for( i = 1; i < size; i++ )
            {
                j2 = 0;
                for( j = 0; j < size; j++ )
                {
                    if( j == j1 ) continue;
                    m[i - 1][j2] = this->the_matrix[i][j];
                    j2++;
                }
            }
            det += pow( -1.0, j1 + 2.0 ) * this->the_matrix[0][j1] * m.determinant( size - 1 );
        }
    }
    return det;
}

Matrix Matrix::cofactor( unsigned int size ) const
{
    Matrix temp( size - 1, size - 1 );
    Matrix newMatrix( size, size );

    unsigned int j1;
    unsigned int i1;
    double det;
    for( unsigned int j = 0; j < size; j++ )
    {
        for( unsigned int i = 0; i < size; i++ )
        {
            i1 = 0;
            for( unsigned int ii = 0; ii < size; ii++ )
            {
                if( ii == i ) continue;
                j1 = 0;
                for( unsigned int jj = 0; jj < size; j++ )
                {
                    if( jj == j ) continue;
                    temp[i1][j1] = this->the_matrix[ii][jj];
                    j1++;
                }
                i1++;
            }
            det = temp.determinant( size - 1 );
            newMatrix[i][j] = pow( -1.0, i + j + 2.0 ) * det;
        }
    }
    return newMatrix;
}

Matrix Matrix::transpose( unsigned int size ) const
{
    double temp;
    Matrix newMatrix( size, size );

    for( unsigned int i = 0; i < size; i++ )
    {
        for( unsigned int j = 0; j < size; j++ )
        {
            temp = this->the_matrix[i][j];
            newMatrix[i][j] = this->the_matrix[j][i];
            newMatrix[j][i] = temp;
        }
    }
    return newMatrix;
}

Matrix Matrix::identityMatrix( const Matrix& rhs ) const
{
    if( rhs.rows != rhs.cols )
    {
        throw matrixException( "identifyMatrix, not a square matrix" );
    }
    Matrix newMatrix( rhs.rows, rhs.cols );

    unsigned int j = 0;
    for( unsigned int i = 0; i < rows; i++ )
    {
        newMatrix[i][j] = 1;
        j++;
    }
    return newMatrix;
}

Matrix Matrix::inverse2x2( const Matrix& rhs ) const
{
    if( rhs.rows != 2 || rhs.cols != 2 )
    {
        throw matrixException( "inverse2x2, matrix not 2 x 2" );
    }
    Matrix newMatrix( 2, 2 );
    Matrix adj( 2, 2 );

    adj[0][0] = rhs.the_matrix[1][1];
    adj[0][1] = -1*rhs.the_matrix[0][1];
    adj[1][0] = -1*rhs.the_matrix[1][0];
    adj[1][1] = rhs.the_matrix[0][0];

    double det = rhs.the_matrix[0][0] * rhs.the_matrix[1][1] - rhs.the_matrix[0][1] * rhs.the_matrix[1][0];

    if( det == 0 )
    {
        throw matrixException("inverse2x2,  determinant was zero no Inverses can be found" );
    }

    double inverseDet = 1/det;
    newMatrix = inverseDet * adj;
    return newMatrix;
}

Matrix Matrix::operator!() const
{
    if( rows != cols )
    {
        throw matrixException( "operator! rows and cols not equal" );
    }

    Matrix newMatrix( rows, cols );
    if( rows == 2 )
    {
        newMatrix = inverse2x2( *this );
    }
    else
    {
        Matrix cofactorMatrix( rows, cols );
        cofactorMatrix = this->cofactor( rows );
        Matrix adjointMatrix( rows, cols );
        adjointMatrix = cofactorMatrix.transpose( rows );
        double det = ( ( *this ).determinant( rows ) );
        if( det == 0 )
        {
            throw matrixException( "operator!, determinant was zero no Inverses can be found" );
        }
        newMatrix = adjointMatrix * ( 1 / det );
    }

    //double check matrix
    Matrix identity = identityMatrix( *this );
    Matrix check( rows, cols );
    check = ( *this ) * newMatrix;

    bool equal = true;
    for( unsigned int i = 0; i < this->rows && equal; i++ )
    {
        for( unsigned int j = 0; j < this->cols && equal; j++ )
        {
            if( identity[i][j] != check[i][j] )
            {
                equal = false;
                std::cout << "invertible may not be correct becuase of floating point rounding" << std::endl;
            }
        }
    }
    return newMatrix;
}

unsigned int Matrix::getRows() const
{
    return rows;
}

unsigned int Matrix::getCols() const
{
    return cols;
}
