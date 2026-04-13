#include "Pawn.hpp"

#include "Cell.hpp"
#include "PawnMaps.hpp"

#include <iostream>

// Pawn will always be initiated to a home Cell, Color is inferred from Cell.
Pawn::Pawn(Cell *hC) : homeCell(hC), color(pawnIdToColor[hC->getHomeID()]), ID(hC->getHomeID())
{
    // moveTo(homeCell);
}

void Pawn::update() {}

void Pawn::setOutline(raylib::Color c, float thickness)
{
    outline.color = c;
    outline.thickness = thickness;
}

void Pawn::render()
{
    rect.Draw(color);
    rect.DrawLines(outline.color, outline.thickness);
}

// pawn.cpp
void Pawn::moveTo(Cell *cell)
{
    std::cout << "\nPawn's PositionX: " << rect.GetPosition().x;
    std::cout << "\nPawn's PositionY: " << rect.GetPosition().y;
    currentCell = cell;
    Vector2 newPos =
        currentCell->getRect().GetPosition() +
        ((currentCell->getRect().GetSize() - rect.GetSize()) / 2); // Gets Pos right in mid of cell

    rect.SetPosition(newPos); // sets pawns rect to middle of cells rect
    std::cout << "\nPawn's New PositionX: " << rect.GetPosition().x;
    std::cout << "\nPawn's New PositionY: " << rect.GetPosition().y << "\n";
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

const int Pawn::getScore() { return score; }
