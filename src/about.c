// about.c

#include "raylib.h"
#include "../include/raylib.h"
bool about_us(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("About Us", screenWidth / 2 - MeasureText("About Us", 40) / 2, screenHeight / 2 - 20, 40, DARKGRAY);
        DrawText("Press [ESC] to return to menu", screenWidth / 2 - MeasureText("Press [ESC] to return to menu", 20) / 2, screenHeight - 60, 20, DARKGRAY);

        EndDrawing();

        if (IsKeyPressed(KEY_ESCAPE))
            return true; 
            
            // Возвращаем true, если пользователь нажал ESC
    }

    return false; // Если окно закрыто, возвращаем false
}
