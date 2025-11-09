#include "pawn.hpp"
#include "ludoCell.hpp"

void Pawn::render() { rect.Draw(color); }

void Pawn::moveTo(LudoCell &nextCell) {
    currentCell = nextCell;
}
