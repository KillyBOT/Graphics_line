#include <stdio.h>

#include "line.h"

void drawLine(struct pic* p, int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b){
  int dx, dy, xi, yi, xf, yf, A, B, d;
  double m;
  struct color c;

  c.r = r;
  c.g = g;
  c.b = b;

  if(x2 < x1){
    xi = x2;
    yi = y2;
    xf = x1;
    yf = y1;
  } else {
    xi = x1;
    yi = y1;
    xf = x2;
    yf = y2;
  }

  //printf("From (%d,%d) to (%d,%d)\n", xi,yi,xf,yf);

  dx = xf - xi;
  dy = yf - yi;

  A = dy;
  B = -dx;

  //printf("dx: %d dy %d\n", dx,dy);

  if(dy >= 0 && dx >= dy){ //In octant I
    //printf("Octant I\n");
    d = (2 * A) + B;

    while(xi <= xf){
      p->data[yi][xi] = c;

      if(d > 0){
        yi++;
        d += (2 * B);
      }
      xi++;
      d += 2 * A;
    }
  }
  else if(dy >= 0 && dx < dy){ //In octant II
    //printf("Octant II\n");
    d = A + (2 * B);

    while(yi <= yf){
      p->data[yi][xi] = c;

      if(d <= 0){
        xi++;
        d += (2 * A);
      }
      yi++;
      d += (2 * B);
    }
  }
  else if(dy < 0 && dx >= (dy * -1)){ //In octant VIII
    //printf("Octant VIII\n");
    d = (2 * A) - B;

    while(xi <= xf){
      p->data[yi][xi] = c;

      if(d <= 0){
        yi--;
        d -= (2 * B);
      }
      xi++;
      d += (2 * A);
    }
  }
  else if(dy < 0 && dx < (dy * -1)){
    //printf("Octant VII\n");
    d = A - (2 * B);

    while( yi >= yf){
      p->data[yi][xi] = c;

      if(d > 0){
        xi++;
        d += (2 * A);
      }
      yi--;
      d -= (2 * B);
    }
  }
}

void drawPic(struct pic* p, char* fileName, int width, int height){

  struct color pixel;

  FILE* f = fopen(fileName, "w+");

  fprintf(f, "P3 %d %d 255 ", width, height);
  for(int y = 0; y < height; y++){
    for(int x = 0; x < width; x++){
      pixel = p->data[y][x];
      if(pixel.r > 0 || pixel.g > 0 || pixel.b > 0){
        fprintf(f, "%d %d %d ",pixel.r,pixel.g, pixel.b);
      } else {
        fprintf(f, "0 0 0 ");
      }
    }
  }

  fclose(f);
}
