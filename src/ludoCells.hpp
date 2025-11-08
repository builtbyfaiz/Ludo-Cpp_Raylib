#pragma once
#include "globals.hpp"
#include "ludoCell.hpp"
#include "raylib-cpp.hpp"
#include <vector>


class ludoCells
{
  public:
    std::vector<std::vector<ludoCell>> cellsGrid; // 2D Vector, same as arr[][]

    ludoCells();
    
    void init();
    void render();
};