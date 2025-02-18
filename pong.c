#include <raylib.h>

#define height 600
#define width 800
int main(){
    InitWindow(width, height , "Ping Pong");
    SetTargetFPS(60);
    // pong ball x and y add if hit the ends return krni
int x = width / 2 , y = height/2;
int x1 = -3;
int y1 = -3;
int size = 10;
int slide_hight = 20;
int slide_X = 60;
int slide_X2 = 60;
int slide_width = 180;
while (!WindowShouldClose()){
    x += x1 ; 
    y += y1; 
    if (IsKeyDown(KEY_RIGHT)){
       if(slide_X < width - 180){
              slide_X += 5; 
    }
    }
    if (IsKeyDown(KEY_D)){
       if(slide_X2 < width - 180){
              slide_X2 += 5; 
    }
    }
    if (IsKeyDown(KEY_LEFT)){
       if(slide_X > 0){
              slide_X -= 5; 
    }
    }
    if (IsKeyDown(KEY_A)){
       if(slide_X2 > 0){
              slide_X2 -= 5; 
    }
    }
    if (x >= width - size || x <= size) {
        x1 *= -1;
    }
    if (y <= 30 && x >= slide_X2 && x <= slide_X2 + 180 || y >= height - 30 && x >= slide_X && x <= slide_X + 180){
        y1 *= -1;
    }
    if (y > height || y < 30 )
    {
        DrawText("Game Over " , width/4 , height/4 , 60 , RED);
        x = height + 60;
    }
    
    
    ClearBackground(WHITE);
    
    BeginDrawing();
    
    DrawCircle(x, y, size , PINK);
    DrawText("Green left=A Green right=D\n Left and Right arrow for red" , 10 , 40 ,20 , GRAY);
    DrawRectangle(slide_X , height - slide_hight, slide_width, slide_hight , RED);
    DrawRectangle(slide_X2 , 0, slide_width, slide_hight , GREEN);
   
   EndDrawing();
}
CloseWindow();
return 0;
}