#include "board.hpp"
#include <iostream>

void Board::handleClick()
{
    for (auto &pawn : pawns.allPawns)
    {
        // std::cout<<pawn.getColor().ToString()<<"\n";
        // std::cout<<pawn.getState()<<"\n";
        // std::cout<<pawn.getScore()<<"\n";
        // std::cout<<pawn.getRect().x<<"\n";

        if (!CheckCollisionPointRec(GetMousePosition(), pawn.getRect()))
            continue;

        std::cout<<"Collision with: "<<pawn.getRect().x;
        if (pawn.isValidOnTurn(turn))
        {
            std::cout<<"Pawn valid" <<pawn.getRect().x;
            std::cout<<"Pawn moveable" <<pawn.getState();

            if (!pawn.isMoveable && dice == 6) {
                pawn.spawn();
                // std::cout<<"spawn cell:" <<pawn.spawnCell->getRect().x;}
            }
            else if (pawn.isMoveable)
                pawns.move(pawn, dice);

            turn++;
            std::cout<<"turn";
        }
    }
    
}

void Board::autoRollDice()
{
    // char keyboardInput;
    // std::cout << "Player" << turn << " enter 'r' to roll dice: ";

    // if(!IsKeyPressed(KeyboardKey::KEY_R)) {
    //     std::cout << std::endl << "Wrong Input" << std::endl;
    //     return;
    // }

    if(isNextTurn)
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
    // Roll Dice on click
    // Click Pawn (if Pawn == Own Color)
    // Move Accordingly
    // Roll Dice Again

    if (!IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        return;

    handleClick();
}

void Board::update() {autoRollDice();}

void Board::render()
{
    cells.render();
    pawns.render();
}