#include <stdio.h>

int identical (int a[], int b[], unsigned int len)
{	

if (len == 0)
	{ return 1;}

for (int i=0; i< len; i++){

if ( a[i] != b[i]){
return 0;}}

return 1;}



/*int main( void )
{
  int a[4] = {86, 77, 15, 93};
  int b[4]= {86, 77, 15, 93};
 
  if( identical( a, b, 4 ) == 1 )
  {
     printf( "a and b are identical\n" );
  } else {
    printf( "a and b are NOT identical\n" );
  }
  
  return 0;
}*/
