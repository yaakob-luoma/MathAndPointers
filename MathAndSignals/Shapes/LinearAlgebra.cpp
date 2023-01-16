#include "LinearAlgebra.h"

LinearAlgebra* LinearAlgebra::instance_ptr{nullptr};
std::mutex LinearAlgebra::mutex;

LinearAlgebra* LinearAlgebra::getInstance()
{
    std::lock_guard<std::mutex> lock(mutex);
    if ( instance_ptr == nullptr )
    {
        instance_ptr = new LinearAlgebra();
    }
    return instance_ptr;
}


double LinearAlgebra::determinant( const Matrix& matrix, unsigned int size ) const
{
    double det = 0;

    Matrix m( size - 1, size - 1 );

    if( size < 1 )
    {
        throw matrixException( "determinant, size is zero" );
    }
    else if( size == 1 )
    {
        det = matrix[0][0];
    }
    else if( size == 2 )
    {
        det = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
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
                    m[i - 1][j2] = matrix[i][j];
                    j2++;
                }
            }
            det += pow( -1.0, j1 + 2.0 ) * matrix[0][j1] * determinant( m, size - 1 );
        }
    }
    return det;
}

Matrix LinearAlgebra::cofactor( const Matrix& matrix, unsigned int size ) const
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
                    temp[i1][j1] = matrix[ii][jj];
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

Matrix LinearAlgebra::transpose( const Matrix& matrix, unsigned int size ) const
{
    double temp;
    Matrix newMatrix( size, size );

    for( unsigned int i = 0; i < size; i++ )
    {
        for( unsigned int j = 0; j < size; j++ )
        {
            temp = matrix[i][j];
            newMatrix[i][j] = matrix[j][i];
            newMatrix[j][i] = temp;
        }
    }
    return newMatrix;
}

Matrix LinearAlgebra::identityMatrix( const Matrix& rhs ) const
{
    if( rhs.getRows() != rhs.getCols() )
    {
        throw matrixException( "identifyMatrix, not a square matrix" );
    }
    Matrix newMatrix( rhs.getRows(), rhs.getCols() );

    unsigned int j = 0;
    for( unsigned int i = 0; i < rhs.getRows(); i++ )
    {
        newMatrix[i][j] = 1;
        j++;
    }
    return newMatrix;
}

