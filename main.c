#include <stdio.h>
#include "raylib.h"
#include <stdint.h>

typedef enum
{
    position_bit,
    velocity,
    health_bit,
    sprite_bit,
} CompontentBit;

typedef enum
{
    skeleton_sprite,
    player_sprite,
} Sprite;

#define COMPONENT_SIZE 1024
#define SCREEN_WIDTH 840
#define SCREEN_HEIGHT 680

typedef struct
{

    Vector2 position[COMPONENT_SIZE];
    Vector2 velocity[COMPONENT_SIZE];
    uint32_t health[COMPONENT_SIZE];
    Sprite sprite[COMPONENT_SIZE];
    CompontentBit Archetype[COMPONENT_SIZE];
} Compontents;

int main()
{
    int screenWidth = SCREEN_WIDTH;
    int screenHeight = SCREEN_HEIGHT;

    uint32_t entity[COMPONENT_SIZE];
    uint32_t dead_entity[COMPONENT_SIZE];

    Compontents comps = {};


    InitWindow(screenWidth, screenHeight, "Zerg");
    InitAudioDevice();
    SetTargetFPS(60);
    Texture2D jumbly = LoadTexture("jumblysprite.png");
    Rectangle dim = {
        0,0,64,64,
    };

    Vector2 pos = {0.0f,0.0f};
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTextureRec(jumbly,dim,pos,WHITE);
        EndDrawing();
    }
    UnloadTexture(jumbly);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}