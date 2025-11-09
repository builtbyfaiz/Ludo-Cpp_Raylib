#include "pawn.hpp"
#include "ludoCell.hpp"
#include "mappingsPawns.hpp"

Pawn::Pawn(LudoCell *hC)
    : homeCell(hC), color(colorLegendPawns[hC->getHomeID()]), ID(hC->getHomeID())
{
    moveTo(homeCell);
}

void Pawn::update() {}

void Pawn::render() { rect.Draw(color); }

void Pawn::returnHome()
{
    distance = 0;
    moveTo(homeCell);
}

void Pawn::moveTo(LudoCell *nextCell)
{
    if (currentCell != nullptr)
        distance += nextCell->getPathID() - currentCell->getPathID();

    currentCell = nextCell;
    Vector2 newPos =
        currentCell->getRect().GetPosition() + ((currentCell->getRect().GetSize() - rect.GetSize()) / 2); // Gets Pos right in mid of cell

    rect.SetPosition(newPos); // sets pawns rect to middle of cells rect
}
