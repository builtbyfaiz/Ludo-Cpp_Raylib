#include "Board.hpp"

Board::Board() {
    PawnsManager::bindToBoard(&cells, &pawns);
}

void Board::init()
{
    cells.init();
    PawnsManager::init();
}

void Board::render()
{
    cells.render();
    PawnsManager::renderPawns();
}