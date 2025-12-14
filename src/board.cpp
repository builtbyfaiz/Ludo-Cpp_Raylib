#include "board.hpp"
#include <iostream>

void Board::handleClick()
{
    for (auto &pawn : pawns.allPawns)
    {

        if (!CheckCollisionPointRec(GetMousePosition(), pawn.getRect()))
            continue;

        if (pawn.isValidOnTurn(turn))
        {
            if (!pawn.isSpawned && dice == 6)
            {
                pawn.spawn();
            }
            else if (pawn.isSpawned && pawn.isMoveable)
            {
                pawns.move(pawn, dice);
                std::cout << "Pawn Moved" << "\n";
            }

            if (dice != 6)
            {
                turn++;
                turn = (turn % 4);
            }

            // std::cout << "Dice:" << dice << "\n";
            // std::cout << "Turn: " << turn << "\n";
        }
    }
}

void Board::rollDiceSmart()
{
    // char keyboardInput;
    std::cout << "\nPlayer" << turn << " enter 'r' to roll dice: ";

    if (!IsKeyPressed(KeyboardKey::KEY_R))
    {
        std::cout << std::endl << "Wrong Input" << std::endl;
        return;
    }

    if (isNextTurn)
    {
        dice = GetRandomValue(1, 6);
        std::cout << "\nPlayer" << turn << " Rolled a " << dice;
    }
}

void Board::init()
{
    cells.init();
    pawns.init();
}

void Board::handleInput()
{
    // Roll Dice on click
    // Click Pawn (if Pawn == Own Color)
    // Move Accordingly
    // Roll Dice Again

    if (!IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        return;

    handleClick();
}

void Board::update()
{
    for (auto &pawn : pawns.allPawns)
    {
        if (pawn.isValidOnTurn(turn))
        {
            pawn.isMoveable = true;
            pawn.isKillable = false;
        }
        else{
            pawn.isMoveable = false;
            pawn.isKillable = true;
        }
    }
    // rollDiceSmart();

    for (auto &row : cells.cellsGrid) // Check Kills
    {
        for (auto &cell : row)
        {

        }
    }
}

void Board::render()
{
    cells.render();
    pawns.render();
}