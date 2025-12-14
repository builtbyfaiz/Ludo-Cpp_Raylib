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

void Pawn::render()
{
    rect.Draw(color);
    rect.DrawLines(BLACK, 2);
}

bool Pawn::isValidOnTurn(int turn)
{
    switch (turn) // clang-format off
    {
    case 1: if (color == LUDO_RED   ) return true; else return false;
    case 2: if (color == LUDO_GREEN ) return true; else return false;
    case 3: if (color == LUDO_BLUE  ) return true; else return false;
    case 4: if (color == LUDO_YELLOW) return true; else return false;

    default: return false;
    } // clang-format on
}

// pawn.cpp
void Pawn::moveTo(LudoCell *nextCell)
{
    if (isMoveable && currentCell != nullptr)
        score += nextCell->getPathID() - currentCell->getPathID();

    currentCell = nextCell;
    Vector2 newPos = currentCell->getRect().GetPosition() +
                     ((currentCell->getRect().GetSize() - rect.GetSize()) /
                      2); // Gets Pos right in mid of cell

    rect.SetPosition(newPos); // sets pawns rect to middle of cells rect
    isMoveable = false;
}

void Pawn::spawn()
{
    moveTo(spawnCell);
    score = 1;
    isMoveable = true;
}
void Pawn::die()
{
    moveTo(homeCell);
    score = 0;
}

const raylib::Rectangle Pawn::getRect() { return rect; }

const raylib::Color Pawn::getColor() { return color; }

const bool Pawn::getState() { return isMoveable; }
