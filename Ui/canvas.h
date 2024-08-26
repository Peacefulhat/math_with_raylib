#ifndef CANVAS_H
#define CANVAS_H
#define PI 3.14159265
#define WIDTH 450
#define HEIGHT 450 
#include<raylib.h>
#include<stdio.h>
#include<math.h>
#include<unistd.h>
typedef struct {
  int x,y;
}point;
void basicTrig(float angle);// basic trigonometric wave form
void animateCircle();// animating using trigonometric function.
void animateCircleShrink();// circle shrink uhshrink animation.
void animateCircleCircular(float speed,float speed2);
#endif // !CANVAS_H
