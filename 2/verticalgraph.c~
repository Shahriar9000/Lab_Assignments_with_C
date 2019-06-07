/*#include <stdio.h>

int main ()
{	
	int a[80];
	int len=0;
	int value,j,nc,nw;
	int h_max=0;

	while (scanf("%d", &value) != EOF){
	      a[len] = value;
	       len=len+1;
	if ( len == 80){ 
		break;}}

	for (int i = 0; i < len; i++) {
 		 if (a[i] > h_max){ h_max = a[i];}}


	for (int i = h_max; i >= 0; i--) {
   		 for (int j = 0; j < len; j++) {
     			 if (a[j] > i) {
       				 printf("#"); }
     		  	 else {
    			    printf(" ");}
    				}
   		printf("\n");}

return 0;}*/

#include <stdio.h>


int main() {

	int i = 0;
	int arr[80] = {0};
	int temp =0;
	int j =0;
	int r;
	int c;

	while( temp != EOF ) {
		temp = scanf( "%d" , &arr[i]);
		i++;
	}
		
	

	int col = i-1;
	int max = arr[0];
	
	for (j=1; j<i-1; j++) {
		if (arr[j]>max){
			max = arr[j];
		}	
	}
	

	for (r=max-1; r>=0; r--){
		for (c =0; c<col; c++){
			if (arr[c]>r){
				printf("#");
			}
			else {
				printf(" ");
			}
		}
	printf("\n");
	}

return 0;}





