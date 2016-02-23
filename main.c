#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ml6.h"
#include "display.h"
#include "draw.h"
int main() {
  screen s;
  color c;
  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;
  clear_screen(s);

  int y1, y2, d, count;
  y1 = 0;
  y2 = YRES-1;
  d = 1;
  count = 1;
  while(y1<YRES){
    if(count%2 == 0){
      c.red = 0;
      c.green = MAX_COLOR;
    }else{
      c.red = MAX_COLOR;
      c.green = 0;
    }
    draw_line(0,y1,XRES-1,y1,s,c);
    draw_line(y1,0,y1,YRES-1,s,c);
    d = d * 2;
    y1 += d;
    count++;
  }
  d = 1;
  while(y2<YRES){
    if(count%2 == 0){
      c.red = 0;
      c.green = MAX_COLOR;
    }else{
      c.red = MAX_COLOR;
      c.green = 0;
    }
    draw_line(0,y2,XRES-1,y2,s,c);
    draw_line(y2,0,y2,YRES-1,s,c);
    d = d * 2;
    y2 -= d;
    count++;
  }
  c.red = 0;
  c.green = 0;
  c.blue = MAX_COLOR;
  draw_line(0,YRES/2,XRES-1,YRES/2,s,c);
  draw_line(XRES/2,0,XRES/2,YRES-1,s,c);
  draw_line(0,0,XRES-1,YRES-1,s,c);
  draw_line(0,YRES-1,XRES-1,0,s,c);
  draw_line(0,YRES/4,XRES-1,3*YRES/4,s,c);
  draw_line(0,3*YRES/4,XRES-1,YRES/4,s,c);
  draw_line(XRES/4,0,3*XRES/4,YRES-1,s,c);
  draw_line(3*XRES/4,0,XRES/4,YRES-1,s,c);

  //display(s);
  save_extension(s, "lines.png");
} 
