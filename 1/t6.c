#include <stdio.h>
#include <math.h>


int main ()
{
	
	float i = 0.0;
	float smallest_number = 100000.0;
	float largest_number = -100000.0;
	float total_number = 0;
	float sum = 0.0;
	float mean = 0.0;
	
	for (int j=0; j>=0; j++){
	
	int result = scanf ("%f", &i);
	
	if (result == EOF)
	{ break; }
	
	if (result == 1 )
	{ if ( -100000 <= i <= 100000){
		sum= sum + i;
		total_number = total_number + 1;
		if ( i <= smallest_number)
		{ smallest_number = i;}
		if ( i >= largest_number)
		{ largest_number = i;}
		continue;}
	}}

	mean = sum/total_number;
	printf ("%.2f %.2f %.2f\n" , smallest_number, largest_number, mean );
	

	return 0;

}
