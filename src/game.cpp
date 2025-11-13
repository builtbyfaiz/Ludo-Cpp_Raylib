#include "game.hpp"

// Game loop
void Game::run()
{
    while (!WindowShouldClose()) // Run the loop untill the user quits
    {
        handleInput();
        update();
        render();
    }
    CloseWindow(); // leaving this here till i figure how destructor of this works
}

void Game::handleInput() {
    
}

void Game::update() {}

void Game::render()
{
    BeginDrawing();
    ClearBackground(raylib::BLACK);

    board.render();

    EndDrawing();
}

Game::Game() {
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(750, 750, "Ludo");
    board.init();
}

Game::~Game() { CloseWindow(); }
