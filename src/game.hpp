#pragma once
#include "board.hpp"
#include "controller.h"

class Game {
  public:
    Board board;
    BoardController controller;
    // Player player1;
    // player2;
    // player3;
    // player4;
    Game();
    ~Game();

    void handleInput();
    void update();
    void render();
};
