
#include <raylib.h>

typedef struct Particle {
    Vector2 pos;
    Vector2 vel;
    float gravity;
}Particle;

void updatePosition() {
    
}

void accelerate() {
    
}
    
int main() {

    InitWindow(800, 600, "Particles");
    SetTargetFPS(60);

    while(!WindowShouldClose()) {

        BeginDrawing();

        ClearBackground(BLACK);
        
        DrawCircle(400, 100, 10, WHITE);

        EndDrawing();
    }
    CloseWindow();

    return 0;
}
