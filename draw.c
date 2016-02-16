#include <stdio.h>
#include <stdlib.h>
#include "ml6.h"
#include "display.h"
#include "draw.h"
//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int octant = 0;
  int dx = x1-x0;
  int dy = y1-y0;

  //If the line is drawn right to left, switch the two endpoints
  if(dx<0){
    printf("\nendpoints switched\n");
    int tempX = x1;
    int tempY = y1;
    x1 = x0;
    y1 = y0;
    x0 = tempX;
    y0 = tempY;
    dx = x1-x0;
    dy = y1-y0;
  }


  //Determine which octant the line is in
  if(dy>0){
    if(dy<dx){
      octant = 1;
    }else{
      octant = 2;
    }
  }else{
    if(abs(dy)<abs(dx)){
      octant = 8;
    }else{
      octant = 7;
    }
  }

  if(octant == 1){
    //////////////////////Octant I////////////////////////////////
    int x, y, A, B,d;

    //initial values
    x = x0;
    y = y0;
    A = y1-y0;
    B = -(x1-x0);
    d = (2*A) + B;

    //get rid of floating point division
    A = 2*A;
    B = 2*B;

    while(x<=x1){
      plot(s,c,x,y);
      if(d>0){
	y+=1;
	d += B;
      }
      x += 1;
      d += A;
    }
    //////////////////////////////////////////////////////////////
  }
  else if(octant == 2){
    //////////////////////Octant II///////////////////////////////
    int x, y, A, B,d;

    //initial values
    x = x0;
    y = y0;
    A = y1-y0;
    B = -(x1-x0);
    d = A + (2*B);

    //get rid of floating points
    A = 2*A;
    B = 2*B;

    while(y <= y1){
      plot(s,c,x,y);
      if(d<0){
	x += 1;
        d += A;
      }
      y += 1;
      d += B;
    }
    ////////////////////////////////////////////////////////////////
  }
  else if(octant == 7){
    //////////////////////Octant VII//////////////////////////////
    int x, y, A, B,d;

    //initial values
    x = x0;
    y = y0;
    A = y1-y0;
    B = -(x1-x0);
    d = -A + (2*B);

    //get rid of floating points
    A = 2*A;
    B = 2*B;

    while(y >= y1){
      plot(s,c,x,y);
      if(d<0){
	x += 1;
        d -= A;
      }
      y -= 1;
      d += B;
    }
    ////////////////////////////////////////////////////////////////
  }
  else if(octant == 8){
    //////////////////////Octant VIII/////////////////////////////
    int x, y, A, B,d;

    //initial values
    x = x0;
    y = y0;
    A = y1-y0;
    B = -(x1-x0);
    d = (2*A) - B;

    //get rid of floating point division
    A = 2*A;
    B = 2*B;

    while(x<=x1){
      plot(s,c,x,y);
      if(d<0){
	y -= 1;
	d -= B;
      }
      x += 1;
      d += A;
    }
    //////////////////////////////////////////////////////////////
  }
}
