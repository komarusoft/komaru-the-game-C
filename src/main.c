#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "../include/raygui.h"
#include "../include/about.h"

typedef enum {
    MENU_NONE,
    MENU_START,
    MENU_ABOUT,
    MENU_SETTINGS,
    MENU_EXIT
} MenuOption;

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "raylib - меню");

    SetTargetFPS(60);

    MenuOption selectedOption = MENU_NONE;
    
    while (!WindowShouldClose())    
    {
        if (selectedOption == MENU_NONE || selectedOption == MENU_START || selectedOption == MENU_SETTINGS || selectedOption == MENU_EXIT) {
            BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawText("Main Menu", screenWidth / 2 - MeasureText("Main Menu", 40) / 2, 40, 40, DARKGRAY);

            if (GuiButton((Rectangle){ screenWidth / 2 - 50, 120, 100, 40 }, "Start")) {
                selectedOption = MENU_START;
            }
            if (GuiButton((Rectangle){ screenWidth / 2 - 50, 180, 100, 40 }, "About")) {
                selectedOption = MENU_ABOUT;
            }
            if (GuiButton((Rectangle){ screenWidth / 2 - 50, 240, 100, 40 }, "Settings")) {
                selectedOption = MENU_SETTINGS;
            }
            if (GuiButton((Rectangle){ screenWidth / 2 - 50, 300, 100, 40 }, "Exit")) {
                selectedOption = MENU_EXIT;
            }

            EndDrawing();
        } else if (selectedOption == MENU_ABOUT) {
            about_us();
            if (IsKeyPressed(KEY_ESCAPE)) {
                selectedOption = MENU_NONE;
            }
        }

        if (selectedOption == MENU_EXIT) {
            break;
        }
    }

    CloseWindow();

    return 0;
}
