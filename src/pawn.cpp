#include "pawn.hpp"
#include "ludoCell.hpp"
#include "mappingsPawns.hpp"
#include <iostream>

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

// pawn.cpp
void Pawn::moveTo(LudoCell *cell)
{
    std::cout << "\nPawn's PositionX: "<< rect.GetPosition().x;
    std::cout << "\nPawn's PositionY: "<< rect.GetPosition().y;
    currentCell = cell;
    Vector2 newPos = currentCell->getRect().GetPosition() +
                     ((currentCell->getRect().GetSize() - rect.GetSize()) /
                      2); // Gets Pos right in mid of cell

    rect.SetPosition(newPos); // sets pawns rect to middle of cells rect
    std::cout << "\nPawn's New PositionX: "<< rect.GetPosition().x;
    std::cout << "\nPawn's New PositionY: "<< rect.GetPosition().y <<"\n";
}

void Pawn::spawn()
{
    moveTo(spawnCell);
    score = 1;
    isSpawned = true;
}
void Pawn::die()
{
    moveTo(homeCell);
    score = 0;
}

const raylib::Rectangle Pawn::getRect() { return rect; }

const raylib::Color Pawn::getColor() { return color; }

const bool Pawn::getState() { return isMoveable; }

const int Pawn::getScore() { return score; }