Matrix LinearAlgebra::inverse( const Matrix& matrix ) const
{
    unsigned int rows = matrix.getRows();
    unsigned int cols = matrix.getCols();

    if( rows != cols )
    {
        throw matrixException( "operator! rows and cols not equal" );
    }

    Matrix newMatrix( rows, cols );
    if( rows == 2 )
    {
        newMatrix = inverse2x2( matrix );
    }
    else
    {
        Matrix cofactorMatrix( rows, cols );
        cofactorMatrix = cofactor( matrix, rows );
        Matrix adjointMatrix( rows, cols );
        adjointMatrix = cofactorMatrix.transpose( rows );
        double det = determinant( matrix, rows );
        if( det == 0 )
        {
            throw matrixException( "inverse, determinant was zero no Inverses can be found" );
        }
        newMatrix = adjointMatrix * ( 1 / det );
    }

    //double check matrix
    Matrix identity = identityMatrix( matrix );
    Matrix check( rows, cols );
    check = matrix * newMatrix;

    bool equal = true;
    for( unsigned int i = 0; i < rows && equal; i++ )
    {
        for( unsigned int j = 0; j < cols && equal; j++ )
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

Matrix LinearAlgebra::inverse2x2( const Matrix& matrix ) const
{
    if( matrix.getRows() != 2 || matrix.getCols() != 2 )
    {
        throw matrixException( "inverse2x2, matrix not 2 x 2" );
    }
    Matrix newMatrix( 2, 2 );
    Matrix adj( 2, 2 );

    adj[0][0] = matrix[1][1];
    adj[0][1] = -1 * matrix[0][1];
    adj[1][0] = -1 * matrix[1][0];
    adj[1][1] = matrix[0][0];

    double det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    if( det == 0 )
    {
        throw matrixException("inverse2x2,  determinant was zero no Inverses can be found" );
    }

    double inverseDet = 1/det;
    newMatrix = inverseDet * adj;
    return newMatrix;
}


/**
 * @brief Matrix::solveAugmentedMatrix
 * example:
 *  1 * x1 - 2 * x2 + 1 * x3 = 0
 *  0 * x1 + 2 * x2 - 8 * x3 = 8
 * -4 * x1 + 5 * x2 + 9 * x3 = -9
 *
 * [ 1, -2, 1, 0 ]
 * [ 0, 2, -8, 8 ]
 * [ -4, 5, 9, 9 ]
 *
 * solution:
 * [ 1, 0, 0, 29 ]
 * [ 0, 1, 0, 16 ]
 * [ 0, 0, 1, 3 ]
 * @return
 */
/**
 * @brief LinearAlgebra::echelonForm, convert matrix into Echelon form
 * Echelon form if
 * 1) all nonzero rows are above any rows of all zeros
 * 2) each leading entry of a row is in a column to the right of the leading entry of the row above it
 * 3) All entries in a column below a leading entry are zeros
 *
 * If a matrix in echelon form satisfies the following additional conditions, then it is in reduced echelon form / reduced row echelon form
 * 4) The leading entry in each nonzero row is 1
 * 5) Each leading 1 is the only nonzero entry in its column
 * For example:
 * [ 1, 0, 0, 29 ]
 * [ 0, 1, 0, 16 ]
 * [ 0, 0, 1, 3 ]
 * @param matrix
 * @return
 */
Matrix LinearAlgebra::rowReduction( const Matrix& matrix ) const
{
  unsigned int rows = matrix.getRows();
  unsigned int cols = matrix.getCols();

  unsigned int termSolvingFor = 0;

  Matrix newMatrix = matrix;

  while( termSolvingFor < rows //haven't complete the matrix
         && termSolvingFor < cols - 2 )
  {
      //term solving for is zero, swap or interchange with a row that does have a non-zero
      if( newMatrix[ termSolvingFor ][ termSolvingFor ] == 0.0 )
      {
          //find row below that is non-zero
          unsigned int i = termSolvingFor + 1;
          for(  ; i < rows; i++ )
          {
              if( newMatrix[ i ][ termSolvingFor ] != 0 )
              {
                  newMatrix = rowInterchange( newMatrix, termSolvingFor, i );
                  std::cout << "rowInterchange: " << std::endl << newMatrix;
                  break;
              }
          }
      }

      //term solving for is non-zero and non-one, scale term to one
      if( newMatrix[ termSolvingFor ][ termSolvingFor ] != 1.0 )
      {
        newMatrix = rowScaling( newMatrix, termSolvingFor );
        std::cout << "rowScaling: " << std::endl << newMatrix;
      }

      //are all other terms zero in the lower rows, eliminate term in other rows
      for( unsigned int i = termSolvingFor + 1; i < rows; i++ )
      {
        if( newMatrix[ i ][ termSolvingFor ] != 0.0 )
        {
            newMatrix = rowReplacement( newMatrix, termSolvingFor, i );
            std::cout << "rowReplacement: " << std::endl << newMatrix;
        }
      }

      termSolvingFor++;
  }

  //clean up step
  /* from the exampe:
  * matrix = [ 1, -2, 1, 0 ]
  *          [ 0, 2, -8, 8 ]
  *          [ -4, 5, 9, 9 ]
  *
  * newMatrix = [ 1, -2, 1, 0 ]
  *             [ 0,  1, -4, 4 ]
  *             [ 0,  0, 1,  3 ]
  *
  * cleanUp should give [ 1, 0, 0, 29 ]
  *                     [ 0, 1, 0, 16 ]
  *                     [ 0, 0, 1,  3 ]
  */
  std::cout << "Clean up" <<std::endl;
  //move from bottom right to top left
  int pivotColumn = cols - 2;
  int pivotPosition = pivotColumn - 1;

  while( pivotColumn >= 0 )
  {
      while( pivotPosition >= 0 )//haven't complete the matrix
      {
          if( newMatrix[ pivotPosition ][ pivotColumn ] != 0.0
              && pivotPosition + 1 < static_cast<int>( rows ) )
          {
            newMatrix = rowReplacement( newMatrix, pivotColumn, pivotPosition );
            std::cout << "rowReplacement: " << std::endl << newMatrix;
          }
          pivotPosition--;
      }
      //reset rows, and decrement columns

      pivotColumn--;
      pivotPosition = pivotColumn - 1;
  }

  return newMatrix;
}

unsigned int LinearAlgebra::findFirstNoneZero( const Matrix& matrix, unsigned int row ) const
{
    unsigned int cols = matrix.getCols();
    unsigned int j = 0;
    for( ; j < cols; j++ )
    {
        if( matrix[ row ][ j ] != 0.0 )
        {
            break;
        }
    }
    return j;
}

/**
 * @brief Matrix::isAugmentedMatrixContradiction
 * checks if there is not a solution
 * for example:
 *  if a row is [ 0, 0, 0, 2 ] it would be true that there is a contradiction
 *  as 0 * x1 + 0 * x2 + 0 * x3 != 2
 * @return bool, true if contradiction else false
 */
bool LinearAlgebra::isContradiction( const Matrix& matrix ) const
{
    unsigned int rows = matrix.getRows();
    unsigned int cols = matrix.getCols();

    for( unsigned int i = 0; i < rows; i++ )
    {
        //check all but the last column
        unsigned int numOfZeros = 0;
        for( unsigned int j = 0; j < ( cols - 2 ); j++ )
        {
            if( matrix[i][j] == 0.0 )
            {
                numOfZeros++;
            }
        }
        if( numOfZeros == ( cols - 1 ) //all cols, but the last are zero
            && matrix[i][cols-1] != 0.0 ) // and the last column is not zero
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Matrix::solveAugmentedMatrixReplacement
 * Replace one row by the sum of itself and a multiple of another row
 * @param row1, row used to help with replacement
 * @param row2, row that will be replaced
 */
Matrix LinearAlgebra::rowReplacement( const Matrix& matrix
                                                     , unsigned int row1
                                                     , unsigned int row2 ) const
{
    if( row1 == row2 )
    {
        throw matrixException( "rowReplacement, row1 and row2 are the same");
    }
    unsigned int cols = matrix.getCols();

   unsigned int colIndex = findFirstNoneZero( matrix, row1 );
   //unsigned int colIndex2 = findFirstNoneZero( matrix, row2 );

   if( colIndex >= cols )
   {
       throw matrixException( "solveAugmentedMatrixReplacement, colIndex is out of bounds");
   }

   double scaleAmount = -1 * matrix[ row2 ][ colIndex ];

   Matrix newMatrix = matrix;
   for( unsigned int j = 0; j < cols; j++ )
   {
       newMatrix[ row2 ][ j ] = ( scaleAmount * matrix[ row1 ][ j ] ) + matrix[ row2 ][ j ];
   }

   return newMatrix;
}

/**
 * @brief Matrix::solveAugmentedMatrixInterchange
 * Interchange two rows
 * @param row1
 * @param row2
 */
Matrix LinearAlgebra::rowInterchange( const Matrix& matrix
                                                     , unsigned int row1
                                                     , unsigned int row2 ) const
{
    unsigned int cols = matrix.getCols();

    Matrix newMatrix = matrix;

    //set row2 into row1
    //set row1 into row2
    for( unsigned int j = 0; j < cols; j++ )
    {
        newMatrix[ row1 ][ j ] = matrix[ row2 ][ j ];
        newMatrix[ row2 ][ j ] = matrix[ row1 ][ j ];
    }

    return newMatrix;
}

/**
 * @brief Matrix::solveAugmentedMatrixScaling
 * Multiply all entries in a row by a nonzero constant
 * @param row
 */
Matrix LinearAlgebra::rowScaling( const Matrix& matrix, unsigned int row ) const
{
    unsigned int cols = matrix.getCols();

    unsigned int colIndex = findFirstNoneZero( matrix, row );
    if( colIndex >= cols )
    {
        throw matrixException( "rowScaling, colIndex is out of bounds");
    }

    double scaleAmount = 1 / matrix[ row ][ colIndex ];

    Matrix newMatrix = matrix;

    for( unsigned int j = 0; j < cols; j++ )
    {
        newMatrix[ row ][ j ] = scaleAmount * matrix[ row ][ j ];
    }

    return newMatrix;
}


