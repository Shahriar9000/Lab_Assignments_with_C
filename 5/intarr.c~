#include <assert.h>
 #include <stdint.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <math.h>
 
//#include "intarr.h"
/* Structure type that encapsulates our safe int array. */
typedef struct {
  int* data;
  unsigned int len;
} intarr_t;
 
/* A type for returning status codes */
typedef enum {
  INTARR_OK,
  INTARR_BADARRAY,
  INTARR_BADINDEX,
  INTARR_BADALLOC,
  INTARR_NOTFOUND
} intarr_result_t;
 
 
//t1
 
// Create a new intarr_t with initial size len.  If successful
// (i.e. memory allocation succeeds), returns a pointer to a
// newly-allocated intarr_t.  If unsuccessful, returns a null pointer.
 
intarr_t* intarr_create( unsigned int len)
{
	intarr_t* kt = NULL;
 
	kt = malloc(sizeof(intarr_t));
	if (kt != NULL)
	{
		kt->data = malloc(len * sizeof(int));
		if(kt->data == NULL)
		{
			free(kt);
		}
 
		else
		{
			kt->len = len;
		}
	}
 
	return kt;
}
 
 
// frees all memory allocated for ia. If the pointer is null, do
// nothing. If the ia->data is null, do not attempt to free it.
void intarr_destroy( intarr_t* ia)
{
	if (ia == NULL)
	{
		if (ia->data != NULL)
		{
			free(ia->data);
		}
	}
 
	else if(ia != NULL)
	{
		free(ia);
	}
}
 
 
 
//t2
 
// If index is valid, set the value at ia->data[index] to val and return
// INTARR_OK. Otherwise, leave the array unmodified and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
 
intarr_result_t intarr_set( intarr_t* ia, unsigned int index, int val )
{
 
if(ia == NULL)
	{
		return(INTARR_BADARRAY);
	}
	else if(index<ia->len)
	{
		ia->data[index] = val;
		return(INTARR_OK);
	}
	else if(index>ia->len)
	{
		return(INTARR_BADINDEX);
	}
 
}
 
 
// If index is valid and i is non-null, set *i to ia->data[index] and return
// INTARR_OK. Otherwise no not modify *i and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_get( const intarr_t* ia, unsigned int index, int* i)
{
 if (ia == NULL)
    {
        return INTARR_BADARRAY;
    }
    else
    {
        // if (ia->data[index] != 0)
        if ( index < ia->len )
        {
            if (i != NULL)
            {
                *i = ia->data[index];
            }
            return INTARR_OK;
        }
        else
        {
            return INTARR_BADINDEX;
        }
    }
    return 0;
}
 
 
 
 
//t3
 
// Return a duplicate of ia, allocating new storage for the duplicate
// data (we call this a "deep copy"). If unsuccessful (i.e. memory
// allocation for the copy fails, or ia is null), return a null pointer. 
 
intarr_t* intarr_copy( const intarr_t* ia )
{       
	intarr_t* dup=malloc(sizeof(intarr_t));
	int i=0;
	if (dup==NULL || ia==NULL){
		return NULL;
	}
	dup->data=malloc((ia->len)*sizeof(int));
	dup->len=ia->len;
	if (dup->data==NULL){
		return NULL;
	}
	while(i<(ia->len)){
		dup->data[i]=ia->data[i];
		i++;
	}
	return dup;
 
}
 
 
//t4
 
// sort ia by value smallest-to-largest, so that data[i] < data[i+1]
// for all valid i, then return INTARR_OK. Works in-place: contents of
// ia are sorted on return. If ia is null, return
// INTARR_BADARRAY.
 
intarr_result_t intarr_sort( intarr_t* ia )
{
	int minpos,swap;
	if (ia==NULL)
	{
		return INTARR_BADARRAY;
	}
	for (int i = 0; i < (ia->len)-1; i++)
	{
		minpos=i;
		for (int j = i+1; j < (ia->len); j++)
		{
			if ((ia->data[j]) < (ia->data[minpos])) {
				minpos = j;
			}
		}
		if(minpos != i) {
			swap=ia->data[i];
			ia->data[i]=ia->data[minpos];
			ia->data[minpos]=swap;
		}
	}
	return INTARR_OK;
}
 
 
//t5
 
