#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
 
void draw_circle( uint8_t img[], 
      unsigned int cols, 
      unsigned int rows, 
      int x,
      int y,
      int r,
      uint8_t color )
{
    int i, j;
    double xtoi,ytoj,dist;
 
    for(i = 0; i< cols; i++)
    {
        for(j = 0; j< rows;j++)
        {
 
          if(r > 0 )
          {
            xtoi = i-x-.5;
            ytoj = j-y-.5;
            dist = sqrt(pow(xtoi,2) + pow(ytoj,2));
            if(dist<r)
            {
                set_pixel(img, cols, rows, i,j,color);
            }
 
            xtoi = i-x+.5;
            ytoj = j-y+.5;
            dist = sqrt(pow(xtoi,2) + pow(ytoj,2));
            if(dist<r)
            {
                set_pixel(img, cols, rows, i,j,color);
            }
 
            xtoi = i-x+.5;
            ytoj = j-y-.5;
            dist = sqrt(pow(xtoi,2) + pow(ytoj,2));
            if(dist<r)
            {
                set_pixel(img, cols, rows, i,j,color);
            }
 
 
            xtoi = i-x-.5;
            ytoj = j-y+.5;
            dist = sqrt(pow(xtoi,2) + pow(ytoj,2));
            if(dist<r)
            {
                set_pixel(img, cols, rows, i,j,color);
            }
          } 
 
        }
    }
}
