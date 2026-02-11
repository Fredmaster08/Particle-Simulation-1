
#include <raylib.h>
#include <stdio.h>

int main() {

    InitWindow(800, 600, "Particles");
    SetTargetFPS(60);

    int Particles = 100;

    while(!WindowShouldClose()) {

        BeginDrawing();

        ClearBackground(BLACK);
            
        for(int i = 10; i < Particles; i++){
           int gap = 10; 
            DrawCircle(20 + gap, 20, 10, WHITE);
            
        }
        
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
