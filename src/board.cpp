#include "board.hpp"
#include <iostream>

void Board::handleClick()
{
    bool nextTurn = false;
    for (auto &&pawn : pawns.allPawns)
    {
        if (!CheckCollisionPointRec(GetMousePosition(), pawn.getRect()))
            continue;

        if (pawn.isValidOnTurn(turn))
        {
            if (!pawn.isMoveable && dice == 6)
                pawn.spawn();

            else if (pawn.isMoveable)
                pawns.move(pawn, dice);
        }
    }
    turn++;
}

void Board::rollDice()
{
    // char keyboardInput;
    // std::cout << "Player" << turn << " enter 'r' to roll dice: ";

    // if(!IsKeyPressed(KeyboardKey::KEY_R)) {
    //     std::cout << std::endl << "Wrong Input" << std::endl;
    //     return;
    // }

    // Automatic Dice for Now
    if (isNextTurn)
    {
        dice = GetRandomValue(1, 6);
        std::cout << "Player" << turn << " Rolled a " << dice;
    }
}

void Board::init()
{
    cells.init();
    pawns.init();
}

void Board::handleInput()
{
    // Roll Dice
    // Click Pawn (if Pawn == Own Color)
    // Move Accordingly
    // Roll Dice Again

    if (!IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        return;

    handleClick();
    rollDice();
}

void Board::update() {}

void Board::render()
{
    cells.render();
    pawns.render();
}