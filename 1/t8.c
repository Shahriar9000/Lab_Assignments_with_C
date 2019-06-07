#include <stdio.h>
#include <math.h>


int main ()
{
	char hashtag = '#';
	char dot = '.';
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);

	
for (int i=1; i <= y ; i++ )
{	//printf ("%c" , hashtag);
	
	for ( int j=1; j <= x; j++)
	{
 		if ( i==1 || i == y || j == 1 || j == x) 
			{printf ("%c" , hashtag);}
		else 
		{ printf ("%c", dot);}
	
		}
	printf( "\n");
	
}

	

	return 0;

}
