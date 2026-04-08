#pragma once
#include "Board.hpp"
#include "BoardController.h"

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
