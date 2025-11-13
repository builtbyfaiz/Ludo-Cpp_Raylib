#pragma once
#include "board.hpp"

class Game {
  public:
    Board board;
    // Player player1;
    // player2;
    // player3;
    // player4;
    Game();
    ~Game();

    void run();
    void handleInput();
    void update();
    void render();
};
