#include"canvas.h"
#define SCALEFACTOR 60

Color colorArray[] = {
  RED,          
  GREEN,        
  BLUE,         
  YELLOW,       
  ORANGE,       
  PINK,         
  PURPLE,       
  SKYBLUE,      
  LIME,         
  VIOLET        
};

void basicTrig(float angle){
  char TextBuffer[100];  
  for(;angle<=2*PI;angle+=0.01){
    int y=-sinf(angle)*SCALEFACTOR;// sine of angle * scale fact
    int x=angle*SCALEFACTOR; // angle * sacle factor
    DrawPixel(x,y+(HEIGHT/2),GREEN);
  }
  return;
  
}

void animateCircle() {
  InitWindow(WIDTH,HEIGHT,"mywin");
  const int cx = WIDTH / 2;
  const int cy = HEIGHT / 2;
  float speed = 0.03f; 
  const float offset = HEIGHT*0.3;
  float angle = 0.02f;
  int i=0;
  while (!WindowShouldClose()) {
    point p;
    p.x=cx;//(cx+offset)-i;
    p.y=cy+(sinf(angle))*offset; 
    
    if (angle > 2 * PI) {
      angle =0.0f;
      // Keep angle in range [0, 2π)
    }
    if(p.x<=0){
      p.x=cx+sinf(offset);
      angle=0;
      i=0;
    }
    i+=1; 
    angle+=speed;
    usleep(10000); // 10 milliseconds (adjust as needed)
    BeginDrawing();
    ClearBackground(BLACK);
    DrawCircle(p.x, p.y,20, WHITE);
    EndDrawing();
  }
}

void animateCircleShrink(){
  InitWindow(WIDTH,HEIGHT,"mywin");
  const int cx = WIDTH / 2;
  const int cy = HEIGHT / 2;
  float speed = 0.03f; 
  const float offset = HEIGHT*0.1;
  float angle = 0.01f;
  int i=0;
  while (!WindowShouldClose()) {
    int radius=(cy/3)+(sinf(angle))*offset; 
    angle+=speed;
    usleep(10000); // 10 milliseconds (adjust as needed)
    BeginDrawing();
    ClearBackground(BLACK);
    DrawCircle(cx, cy,radius, WHITE);
    EndDrawing();
  }
}

void animateCircleCircular(float speed, float speed2) {
  InitWindow(WIDTH, HEIGHT, "mywin");
  SetTargetFPS(60); // Set the target FPS for smoother animation

  const int cx = WIDTH / 2;
  const int cy = HEIGHT / 2;
  float angle = 0.0f;
  float angle2 = 0.0f;
  int j = 40;

  while (!WindowShouldClose()) {
    // Update angles and positions
    angle += speed;
    angle2 += speed2;

    if (angle > 2 * PI) angle =0.01f;
    if (angle2 > 2 * PI) angle2 = 0.01f;
    // Update positions of circles
    
    point pv[10],pv2[10],pv3[10],pv4[10];
    for (int i = 0; i < 10; i++) {
      pv[i].x =  (j+30) * sinf(angle + i * (2 * PI / 10)) + cx;
      pv[i].y = (j+30) * cosf(angle2 + i * (2 * PI / 10)) + cy;
    }
    
    for (int i = 0; i < 10; i++) {
      pv2[i].x =  (j+120) * sinf(angle + i * (2 * PI / 10)) + cx;
      pv2[i].y = (j+120) * cosf(angle2 + i * (2 * PI / 10)) + cy;
    }
    
    for (int i = 0; i < 10; i++) {
      pv3[i].x =  (j+60) * sinf(angle + i * (2 * PI / 10)) + cx;
      pv3[i].y = (j+60) * cosf(angle2 + i * (2 * PI / 10)) + cy;
    }
    
    for (int i = 0; i < 10; i++) {
      pv4[i].x =  (j+90) * sinf(angle + i * (2 * PI / 10)) + cx;
      pv4[i].y = (j+90) * cosf(angle + i * (2 * PI / 10)) + cy;
    }
    
    // Clear the screen and draw all circles
    BeginDrawing();
    ClearBackground(BLACK);
    for (int i = 0; i < 10; i++) {
      DrawCircle(pv2[i].x,pv2[i].y,20,colorArray[i]);
      DrawCircle(pv3[i].x, pv3[i].y,20, colorArray[i]);
      DrawCircle(pv4[i].x,pv4[i].y,20,colorArray[i]);
      DrawCircle(pv[i].x, pv[i].y,20, colorArray[i]);
    }
    EndDrawing();

    // Adjust the delay to control the speed of animation
    //usleep(10000); // 10 milliseconds (adjust as needed)
  }
  
  CloseWindow(); // Close the window and OpenGL context
}
