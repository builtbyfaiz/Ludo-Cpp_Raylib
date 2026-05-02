#pragma once
#include "Cell.hpp"

#include <vector>

//TODO rename to CellsManager
class Cells
{
  public:
    const int GRID_SIZE = 15;
    std::vector<std::vector<Cell>> grid; // 2D Vector, same as arr[][]
    
    void init();
    void render();
};