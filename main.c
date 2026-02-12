
#include <raylib.h>
#include <stdio.h>

typedef struct Particle {
    Vector2 pos;
    Vector2 vel;
}Particle;

int main() {

    InitWindow(800, 600, "Particles");
    SetTargetFPS(60);

    int Particles = 100;
    //int randomValue = GetRandomValue(10, 100);

    while(!WindowShouldClose()) {

        BeginDrawing();

        ClearBackground(BLACK);
            
        for(int i = 0; i < Particles; i++){
            DrawCircle(30 * i, 20, 10, WHITE);
            
        }
        
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
