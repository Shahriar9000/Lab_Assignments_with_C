#include <stdint.h> // for uint8_t 
#include <stdlib.h> // for malloc() 
#include <string.h> // for memset() 
#include <stdio.h> 
#include <math.h> 
#include <assert.h> 
#include "intarr.h" 
/* LAB 6 TASK 1 */ /*   Save the entire array ia into a file called 'filename' in (a binary   file format) that can be loaded by intarr_load_binary(). Returns   zero on success, or a non-zero error code on failure. Arrays of   length 0 should produce an output file containing an empty array. */ 

int intarr_save_binary( intarr_t* ia, const char* filename ) 
{ 	if (ia == 0) 
	{ return 1; 	}     
	FILE* f = fopen(filename,"w");     	
	if( f == NULL )     
	{ return 1;     } 	
	int len = ia->len; 	
	if (fwrite(&len , sizeof(int), 1, f) != 1) 
	{ return 1; 	} 		
	if ( fwrite(ia->data, sizeof(int), len, f) != len ) 
	{ return 1; 	} 	
	fclose(f); 	
	return 0; 
} 
/*   Load a new array from the file called 'filename', that was   previously saved using intarr_save_binary(). Returns a pointer to a   newly-allocated intarr_t on success, or NULL on failure. */ 

intarr_t* intarr_load_binary( const char* filename ) 
{ 	FILE *f = fopen( filename, "r");     	
	int len; 	
	if(f == NULL) 
	{ return NULL; 	} 		
	if (fread( &len , sizeof(int) , 1 , f) != 1) 
	{ return NULL; 	} 	
	intarr_t*new = intarr_create(len); 	
	if (fread(new->data, sizeof(int) , len , f) != len) 
	{ return NULL; 	} 	
	return new; //i have to return a pointer to the new array i created from the file. 
}
