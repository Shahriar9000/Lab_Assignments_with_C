/*
 * imageops.c - Simple operations on images
 *
 * C laboratory exercises.
 * Richard Vaughan, 2014.
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* PAIR SECTION BEGINS - WORK WITH YOUR PARTNER ON THESE TASKS */

/*-------------------------------------------------
  PART 0: DEMONSTRATION
*/


// get the value in the array at coordinate (x,y)
uint8_t get_pixel( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows,
           unsigned int x,
           unsigned int y )
{
    assert( x < cols );
    assert( y < rows );
    return array[ y*cols + x ];
}

// set the pixel at coordinate {x,y} to the specified color
void set_pixel( uint8_t array[], 
        unsigned int cols, 
        unsigned int rows,
        unsigned int x,
        unsigned int y,
        uint8_t color )
{
    assert( x < cols );
    assert( y < rows );
    array[ y * cols + x ] = color;
} 

// Set every pixel to 0 (black) 
void zero( uint8_t array[],
	   unsigned int cols,
	   unsigned int rows )
{
  // your code here.
	 memset( array, 0, cols * rows * sizeof(array[0]) );

}

// Returns a pointer to a freshly allocated array that contains the
// same values as the original array, or a null pointer if the
// allocation fails. The caller is responsible for freeing the array
// later.
uint8_t* copy( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows )
{
  // your code here
  return NULL;
}



/*-------------------------------------------------
  PART 1: OPERATIONS ON THE WHOLE IMAGE 
*/

/* TASK 1 - three easy functions to get started */

// Return the darkest color that appears in the array; i.e. the
// smallest value
uint8_t min( const uint8_t array[], 
	     unsigned int cols, 
	     unsigned int rows )
{
  // your code here
   uint8_t darkest = 255;

    for(int pixel = 0; pixel < (cols * rows); pixel++){
        if(array[pixel] < darkest){
            darkest = array[pixel]; }}
  return darkest;
}

// Return the lightest color that appears in the array; i.e. the
// largest value
uint8_t max( const uint8_t array[], 
		 unsigned int cols, 
		 unsigned int rows )
{
  // your code here
 int8_t lightest = 0;

    for(int pixel = 0; pixel < (cols * rows); pixel++){
        if(array[pixel] > lightest){
            lightest = array[pixel]; }}

    return lightest;
}

// TASK 2

//  Replace every instance of pre_color with post_color.
void replace_color(  uint8_t array[], 
		     unsigned int cols, 
		     unsigned int rows,
		     uint8_t pre_color,
		     uint8_t post_color )
{
  // your code here
	for (int x = 0; x<(cols*rows); x++)
    {
        if (array[x] == pre_color)
        {
             array[x] = post_color;
        }
    }
}


/* TASK 3  - two functions */


// flip the image, left-to-right, like in a mirror.
void flip_horizontal( uint8_t array[], 
              unsigned int cols, 
              unsigned int rows )
{
  // your code here
    unsigned int left = 0;
    unsigned int right = cols-1;

    for(int r = 0; r < rows; r++){  
        while(left != right && right > left){
            int index1 = r * cols + left;
            int index2 = r * cols + right;

            int temp = array[index1];
            array[index1] = array[index2];
            array[index2] = temp;
            right--;
            left++;
        }

        // Reset left and right after processing a row.
        left = 0;
        right = cols-1;
    }
}

// flip the image top-to-bottom.
void flip_vertical( uint8_t array[], 
            unsigned int cols, 
            unsigned int rows )
{
    // your code here
	int top = 0;
   int bottom = (rows - 1) * cols;

   while (top < bottom) {

     for (int c = 0; c < cols; ++c) {
       int temp = array[top + c];
       array[top + c] = array[bottom + c];
       array[bottom + c] = temp;
     }

     top += cols;
     bottom -= cols;
   }
}

/* TASK 4 */

// Find the first coordinate of the first pixel with a value that
// equals color. Search from left-to-right, top-to-bottom. If it is
// found, store the coordinates in *x and *y and return 1. If it is
// not found, return 0.
int locate_color(  const uint8_t array[], 
		   unsigned int cols, 
		   unsigned int rows,
		   uint8_t color,
		   unsigned int *x,
		   unsigned int *y )
{
    // your code here
	int a = 0;
	int b = 0;
	for (a=0; a<rows; a++)
	{
		for (b=0; b<cols; b++)
		{
			if ((get_pixel(array,cols,rows,b,a)) == color)
			{
				*x = b;
				*y = a;
				return 1;
			}
		}
	}
    return 0;
}


/* TASK 5 */

// Invert the image, so that black becomes white and vice versa, and
// light shades of grey become the corresponding dark shade. 
void invert( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows )
{
    // your code here
	int i = 0;
	int j = 0;
	uint8_t a;
	for (i=0 ; i<cols; i++)
	{
		for (j=0; j<rows; j++)
		{
			a = get_pixel(array, cols, rows, i, j);
			set_pixel(array, cols, rows, i, j, 255-a);
		}
	}
}

/* TASK 6 */

// Multiply every pixel by scale_factor, in order to brighten or
// darken the image. Any resulting value over 255 is
// thresholded to 255.
void scale_brightness( uint8_t array[],
            unsigned int cols,
            unsigned int rows,
            double scale_factor )
{
  // your code here
	
	int len = cols*rows;
	int i;
	float a = 0.0;
	for (i=0;i<len;i++)
	{
		a = round(scale_factor*array[i]);
		if (a >= 255)
			array[i] = 255;
		else
		{
			array[i] = a;
		}
	}
}


