#include "board.hpp"

Pawns Board::pawns(LudoCells *cells) { return Pawns(); }

Board::Board() { init(); }

void Board::init()
{
    cells.init();
    pawns.init(&cells);
}

void Board::update() {}

void Board::render()
{
    cells.render();
    pawns.render();
}