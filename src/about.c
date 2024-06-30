#include "raylib.h"
#include "../include/about.h"

void about_us(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawText("About Us", screenWidth / 2 - MeasureText("About Us", 40) / 2, screenHeight / 2 - 20, 40, DARKGRAY);
    DrawText("Press [ESC] to return to menu", screenWidth / 2 - MeasureText("Press [ESC] to return to menu", 20) / 2, screenHeight - 60, 20, DARKGRAY);

    EndDrawing();
}