/* TASK 7 */

// Normalize the dynamic range of the image, i.e. Shift and scale the
// pixel colors so that that darkest pixel is 0 and the lightest pixel
// is 255. Hint: you already wrote min() and max(). 
void normalize( uint8_t array[],
        unsigned int cols,
        unsigned int rows )
{
    // your code here
    uint32_t minv,maxv;

    minv = min(array,cols,rows);
    maxv= max(array,cols,rows);
    //uint32_t range= maxv-minv;
      	if( (maxv - minv) > 0){
 
  	//declaring another array to save new pixel values.
  	uint8_t temp[cols*rows];
 
  	// array initialized
  	for (int i = 0; i < cols*rows ; ++i) {temp[i] = 0;}
 
  	//calculating new pixel values.
  	for (int i = 0; i < cols*rows ; ++i){
    	temp[i] = ((array[i] - minv)*255) / (maxv - minv);
  	}
 
  	//changing the pixel values of the image accordingly.
  	for (int i = 0; i < cols*rows ; ++i)
  	{
    	if(array[i] == minv){ array[i] = 0;}
 
    	else if(array[i] == maxv){ array[i] = 255;} 
 
    	else{ array[i] = round(temp[i]); }
  	}
    }}


/* TASK 8 */

// Return a new image of size rows/2 by cols/2 If the original image              
// has an odd number of columns, ignore its rightmost column. If the              
// original image has an odd number of rows, ignore its bottom row.               
// The value of a pixel at (p,q) in the new image is the average of               
// the four pixels at (2p,2q), (2p+1,2q), (2p+1,2q+1), (2p,2q+1) in               
// the original image.                                                            
uint8_t* half( const uint8_t array[],
	       unsigned int cols,
	       unsigned int rows )
{
  // your code here
	int x = 0;
	int y = 0;
	if (cols%2!=0)
	{
		cols = cols - 1;
	}
	if (rows%2!=0)
	{
		rows = rows - 1;	
	}
	unsigned int newcols = cols/2;
	unsigned int newrows = rows/2;
	uint8_t *new = malloc(newrows*newcols*sizeof(uint8_t));
	if (new != 0)
	{
		for (x = 0; x < cols; x+=2)
		{
			for (y = 0; y < rows ; y+=2)
			{
				float color = round((get_pixel(array,cols,rows,x,y)
					+ get_pixel(array,cols,rows,x,y+1)
					+ get_pixel(array,cols,rows,x+1,y)
					+ get_pixel(array,cols,rows,x+1,y+1))/4.00);
				set_pixel(new,newcols,newrows,x/2,y/2,color);
			}
		}
		return new;
	}
 
	else
	{	
  return NULL;
	}
}




/*-------------------------------------------------
  PART 2: OPERATIONS ON IMAGE SUB-REGIONS

  These functions operate only on a rectangular region of the array
  defined by a (left,top) corner (i.e. closer to the image origin) and
  (right,bottom) corner (i.e. further from the image origin).

  The region includes all the columns from [left, right-1] inclusive,
  and allthe rows from [top, bottom-1] inclusive.
  
  In every case, you may assume that left <= right and top <= bottom:
  do not need to test for this.

  The area of the region is right-left * bottom-top pixels, which
  implies that if left == right or top == bottom, the region has no
  area and is defined as "empty". Each function notes how to handle
  empty regions.
 
  In every function, use assert() to test bounds on the region
  corners.
*/

/* TASK 9 */

// Set every pixel in the region to color. If the region is empty, the
// image must be unchanged.
void region_set( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows,
         unsigned int left,
         unsigned int top,
         unsigned int right,
         unsigned int bottom,
         uint8_t color )
{
    // your code here
	int x = 0;
	int y = 0;
	if ((left != right) && (top != bottom))
	{
		for (x = left; x < right; x++)
		{
			for (y = top; y < bottom; y++)
			{
				set_pixel(array, cols, rows, x, y, color);
			}
		}
	} 
}

/* TASK 10 */

// Return the sum of all the pixels in the region. Notice the large
// return type to handle potentially large numbers. Empty regions
// return the sum 0.
unsigned long int region_integrate( const uint8_t array[], 
                    unsigned int cols, 
                    unsigned int rows,
                    unsigned int left,
                    unsigned int top,
                    unsigned int right,
                    unsigned int bottom )
{
    // your code here
	int x = 0;
	int y = 0;
	long int sum = 0;
	if ((left != right) && (top != bottom))
	{
		for (x = left; x < right; x++)
		{
			for (y = top; y < bottom; y++)
			{
				sum = sum + get_pixel(array, cols, rows, x, y);
			}
		}
		return sum;
	}
    return 0;
}

/* TASK 11 */

// Get a new image which is a copy of the region. Empty regions return
// a null pointer. If memory allocation fails, return a null
// pointer. The caller is responsible for freeing the returned array
// later.
uint8_t* region_copy( const uint8_t array[], 
              unsigned int cols, 
              unsigned int rows,
              unsigned int left,
              unsigned int top,
              unsigned int right,
              unsigned int bottom )
{
    // your code here
	int x = 0;
	int y = 0;
	int length = right - left;
	int width = bottom - top;
	uint8_t *new = malloc((length)*(width)*sizeof(uint8_t));
	if ((left != right) && (top != bottom))
	{
		for (x = left; x < right; x++)
		{
			for (y = top; y < bottom; y++)
			{
				int color = get_pixel(array,cols,rows,x,y);
				set_pixel(new,length,width,x-left,y-top,color);
			}
		}
	return new;
	}
  return NULL;
}


