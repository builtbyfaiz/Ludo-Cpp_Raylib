#include "board.hpp"
#include "ludoLogic.h"
#include "controller.h"

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