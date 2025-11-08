#pragma once
#include "board.hpp"

class Game
{
    Board board;
    
    public:
    Game();
    ~Game();

    void run(); 
    void handleInput();
    void update();
    void render();
};
