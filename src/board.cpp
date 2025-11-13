#include "board.hpp"
#include <iostream>

void Board::handleClick()
{
    for (auto &&pawn : pawns.allPawns)
    {
        if (!CheckCollisionPointRec(GetMousePosition(), pawn.getRect()))
            continue;

        if (isPawnValid(pawn))

            if (!pawn.isMoveable && dice == 6)
                pawn.spawn();

            else if (pawn.isMoveable)
                pawns.move(pawn, dice);
    }
    turn++;
}

void Board::rollDice() {}

bool Board::isPawnValid(Pawn pawn)
{
    switch (turn) // clang-format off
    {
    case 1: if (pawn.getColor() == LUDO_RED   ) return true; else return false;
    case 2: if (pawn.getColor() == LUDO_GREEN ) return true; else return false;
    case 3: if (pawn.getColor() == LUDO_BLUE  ) return true; else return false;
    case 4: if (pawn.getColor() == LUDO_YELLOW) return true; else return false;

    default: return false;
    } // clang-format on
}

void Board::init()
{
    cells.init();
    pawns.init(&cells);
}

void Board::handleInput()
{
    // Roll Dice
    // Click Pawn (if Pawn == Own Color)
    // Move Accordingly
    // Roll Dice Again

    char keyboardInput;
    std::cout << "Player" << turn << " enter 'r' to roll dice: ";
    std::cin >> keyboardInput;
    if (keyboardInput == 'r' || keyboardInput == 'R')
    {
        rollDice();
    }
    else
    {
        std::cout << std::endl << "Wrong Input" << std::endl;
        return;
    }

    if (!IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        return;

    handleClick();
}

void Board::update() {}

void Board::render()
{
    cells.render();
    pawns.render();
}