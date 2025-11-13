#include "pawn.hpp"
#include "ludoCell.hpp"
#include "mappingsPawns.hpp"

Pawn::Pawn(LudoCell *hC)
    : homeCell(hC), color(colorLegendPawns[hC->getHomeID()]),
      ID(hC->getHomeID())
{
    moveTo(homeCell);
}

void Pawn::update() {}

void Pawn::render() { rect.Draw(color); }

void Pawn::moveTo(LudoCell *nextCell)
{
    if (isMoveable)
    {
        score += nextCell->getPathID() - currentCell->getPathID();

        currentCell = nextCell;
        Vector2 newPos = currentCell->getRect().GetPosition() +
                         ((currentCell->getRect().GetSize() - rect.GetSize()) /
                          2); // Gets Pos right in mid of cell

        rect.SetPosition(newPos); // sets pawns rect to middle of cells rect
    }
}

void Pawn::spawn()
{
    moveTo(spawnCell);
    score = 1;
}
void Pawn::die()
{
    moveTo(homeCell);
    score = 0;
}

const raylib::Rectangle Pawn::getRect() { return rect; }

const raylib::Color Pawn::getColor() { return color; }
