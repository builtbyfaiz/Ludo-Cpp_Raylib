#include "Pawn.hpp"

#include "Cell.hpp"
#include "PawnMaps.hpp"

#include <iostream>

// Pawn will always be initiated to a home Cell, Color is inferred from Cell.
Pawn::Pawn(Cell *hC) : homeCell(hC), color(pawnIdToColor[hC->getHomeID()]), ID(hC->getHomeID())
{
    // moveTo(homeCell);
}

// void Pawn::setOutline(raylib::Color c, float thickness)
// {
//     outline.color = c;
//     outline.thickness = thickness;
// }

void Pawn::setColor(raylib::Color c) { this->color = c; }

// Renders the pawn rectangle with outline outwards
void Pawn::renderWithOutline(raylib::Color outlineColor, float thickness)
{
    raylib::Rectangle rectToRender = rect;

    rectToRender.x -= thickness;
    rectToRender.y -= thickness;
    rectToRender.width  += 2 * thickness;
    rectToRender.height += 2 * thickness;

    rectToRender.Draw(color);
    rectToRender.DrawLines(outlineColor, thickness);
}

// pawn.cpp
void Pawn::moveTo(Cell *cell)
{
    currentCell = cell;
    Vector2 newPos =
        currentCell->getRect().GetPosition() +
        ((currentCell->getRect().GetSize() - rect.GetSize()) / 2); // Gets Pos right in mid of cell

    rect.SetPosition(newPos); // sets pawns rect to middle of cells rect
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

// Base Getters

const int Pawn::getScore() { return score; }
const raylib::Color Pawn::getColor() { return color; }
const raylib::Rectangle Pawn::getRect() { return rect; }

// Style Setters

void Pawn::hide() { hidden = true; }
void Pawn::unhide() { hidden = false; }

void Pawn::select() { selected = true; }
void Pawn::deselect() { selected = false; }

void Pawn::highlight() { highlighted = true; }
void Pawn::unhighlight() { highlighted = false; }

// Style Getters

bool Pawn::isHidden() { return hidden; }
bool Pawn::isSelected() { return selected; }
bool Pawn::isHighlighted() { return highlighted; }