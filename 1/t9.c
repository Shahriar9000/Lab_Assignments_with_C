/*#include <stdio.h>
#include <math.h>


int main ()
{
	int x, y, z;
	int i, space;
	int star=0;
	int left; 
	scanf("%d %d %d", &x, &y, &z);

	for (i=1; i<=z; i++){
		for (space =1; space <= x; space++){
			left = floor( space * (x/(2.0*z)) );
			printf("%d", left);
		//while (star!= (2*i - 1)){
			if (star==0 || star == 2*i-2 || i == z)
				{printf("#");}
			if else ()
				{printf(" "); }
			else 
				{printf(".");}
			star++;}
		star=0;
	
		printf("\n");
	
}
	/*for (i=1; i <= star; i++){
	printf("#");}
	
	printf("\n");




return 0;

}*/

#include <stdio.h>
#include <math.h>

int main (void) 
{
    int x;
    int y;
    int z;
    int k;
    int j;
    scanf("%d %d %d", &x , &y ,&z);
    

    for (j=z-1; j>=0; j--) 
    {   
        if (j == 0) 
        {
        	for (k =0; k<x; k++)
        	{
        	    printf("#");
        	}
        }

	else 
	{  
                
		int left = floor( j * (x/(2.0*z)) );
		int right = ceil( (x-1) + -j * (x/(2.0*z)) );

		for (k=0; k<left; k++)
        	{
        	    printf(" ");
        	}
		printf("#");
		
   		
		for (k=left+1; k<right; k++)
		{
		   if(j==z-1) 
		   {
			printf("#");	
		   }	
		   else
		   {
			printf(".");
		   }	  
                }    
		printf("#");            
                
        
	}
	printf("\n");
       
    } 

    return 0;	       
}
