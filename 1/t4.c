#include <stdio.h>
#include <math.h>

int main()
{

	float i = 0.0;
	int a = 0; 
	a = scanf  ("%f", &i);
	if ( a == 1)
	{ printf ("%.0f %.0f %.0f\n" , floor(i) , round(i), ceil(i)); }
	else 
	{ printf ("scanf error: (%d)\n" , a); }

	return 0;
}
