#include "Board.hpp"

void Board::init()
{
    cells.init();
    pawns.init();
}

void Board::render()
{
    cells.render();
    pawns.render();
}