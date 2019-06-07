#include <stdlib.h>
#include <stdlib.h>
#include <stdlib.h>
#include <assert.h>
#include "point_array.h"


void point_array_init( point_array_t* pa )
{
if(pa!=NULL)
  {
    pa->len=0;
    pa->points = malloc(sizeof(point_t));
    pa->reserved=0;
  }

}



void point_array_reset( point_array_t* pa )
{
if(pa!=NULL)
  {   //pa->points = NULL;
      free(pa->points);
      free(pa);
 
  }
}


int point_array_append( point_array_t* pa, point_t* p )
{
if(pa!=NULL)
{
	pa->points=realloc(pa->points,sizeof(point_t)*(pa->len+1));
	pa->points[pa->len]=*p;
	pa->len=pa->len+1;
	if(pa->points==NULL)
	return 1;
	else return 0;
 
}
else return 1;

}

int point_array_remove( point_array_t* pa, unsigned int i )
{
 assert( pa );
    if( i >= pa->len )
       { return 1;}
    
	pa->points[i] = pa->points[pa->len-1];
	pa->points[i] = pa->points[i+1];

   
    pa->len--;
    return 0;
}





/*
  if(pa == NULL)
  { 
	return 1;
  }

  if(i == pa->len-1)
    {
	pa->points=realloc(pa->points,sizeof(point_t)*(pa->len-1));
    }
  else
  { 
	pa->points[i]=pa->points[pa->len-1];
 	pa->points=realloc(pa->points,sizeof(point_t)*(pa->len-1));
   }
  pa->len=pa->len-1;
 
  if(pa->points==NULL)
	{
  	return 1;
	}
  return 0;*/

 

