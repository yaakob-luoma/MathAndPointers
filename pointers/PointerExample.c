#include <stdio.h>
#include <stdlib.h>

void increment( int *i )
{
  *i = (*i) + 1;
}

void pointerArgDemo()
{
  int a;
  a = 10;
  increment( &a );//call by reference
  printf( "a = %d\n", a );
}


int arraySum( int *a, int size )
{
  int i, sum = 0;
  for( i = 0; i < size; i++ )
  {
    sum += a[i];
  } 
  return sum;
}

void array2DHandler0( int **a, int x, int y )
{
  int i, j;
  for( i = 0; i < x; i++ )
  {
    for( j = 0; j < y; j++ )
    {
      printf("at [%d, %d]: %d\n,", i, j,  a[i][j] );
    }
  }
}

void array2DHandler1(int (*a)[3], int x )
{
  int i, j;
  for( i = 0; i < x; i++ )
  {
    for( j = 0; j < 3; j++ )
    {
      printf("at [%d, %d]: %d\n", i, j, a[i][j] );
    }
  }
}

void array2DHandler2( int a[][3], int x)
{
  int i, j;
  for( i = 0; i < x; i++ )
  {
    for( j = 0; j < 3; j++ )
    {
      printf("at [%d, %d]: %d\n", i, j, a[i][j] );
    }
  }
}

void arrayArgDemo()
{
  int A[] = { 1, 2, 3, 4, 5};
  int size = sizeof( A ) / sizeof( A[0] );
  int total = arraySum( A, size );
  printf( "total = %d\n", total );

  //3D array
  int B[3][2][2] = {
                     { 
                       {2,5},
                       {7,9}
                     },
                     {
                       {3,4},
                       {6,1}
                     },
                     {
                       {0,8},
                       {11,13}
                     }
                   };
  printf("%d %d %d %d\n", B, *B, B[0], &B[0][0] );
  printf("%p %p %p %p\n", B, *B, B[0], &B[0][0] );
  printf("%d\n", *(B[0][0]+1) );

  int C[2][3] = {
                  { 1, 2, 3 },
                  { 4, 5, 6 }
                };
  int rows = 2;
  int columns = 3;
  //create 2D array using **
  //first create memory for number of rows 
  int **D = (int**)calloc( rows, sizeof(int) );
  int i, j;
  //create memory for number of columns in each row
  for( i = 0; i < rows; i++ )
  {
    D[i] = (int*)calloc( columns, sizeof(int) );
  }
  //alternative to creating **D
  //int len = sizeof(int*) * rows + sizeof(int) * columns * rows;
  //D = (int**)calloc(len);
  //int *ptr;
  //ptr = (int*)(D + rows);//points to first element in array
  //for( i = 0; i < rows; i++ ) //loop to point rows pointer to appropriate location
  //{
  //D[i] = (ptr + c * i);
  //}
  //int count = 0;
  //for( i = 0; i < rows; i++ )
  //{
  //for( j = 0; j < columns; j++ )
  //{
  //D[i][j] = ++count; //OR *(*(D+i)+j) = ++count;
  //}
  for( i = 0; i < rows; i++ )
  {
    for( j = 0; j < columns; j++ )
    {
       D[i] [j] = (i + 1) * (j + 1); //should count 1 - 6
    } 
  }
  printf("2D array using (int **a, row, col)\n" );   
  array2DHandler0( D , 2, 3 );
  printf("2D array using (int (*a)[<col>], row)\n" );
  array2DHandler1( C, 2 );
  printf("2D array using (int a[][<col>], row)\n");
  array2DHandler2( C, 2);
  
  //IMPORTANT clean up after using malloc, calloc or realloc
  for( i = 0; i < rows; i++ )
  {
    free( D[i] );
  }
  free(D);
}


void addressDemo()
{
  int A[] = { 2, 4, 5, 8, 1 };
  int i;
  for( i = 0; i < 5; i++ )
  {
    printf("Address = %d\n", &A[i] );
    printf("Address = %d\n", A + i);
    printf("value = %d\n", A[i] );
    printf("value = %d\n", *( A + i ) ); 
  }
}


int main( )
{
  pointerArgDemo(); 
  addressDemo();
  arrayArgDemo();
  return 0;
}
