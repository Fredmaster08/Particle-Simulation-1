
#include <raylib.h>
#include <stdio.h>

typedef struct Particle {
    Vector2 pos;
    Vector2 vel;
}Particle;

typedef struct verletObject {
    Vector2 current_position;
    Vector2 old_position;
    Vector2 acceleration
}verletObject;

typedef struct Solver {
    
}

void updatePosition(float dt) {
    const Vector2 velocity = current_position - old_position;
    // saving current pos
    old_position = current_position;
    current_position = current_position + velocity + acceleration * dt * dt;
    acceleration = {};
}

void accelerate(Vector2 acc) {
    acceleration += acc;
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
