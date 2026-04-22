#include "Pawn.hpp"

#include "Cell.hpp"
#include "PawnMaps.hpp"

// Pawn will always be initiated to a home Cell, Color is inferred from Cell.
Pawn::Pawn(Cell *hC) : homeCell(hC), color(pawnIdToColor[hC->getHomeID()]), ID(hC->getHomeID()) {}

// A function which translationally moves the pawn and centers on provided cell.
void Pawn::moveTo(Cell *cell)
{
    if (currentCell != nullptr)
        currentCell->removePawn(this);
    currentCell = cell;
    currentCell->addPawn(this);

    Vector2 newPos =
        currentCell->getRect().GetPosition() +
        ((currentCell->getRect().GetSize() - rect.GetSize()) / 2); // Gets Pos right in mid of cell

    rect.SetPosition(newPos); // sets pawns rect to middle of cells rect
}

void Pawn::spawn()
{
    moveTo(spawnCell);
    score = 1;
    spawned = true;
}

void Pawn::die()
{
    spawned = false;
    moveTo(homeCell);
    score = 0;
}

// Renders the pawn rectangle with outline outwards
void Pawn::renderWithOutline(raylib::Color outlineColor, float thickness)
{
    raylib::Rectangle rectToRender = rect;

    rectToRender.x -= thickness;
    rectToRender.y -= thickness;
    rectToRender.width += thickness * 2;
    rectToRender.height += thickness * 2;

    rectToRender.Draw(color);
    rectToRender.DrawLines(outlineColor, thickness);
}

// Base Getters
const int Pawn::getScore() { return score; }
const raylib::Color Pawn::getColor() { return color; }
const raylib::Rectangle Pawn::getRect() { return rect; }

// Outline Style Getters
bool Pawn::isHidden() { return hidden; }
bool Pawn::isSelected() { return selected; }
bool Pawn::isHighlighted() { return highlighted; }

// State Getters
bool Pawn::hasWon() { return won; }
bool Pawn::isSpawned() { return spawned; }

// Setter Methods
void Pawn::setColor(raylib::Color c) { this->color = c; }

// Outline Style Setters
void Pawn::hide()
{
    hidden = true;
    color.SetA(0); // Make Pawn transparent
}
void Pawn::unhide()
{
    hidden = false;
    color.SetA(255); // Make Pawn opaque
}

void Pawn::select() { selected = true; }
void Pawn::deselect() { selected = false; }

void Pawn::highlight() { highlighted = true; }
void Pawn::unhighlight() { highlighted = false; }