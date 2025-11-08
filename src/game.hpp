#pragma once
#include "board.hpp"

class Game
{
    public:

    Board board;
    
    Game();
    ~Game();

    void run(); 
    void handleInput();
    void update();
    void render();
};
