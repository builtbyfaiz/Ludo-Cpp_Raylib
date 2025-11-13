#include "board.hpp"
#include <iostream>

void Board::init()
{
    cells.init();
    pawns.init(&cells);
}

void Board::handleInput()
{
    int turn = 1;
    std::cout << "sup nigga, dis built by faiz";
    for (size_t turn = 1; turn < 5; turn++)
    {
        int dice = GetRandomValue(1, 6);
        std::cout << "Player" << turn << "You Rolled: " << dice << std::endl;
        turn = turn > 4 ? 1 : turn;
    }

    raylib::Color playerColor;
    switch (turn) // clang-format off
    {
    case 1: playerColor = LUDO_RED;    break;
    case 2: playerColor = GREEN;  break;
    case 3: playerColor = BLUE;   break;
    case 4: playerColor = YELLOW; break;

    default:
        turn = 1;
        std::cout << "something went wrong with turn var";
        break;
    } // clang-format on
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 mousePos = GetMousePosition();
        for (auto &pawn : pawns.allPawns)
        {
            if (CheckCollisionPointRec(mousePos, pawn.getRect()))
            {
                switch (turn)
                {
                case 1:
                    playerColor = RED;
                    // if(dice==6)
                    // if(pawn.getColor()==RED&&!pawn.isMoveable) pawn.distance += dice;
                    break;
                case 2:
                    playerColor = GREEN;
                    break;
                case 3:
                    playerColor = BLUE;
                    break;
                case 4:
                    playerColor = YELLOW;
                    break;
                }
            }
        }
    }
}
void Board::update() {}

void Board::render()
{
    cells.render();
    pawns.render();
}