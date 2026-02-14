
#include <raylib.h>
#include <stdlib.h>

typedef struct Particle {
    Vector2 pos;
    Vector2 vel;
}Particle;

void update_particles(Particle* particles, int particles_count, float dt) {
    for(int i = 0; i < particles_count; i++) {
        particles[i].pos.y += particles[i].vel.y * dt;
        particles[i].vel.y += 9.81;
    }

}

void draw_particles(Particle* particles, int particles_count) {
    for(int i = 0; i < particles_count; i++) {
        DrawCircle(particles[i].pos.x, particles[i].pos.y, 10.0f, WHITE);
    }
}

void add_particle(Particle** particles, int* particles_count, Particle p) {
    (*particles_count)++;
    *particles = realloc(*particles, sizeof(Particle) * *particles_count);
    (*particles)[*particles_count - 1] = p;
}

int main() {

    InitWindow(800, 600, "Particles");
    SetTargetFPS(60);
    int particles_count = 1;
    Particle* particles = calloc(particles_count, sizeof(Particle));

    while(!WindowShouldClose()) {
        
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Particle p = {
                .pos = GetMousePosition(),
                .vel = {0, 0},
            };
            add_particle(&particles, &particles_count, p);
        }

        update_particles(particles, particles_count, GetFrameTime());

        BeginDrawing();

        ClearBackground(BLACK);
    
        draw_particles(particles, particles_count);

        EndDrawing();
    }
    free(particles);
    CloseWindow();

    return 0;
}
