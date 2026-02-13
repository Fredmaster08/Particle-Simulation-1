
#include <raylib.h>
#include <stdio.h>

typedef struct Particle {
    Vector2 pos;
    Vector2 vel;
}Particle;

typedef struct {
    Vector2 current_position;
    Vector2 old_position;
    Vector2 acceleration
}

int main() {

    InitWindow(800, 600, "Particles");
    SetTargetFPS(60);

    int Particles = 100;


    while(!WindowShouldClose()) {

        BeginDrawing();

        ClearBackground(BLACK);
            
        
        
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
