#include <stdlib.h>
#include <stdlib.h>
#include <assert.h>
#include "point_array.h"

// Safely initalize an empty array structure.
void point_array_init( point_array_t* pa ) {
   assert(NULL != pa);
   pa->len = 0;
   pa->reserved = 2;
   /*pre allocating for 10 elements*/
   pa->points = (point_t*) realloc (NULL, (pa->reserved) * sizeof(point_t));;
}


// Resets the array to be empty, freeing any memory allocated if
// necessary.
void point_array_reset( point_array_t* pa ) {
   assert(NULL != pa);
   free(pa->points);
   pa->points = NULL;
   pa->len = 0;
   pa->reserved = 0;
}


// Append a point to the end of an array. If successful, return 0,
// else return 1;
int point_array_append( point_array_t* pa, point_t* p ) {
    assert( pa );
    assert( p );

    if( pa->len >= pa->reserved )
    {
        size_t new_res = pa->len * 2 + 1;  // add 1 to take care of a NULL array
        size_t sz= new_res * sizeof(point_t);
        point_t* tmp = realloc( pa->points, sz );
        if( tmp == 0 )
            return 1; //fail
        pa->points = tmp;
        pa->reserved = new_res;
    }
    pa->points[pa->len] = *p; // copy struct into array
    pa->len++;
    return 0;
}

// Remove the point at index i from the array, reducing the size of
// the array by one. The order of points in the array may change.
int point_array_remove( point_array_t* pa, unsigned int i ) 
{

    assert( pa );
    if( i >= pa->len )
       { return 1;}
    
	pa->points[i] = pa->points[pa->len-1];
	pa->points[i] = pa->points[i+1];

   /* if (i < pa->len-1)
	{ pa->points[i] = pa->points[i+1];
		point_array_remove(&pa, ++i );
	}*/



    /*while( i < pa->len-1 )
    {
        pa->points[i] = pa->points[i+1];
        i++;
    }*/
    pa->len--;
    return 0;

/*
	if(pa-&gt;len != 0 &amp;&amp; (i &lt; pa-&gt;len))
	{
		pa-&gt;points[i] = pa-&gt;points[pa-&gt;len - 1];
			--(pa-&gt;len);
		return 0;
	}
	else
	{
		return 1;
	}*/

 /* if(pa!=NULL)
  {
    if(i==pa->len-1)
    {pa->points=realloc(pa->points,sizeof(point_t)*(pa->len-1));
 
    }
   else
  { pa->points[i]=pa->points[pa->len-1];
 
    pa->points=realloc(pa->points,sizeof(point_t)*(pa->len-1));
}
  pa->len=pa->len-1;
 
  if(pa->points==NULL)
  return 1;
  else return 0;
 
  }
  else return 1;*/
}