// Find the first occurrence of the target in the array, searching from
// index 0. If the target is found and i is non-null, set *i to the
// location index and return INTARR_OK. If target does not occur in
// the array, leave *i unmodified and return INTARR_NOTFOUND. If ia is
// null, return INTARR_BADARRAY.
intarr_result_t intarr_find( intarr_t* ia, int target, int* i )
{
	if (ia == NULL)
	{
		return INTARR_BADARRAY;
	}
 
	int j;
	for (j = 0; j < ia->len; j++)
	{
		if (ia->data[j] == target)
		{
			*i = j;
			return INTARR_OK;
		}
	}
 
	return INTARR_NOTFOUND;
}
 
 
 
//t6
 
// Append val to the end of ia (allocating space for it). If
// successful, return INTARR_OK, otherwise return
// INTARR_BADALLOC. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_push( intarr_t* ia, int val )
{	unsigned int len = ia->len;
	if (ia==NULL)
	{
		return INTARR_BADARRAY;
	}
	ia->data = realloc(ia->data, (sizeof(int)*(len+1)));
	if (ia->data != NULL)
	{
		ia->data[len]=val;
		ia->len++;
		return INTARR_OK;
	}
	return INTARR_BADALLOC;
}
 
 
 
// If the array is not empty, remove the value with the highest index
// from the array, and, if i is non-null, set *i to the removed value,
// then return INTARR_OK. If the array is empty, leave *i unmodified
// and return INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_pop( intarr_t* ia, int* i )
{	
	unsigned int len = ia->len;
	if (ia==NULL)
	{
		return INTARR_BADARRAY;
	}
	if (len!=0 && i!=NULL){
		ia->data=realloc(ia->data,(sizeof(int)*(len)));
		if(ia->data!=NULL){
			*i = ia->data[len-1];
			ia->len--;
			return INTARR_OK;
		}
	}
	return INTARR_BADINDEX;
}
 
 
//t7
 
// Resize ia to contain newlen values. If newlen is less than the
// original array length, the end of the array is discarded. If newlen
// is greater than the original array length, initialize all the new
// integers to zero. If the allocation is successful, return
// INTARR_OK, otherwise return INTARR_BADALLOC. If ia is null, return
// INTARR_BADARRAY.
intarr_result_t intarr_resize( intarr_t* ia, unsigned int newlen )
{
	if (ia == NULL)
	{
		return INTARR_BADARRAY;
	}
	if(newlen < ia->len)
	{
		ia->data = realloc(ia->data, newlen * sizeof(ia->data));
		ia->len=newlen;
		if(ia)
		{
			return INTARR_OK;
		}
		else return INTARR_BADALLOC;
	}
	if(newlen > ia->len)
	{
		int old_length=ia->len;
		ia->data = realloc(ia->data, newlen * sizeof(ia->data));
		ia->len= newlen;
		if(ia)
		{
			memset(ia->data,0,(newlen - old_length) * sizeof(ia->data));
			return INTARR_OK;
		}
		else return INTARR_BADALLOC;
	}
	return 0;
}
 
 
 
 
//t8
 
// Get a deep copy of a portion of ia from index first to index last
// inclusive. If successful, return a pointer to a newly-allocated
// intarr_t containing a copy of the specified section. If an error
// occurs, i.e. ia is null, first or last are out of bounds, last <
// first, or memory allocation fails, return a null pointer.
intarr_t* intarr_copy_subarray( intarr_t* ia, 
				unsigned int first, 
				unsigned int last )
{
	if (ia == NULL || last<first || first<0 || last+1>ia->len)
		{
			return NULL;
		}
	intarr_t* c = NULL;
	c = malloc(sizeof(intarr_t));
	if (ia != NULL)
	{
		c->data = malloc((last-first+1) * sizeof(int));
		if (c->data == NULL)
		{
			free(c);return NULL;
		}
		else
		{
			for(int n=0; n < last-first+1 ;n++)// 1 2 3 < 3-1+1=3
			{
				c->data[n]=ia->data[first+n];
			}
			c->len=last-first+1;
			return c;
		}
	}
	return NULL;
}
