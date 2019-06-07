#include <stdio.h>
#include <math.h>


int main ()
{
	
	float i = 0.0;
	for (int j=0; j>=0; j++){
	int result = scanf ("%f", &i);
	if (result == 1)
	{printf ("%.0f %.0f %.0f\n" , floor(i), round(i), ceil(i));
		continue;}
	
	else 
	   {printf("Done.\n");
		break;}
	}
	
	
	
	/*float i = 0.0;
	int a = 0; 
	a = scanf ("%f\n", &i);
	printf ("%.0f %.0f %.0f\n" , floor(i) , round(i), ceil(i)); 
	

	/*for (int j=1; j>=0; j++){
	
	
	if (a == EOF)
	    {printf("Done.\n");
		break;}*/
	//}


	return 0;

}
