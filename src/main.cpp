#include "game.hpp"

int main()
{
    Game ludo;  //Create one instance of the ludo game

    while (!WindowShouldClose()) // Run the loop untill the user quits
    {
        ludo.handleInput();
        ludo.update();
        ludo.render();
    }
    CloseWindow();

    return 0;
}
