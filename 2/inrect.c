#include <stdio.h> 

int InRectangle( float pt[2], float rect[4] )
{
    float x=pt[0];
    float y=pt[1];
    float box_x=rect[0];
    float box_y=rect[1];
    float box_x_opp=rect[2];
    float box_y_opp=rect[3];
    float x_diff=0;
    float y_diff=0;

    x_diff = box_x_opp - box_x ;
    y_diff = box_y_opp - box_y;

    //if x_diff is + and y diff is + 
    if (x_diff>=0  && y_diff>=0)
    {
        if ((x >= box_x) && (x <= box_x_opp) && (y>=box_y) && (y<=box_y_opp))
            {return 1;} 
    }
    //if x_diff is - and y diff is -

    if (x_diff<0  && y_diff<0)
    {
        if ((x <= box_x) && (x >= box_x_opp) && (y <=box_y) && (y >= box_y_opp))
            {return 1;} 
    }
    //if x_diff is + and y diff is -

    if (x_diff>=0  && y_diff<0)
    {
        if ((x >= box_x) && (x <= box_x_opp) && (y<=box_y) && (y>=box_y_opp))
            {return 1;} 
    }
    //if x_diff is - and y diff is +
    if (x_diff<0  && y_diff>=0)
    {
        if ((x <= box_x) && (x >= box_x_opp) && (y>=box_y) && (y<=box_y_opp))
            {return 1;} 
    }
    else 
        {return 0;}
}
