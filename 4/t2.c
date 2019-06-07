#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
 
void draw_rectangle( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows, 
         int x,
         int y,
         int rect_width,
         int rect_height,
         uint8_t color )
{
    int i,j;
 
      if(rect_width>0 && rect_height >0)
      {
        for(i = x; i<x+rect_width; i++)
        {
          for(j = y; j < y+rect_height; j++)
          {
            if(i<cols && j<rows)
            {
 
              if(i==x || i == x+rect_width-1)
                  {
                      set_pixel(array, cols, rows, i,j,color);
                  } 
 
 
                  if(j == y || j == y+rect_height -1)
                  {
                    set_pixel(array, cols, rows, i,j,color);
                  }
            }
 
          }
        }
      }
 
      else if(rect_width<0 && rect_height>0)
      {
          for(i = x; i> x+rect_width; i--)
          {//checks columns
            for(j = y; j<y+rect_height; j++)
            {//checks rows
 
              if(i<cols && j<rows)
              {
                if(i==x || i == x+rect_width+1)
                {
                    set_pixel(array, cols, rows, i,j,color);
                  }
 
 
                  if(j == y || j == y+rect_height -1)
                  {
                    set_pixel(array, cols, rows, i,j,color);
                }
              }
 
            }
 
            }
        }
        else if(rect_width>0 && rect_height<0)
      {
        for(i = x; i< x+rect_width; i++)
          {//checks columns
            for(j = y; j>y+rect_height; j--)
            {//checks rows
                if(i<cols && j<rows)
                {
                  if(i==x || i == x+rect_width-1)
                  {
                    set_pixel(array, cols, rows, i,j,color);
                  }
 
                  if(j == y || j == y+rect_height +1)
                  {
                    set_pixel(array, cols, rows, i,j,color);
                  }
                }
 
              } 
 
            }      
 
        }
      else if(rect_width<0 && rect_height<0)
      {
          for(i = x; i> x+rect_width; i--)
          {//checks columns
            for(j = y; j>y+rect_height; j--)
            {//checks rows
 
              if(i<cols && j<rows)
              {
                if(i==x || i == x+rect_width+1)
                  {
                    set_pixel(array, cols, rows, i,j,color);
                  }
 
                  if(j == y || j == y+rect_height +1)
                {
                    set_pixel(array, cols, rows, i,j,color);
                  }
              }
 
            }
 
            }   
        }
 
 
 
}
