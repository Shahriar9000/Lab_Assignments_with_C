#include <assert.h>
 #include <stdint.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <math.h>
 

#include "intarr.h"

/*int intarr_save_json( intarr_t* ia, const char* filename )
{
    if(ia==NULL)
    {
        return 1;
    }
    int *arr=ia->data;
    int n=ia->len;
    int i;
    FILE *p;
    p=fopen(filename,"w");
    if(p!=NULL)
    {
        fprintf(p,"[\n");
        for(i=0;i<n;i++)
        {
            if(i!=n-1)  
            {
                fprintf(p," %d,\n",arr[i]);
            }
            else
            {
                fprintf(p," %d\n",arr[i]);
            }
        }
        fprintf(p,"]");
        fclose(p);
        return 0;
    }
    return 1;
}

intarr_t* intarr_load_json( const char* filename )
{
    FILE* f = fopen(filename, "r");
    if (f == NULL) return NULL;

    intarr_t* loaded = intarr_create(0);

    int value;
    //Get rid of [
    fscanf(f, "%d ", &value);

    while (fscanf(f, "%d, ", &value)) {
        if (value == ']') break;
        intarr_push(loaded, value);
    }


    fclose(f);
    return loaded;
}*/

int intarr_save_json( intarr_t* ia, const char* filename )
{	
	if (ia == NULL) {
		return 1;
	}
  
    FILE* f = fopen(filename,"a");
    if( f == NULL ) //checking if opening the file was successful
    {
      return 1;
    }

	int len = ia->len; 

	for ( int i =0; i<len; i++ ) {
		if (i==0) {	
		fprintf(f,"%c%c%d", 91 , 32 ,ia->data[i]);  //91 = "["    32 = Space
		}
		else {
		fprintf(f,"%c%c%d", 44 , 32 ,ia->data[i]); // 44 is comma
		}
	}
	fprintf(f," ]");
	fclose(f);
	return 0;
}

intarr_t* intarr_load_json( const char* filename ) {

	FILE* f = fopen( filename, "r");
	
	if (f == NULL ) {
		return NULL;
	}   //opened the file
	
	intarr_t * notun = intarr_create(0);
	
	if (notun == NULL) {
		return NULL;
	}  //created an array to store the stuff we read from file
	
	char trash1 ;
	char trash2 ;
	int  value;
	int i = 0;

	while (fscanf (f, "%c%c%d" , &trash1 , &trash2 , &value) == 3) {
		intarr_push(notun,value);
	}
	
	return notun; //i have to return a pointer to the new array i created from the file. 
}
