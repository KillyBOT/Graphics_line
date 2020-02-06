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

void drawLine(struct pic* p, int x1, int y1, int x2, int y2, int r, int g, int b);
void drawPic(struct pic* p, char* fileName);

int main(){
  struct pic* p = malloc(sizeof(struct pic));

  drawLine(p,100,80,140,110,255,0,0); //Testing octant I
  drawLine(p,100,80,140,130,0,255,0); //Testing octant II
  drawLine(p,100,80,140,50,0,0,255); //Testing octant VIII
  drawLine(p,100,80,140,30,255,0,255); //Testing octant VII

  drawPic(p, "pic.ppm");

  return 0;
}

void drawLine(struct pic* p, int x1, int y1, int x2, int y2, int r, int g,int b){
  int dx = x2 - x1;
  int dy = y2 - y1;
  double m = (double)dy/(double)dx;
  struct color c;

  c.r = r;
  c.g = g;
  c.b = b;

  int A = dy;
  int B = -dx;
  int x = x1;
  int y = y1;
  int d;

  printf("%f\n", m);

  if(dx > 0){
    if(m > 0 && m <= 1){ //In octant I
      printf("Octant I\n");
      d = (2 * A) + B;

      while(x <= x2){
        p->data[y][x] = c;

        if(d > 0){
          y++;
          d += (2 * B);
        }
        x++;
        d += 2 * A;
      }
    }
    if(m > 1){ //In octant II
      printf("Octant II\n");
      d = A + (2 * B);

      while(y <= y2){
        p->data[y][x] = c;

        if(d <= 0){
          x++;
          d += (2 * A);
        }
        y++;
        d += (2 * B);
      }
    }
    if(m < 0 && m >= -1){ //In octant VIII
      printf("Octant VIII\n");
      d = (2 * A) - B;

      while(x <= x2){
        p->data[y][x] = c;

        if(d <= 0){
          y--;
          d -= (2 * B);
        }
        x++;
        d += (2 * A);
      }
    }
    if(m < -1){
      printf("Octant VII\n");
      d = A - (2 * B);

      while( y >= y2){
        p->data[y][x] = c;

        if(d > 0){
          x++;
          d += (2 * A);
        }
        y--;
        d -= (2 * B);
      }
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
