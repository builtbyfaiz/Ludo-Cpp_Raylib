#include "Board.hpp"

#include "PawnsManager.hpp"

Board::Board() { PawnsManager::bindToBoard(&cells, &pawns); }

void Board::init()
{
    cells.init();
    PawnsManager::initPawns();
}

void Board::render()
{
    cells.render();
    PawnsManager::renderPawns();
}