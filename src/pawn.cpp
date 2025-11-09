#include "pawn.hpp"
#include "ludoCell.hpp"

void Pawn::update()
{
    
}

void Pawn::render() { rect.Draw(color); }

void Pawn::returnHome() 
{
    score = 0;
    currentCell = homeCell; // 4 Home Cells. identified via ID, each pawn gets its own Cell
}

void Pawn::exitHome() 
{
    score = 1;
    currentCell = spawnCell;
}

void Pawn::moveTo(LudoCell *nextCell) {
    currentCell = nextCell;
    Vector2 newPos = currentCell->getRect().GetPosition() + currentCell->getRect().GetSize()/2; // Gets Pos right in mid of cell
    rect.SetPosition(newPos); // sets pawns rect to middle of cells rect
}
