#pragma once
#include "ludoCell.hpp"
#include <vector>

class LudoCells
{
  public:
  std::vector<std::vector<LudoCell>> cellsGrid; // 2D Vector, same as arr[][]
  std::vector<std::vector<LudoCell>> pathCells; // 2D Vector, same as arr[][]
  
    LudoCells();

    void init();
    void render();
    void next();
};