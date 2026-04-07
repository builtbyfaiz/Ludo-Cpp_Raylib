#pragma once
#include "board.hpp"
#include "controller.h"

class Game {
  public:
    Board board;
    BoardController controller;
    
    Game();
    ~Game();

    void handleInput();
    void update();
    void render();
};
