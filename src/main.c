#include "raylib.h"
#include "../include/about.h"
#include "../include/raygui.h"
typedef enum {
    MENU_START,
    MENU_ABOUT,
    MENU_SETTINGS,
    MENU_EXIT,
    MENU_NONE
} MenuOption;

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "raylib - меню");

    SetTargetFPS(60);

    MenuOption selectedOption = MENU_NONE;
    MenuOption hoveredOption = MENU_NONE;
    
        while (!WindowShouldClose())    
    {
        Vector2 mousePoint = GetMousePosition();
        
        hoveredOption = MENU_NONE;

        if (CheckCollisionPointRec(mousePoint, (Rectangle){ screenWidth/2 - 50, 120, 100, 40 })) {
            hoveredOption = MENU_START;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) selectedOption = MENU_START;
        } else if (CheckCollisionPointRec(mousePoint, (Rectangle){ screenWidth/2 - 50, 180, 100, 40 })) {
            hoveredOption = MENU_ABOUT;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) selectedOption = MENU_ABOUT;
        } else if (CheckCollisionPointRec(mousePoint, (Rectangle){ screenWidth/2 - 50, 240, 100, 40 })) {
            hoveredOption = MENU_SETTINGS;
            if ((MOUSE_LEFT_BUTTON)) selectedOption = MENU_SETTINGS;
        } else if (CheckCollisionPointRec(mousePoint, (Rectangle){ screenWidth/2 - 50, 300, 100, 40 })) {
            hoveredOption = MENU_EXIT;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) selectedOption = MENU_EXIT;
        }

        if (selectedOption == MENU_START) {
     
        } else if (selectedOption == MENU_ABOUT) {
            about_us();
        } else if (selectedOption == MENU_SETTINGS) {
 
        } else if (selectedOption == MENU_EXIT) {
            break;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Main Menu", screenWidth/2 - MeasureText("Main Menu", 40)/2, 40, 40, DARKGRAY);

        DrawRectangle(screenWidth/2 - 50, 120, 100, 40, LIGHTGRAY);
        DrawRectangle(screenWidth/2 - 50, 180, 100, 40, LIGHTGRAY);
        DrawRectangle(screenWidth/2 - 50, 240, 100, 40, LIGHTGRAY);
        DrawRectangle(screenWidth/2 - 50, 300, 100, 40, LIGHTGRAY);

        DrawText("Start", screenWidth/2 - MeasureText("Start", 20)/2, 130, 20, hoveredOption == MENU_START ? RED : BLACK);
        DrawText("About", screenWidth/2 - MeasureText("About", 20)/2, 190, 20, hoveredOption == MENU_ABOUT ? RED : BLACK);
        DrawText("Settings", screenWidth/2 - MeasureText("Settings", 20)/2, 250, 20, hoveredOption == MENU_SETTINGS ? RED : BLACK);
        DrawText("Exit", screenWidth/2 - MeasureText("Exit", 20)/2, 310, 20, hoveredOption == MENU_EXIT ? RED : BLACK);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}