#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <math.h>

#include "line.h"

#define WIDTH 240
#define HEIGHT 160
#define NODES 800

#define PI 3.14159265359

int main(){
  struct pic* p;

  p = calloc(sizeof(struct pic),1);

  drawLine(p,120,80,180,50,255,0,0); //Testing octant I
  drawLine(p,120,80,150,20,0,255,0); //Testing octant II
  drawLine(p,120,80,90,20,0,0,255); //Testing octant III
  drawLine(p,120,80,60,50,255,0,255); //Testing octant IV
  drawLine(p,120,80,60,110,0,255,255); //Testing octant V
  drawLine(p,120,80,90,140,255,255,0); //Testing octant VI
  drawLine(p,120,80,150,140,128,0,255); //Testing octant VII
  drawLine(p,120,80,180,110,255,128,0); //Testing octant VIII

  //Edge cases

  drawLine(p,120,80,180,80,255,255,255);
  drawLine(p,120,80,180,20,255,255,255);
  drawLine(p,120,80,120,20,255,255,255);
  drawLine(p,120,80,60,20,255,255,255);
  drawLine(p,120,80,60,80,255,255,255);
  drawLine(p,120,80,60,140,255,255,255);
  drawLine(p,120,80,120,140,255,255,255);
  drawLine(p,120,80,180,140,255,255,255);

  drawPic(p,"pic.ppm",WIDTH,HEIGHT);
  free(p);

  // int f;
  // int stat;
  //
  // int coords[NODES][2];
  // char name[32];
  // char exportName[32];
  // double current = 0;
  //
  // double step = (2 * PI) / NODES;
  // for(int x = 0; x < NODES; x++){
  //   coords[x][0] = round((WIDTH / 2) - ((WIDTH / 2) * cos(current)));
  //   coords[x][1] = round((HEIGHT / 2) - ((HEIGHT / 2) * sin(current)));
  //   //printf("%d %d\n", coords[x][0],coords[x][1]);
  //   current += step;
  // }
  //
  // for(int drawStep = 2; drawStep < 100; drawStep++){
  //   p = calloc(sizeof(struct pic),1);
  //
  //   for(int currentPoint = 0; currentPoint < NODES; currentPoint++){
  //     drawLine(p,coords[currentPoint][0],coords[currentPoint][1],coords[(currentPoint * drawStep) % NODES][0],coords[(currentPoint * drawStep) % NODES][1],255,255,255);
  //   }
  //   sprintf(name,"pic_%d.ppm",drawStep);
  //   sprintf(exportName, "pic_%d.png",drawStep);
  //
  //   drawPic(p, name);
  //
  //   free(p);
  //
  //   f = fork();
  //   if(f){
  //     waitpid(f, &stat, 0);
  //   } else {
  //     execlp("convert","convert", name, exportName, NULL);
  //   }
  //
  //   f = fork();
  //   if(f){
  //     waitpid(f, &stat, 0);
  //   } else {
  //     execlp("rm", "rm", name, NULL);
  //   }
  // }

  return 0;
}
