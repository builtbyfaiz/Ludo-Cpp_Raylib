#include "game.hpp"

// Game has Dice as well as the Board and Players #TODO add Dice, players
void Game::handleInput() { board.handleInput(); }

void Game::update() { board.update(); }

void Game::render()
{
    BeginDrawing();
    ClearBackground(raylib::BLACK);

    board.render();

    EndDrawing();
}

Game::Game()
{
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(750, 750, "Ludo");
    board.init();
}

Game::~Game() { CloseWindow(); }
