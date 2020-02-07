#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 240
#define HEIGHT 160

struct color{
  unsigned char r;
  unsigned char g;
  unsigned char b;
};

struct pic{
  struct color data[HEIGHT][WIDTH];
};

void drawLine(struct pic* p, int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b);
void drawPic(struct pic* p, char* fileName);

int main(){
  struct pic* p = malloc(sizeof(struct pic));

  drawLine(p,120,80,160,50,255,0,0); //Testing octant I
  drawLine(p,120,80,160,30,0,255,0); //Testing octant II
  drawLine(p,120,80,80,30,0,0,255); //Testing octant III
  drawLine(p,120,80,80,50,255,0,255); //Testing octant IV
  drawLine(p,120,80,80,110,0,255,255); //Testing octant V
  drawLine(p,120,80,80,130,255,255,0); //Testing octant VI
  drawLine(p,120,80,160,130,255,255,255); //Testing octant VII
  drawLine(p,120,80,160,110,128,128,128); //Testing octant VIII

  drawPic(p, "pic.ppm");

  return 0;
}

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

  printf("From (%d,%d) to (%d,%d)\n", xi,yi,xf,yf);

  dx = xf - xi;
  dy = yf - yi;

  A = dy;
  B = -dx;

  m = (double)dy/(double)dx;

  //printf("%f\n", m);

  if(m > 0 && m <= 1){ //In octant I
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
  if(m > 1){ //In octant II
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
  if(m < 0 && m >= -1){ //In octant VIII
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
  if(m < -1){
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

void drawPic(struct pic* p, char* fileName){

  struct color pixel;

  FILE* f = fopen(fileName, "w+");

  fprintf(f, "P3 %d %d 255 ", WIDTH, HEIGHT);
  for(int y = 0; y < HEIGHT; y++){
    for(int x = 0; x < WIDTH; x++){
      pixel = p->data[y][x];
      if(pixel.r > 0 || pixel.g > 0 || pixel.b > 0){
        fprintf(f, "%d %d %d ",pixel.r,pixel.g, pixel.b);
      } else {
        fprintf(f, "0 0 0 ");
      }
    }
  }
}
