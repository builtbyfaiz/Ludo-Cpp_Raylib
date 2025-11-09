#pragma once
#include "globals.hpp"
#include "ludoCell.hpp"
#include "raylib-cpp.hpp"
#include <vector>


class LudoCells
{
  public:
    std::vector<std::vector<LudoCell>> cellsGrid; // 2D Vector, same as arr[][]

    LudoCells();
    
    void init();
    void render();
};