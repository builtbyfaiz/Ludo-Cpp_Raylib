#include "pawn.hpp"
#include "ludoCell.hpp"

Pawn::Pawn(LudoCell *hC)
    : homeCell(hC), ID(hC->getHomeID())
{
    moveTo(homeCell);
}

void Pawn::update() {}

void Pawn::render() { rect.Draw(color); }

void Pawn::returnHome() 
{
    score = 0;
    moveTo(homeCell);
}

void Pawn::exitHome() 
{
    score = 1;
    currentCell = spawnCell;
}

void Pawn::moveTo(LudoCell *nextCell) 
{
    if(currentCell!=nullptr)
        score += nextCell->getPathID() - currentCell->getPathID();
    currentCell = nextCell;
    Vector2 newPos = currentCell->getRect().GetPosition() + currentCell->getRect().GetSize()/2; // Gets Pos right in mid of cell
    rect.SetPosition(newPos); // sets pawns rect to middle of cells rect
}
