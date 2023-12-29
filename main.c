#include "raylib.h"

int main() {
    // Initialiser la fenêtre
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Projet TP ");

    // Initialiser le bouton
    Rectangle buttonBounds = { screenWidth / 2 -75 , screenHeight/4-150, 150, 70 };
    bool buttonPressed = false;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Mettre a jour la logique du bouton
        if (CheckCollisionPointRec(GetMousePosition(), buttonBounds) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            buttonPressed = true;
        } else {
            buttonPressed = false;
        }

        // Début du rendu
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Dessiner le bouton
        DrawRectangleRec(buttonBounds, buttonPressed ? DARKGRAY : BLACK);
        DrawText("trie ", (int)(buttonBounds.x + buttonBounds.width / 2 - MeasureText("trie", 20) / 2),
                 (int)(buttonBounds.y + buttonBounds.height / 2 - 10), 20, buttonPressed ? DARKGRAY : GRAY);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
