#include "board.hpp"

void Board::init()
{
    cells.init();
    pawns.init(cells);
}

void Board::update() {}

void Board::render() { cells.render(); }