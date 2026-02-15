
#include <raylib.h>
#include <stdlib.h>
#include <raymath.h>

typedef struct Particle {
    Vector2 pos_curr;
    Vector2 pos_old;
    Vector2 acc;
}Particle;

void update_particles(Particle* particles, int particles_count, float dt) {
    for(int i = 0; i < particles_count; i++) {
        particles[i].acc = (Vector2){0, 1000.0f};
        Vector2 velocity = Vector2Subtract(particles[i].pos_curr, particles[i].pos_old);
        particles[i].pos_old = particles[i].pos_curr;
        particles[i].pos_curr = Vector2Add(particles[i].pos_curr, Vector2Add(velocity, Vector2Scale(particles[i].acc, dt * dt)));
        particles[i].acc = (Vector2){0};
    }

}

void draw_particles(Particle* particles, int particles_count) {
    for(int i = 0; i < particles_count - 1; i++) {
 //       DrawCircle(particles[i].pos_curr.x, particles[i].pos_curr.y, 10.0f, WHITE);
        DrawLineV(particles[i].pos_curr, particles[i + 1].pos_curr, WHITE);
    }
}

void add_particle(Particle** particles, int* particles_count, Particle p) {
    (*particles_count)++;
    *particles = realloc(*particles, sizeof(Particle) * *particles_count);
    (*particles)[*particles_count - 1] = p;
}

int main() {

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "Particles");
    SetTargetFPS(60);
    int particles_count = 1;
    Particle* particles = calloc(particles_count, sizeof(Particle));

    while(!WindowShouldClose()) {
        
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            Particle p = {
                .pos_curr = GetMousePosition(),
                .pos_old = p.pos_curr,
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
