#include <stdio.h>
#include <stdlib.h>
#include "ml6.h"
#include "display.h"
#include "draw.h"
//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  //calculate slope
  int m = (y1-y0)/(x1-x);

  //Determine which octant the line is in
  ////Determine if the line is drawn left to right
  //////If yes, continue as is
  //////If not, switch endpoints
  ////Determine the octant out of I,II,VII, and VIII
  //////Octant 1
  if(0<m && m<1){

  }
  //////Octant 2
  else if(m>=1){

  }
  //////Octant VII
  else if(m>-1){

  }
  //////Octant VIII
  else{

  }
  //////////////////////Octant I/////////////////////////////
  int x, y, A, B,d;

  //initial values
  x = x0;
  y = y0;
  A = y1-y0;
  B = -(x1-x0);
  d = 2A + B;

  //get rid of floating point division
  A = 2A;
  B = 2B;

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
