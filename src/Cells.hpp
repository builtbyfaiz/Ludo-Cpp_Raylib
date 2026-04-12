#pragma once
#include "Cell.hpp"

#include <vector>

//TODO rename to CellsManager
class Cells
{
  public:
    std::vector<std::vector<Cell>> grid; // 2D Vector, same as arr[][]
    // std::vector<std::vector<Cell>> pathCells; // 2D Vector, same as arr[][]

    Cells();

    void init();
    void render();
};