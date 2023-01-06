#include <stdio.h>

int add( int a, int b )
{
  return a + b;
}

void printHello(char *name )
{
  printf("Hello %s\n", name);
}

void functionPointerDemo()
{
  int c;
  int (*p)(int, int);
  p = &add;
  c = (*p)(2,3);
  printf( "%d\n", c);

  void (*ptr)(char*);
  ptr = printHello;
  ptr("From function functionPointerDemo\n");
}

void a()
{
  printf("From function a\n");
}

void b( void(*ptr)())
{
  ptr();//call-back function that ptr points to
}

int compareAscend(int a, int b)
{
  if( a > b ) return 1;
  else return -1;
}

int compareDescend( int a, int b)
{
  if( a < b ) return 1;
  else return -1;
}

//callback function should compare two integers, should return 1 if first element has
//higher rank, 0 if elements are equal and -1 if second element has higher rank.
void bubbleSort( int *A, int n, int (*compare)(int, int) )
{
  int i, j, temp;
  for( i = 0; i < n; i++ )
  {
    for( j = 0; j < n - 1; j++ )
    {
      if( compare( A[ j ], A[ j + 1 ] ) > 0 ) //compare A[j] with A[j+1] and SWAP if needed
      {
        temp = A[ j ];
        A[ j ] = A[ j + 1 ];
        A[ j + 1 ] = temp;
      }
    }
  }
}

void callbackDemo()
{
  //a and b are functions defined in this file
  void (*p)() = a;
  b(p);
 
  //alternative
  //b(a);
  //
  //another example
  int i, array[] = {3, 2, 1, 5, 6, 4};
  printf("Ascending order:\n");
  bubbleSort( array, 6, compareAscend );
  for( i = 0; i < 6; i++ )
  {
    printf( "%d\n", array[i] );
  }
  printf("Descending order:\n");
  bubbleSort( array, 6, compareDescend );
  for( i = 0; i < 6; i++ )
  {
    printf( "%d\n", array[i] );
  } 
}

int main( )
{
  functionPointerDemo();
  callbackDemo(); 
  return 0;
}
