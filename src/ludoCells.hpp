#pragma once
#include <vector>
#include "raylib-cpp.hpp"
#include "globals.hpp"
#include "ludoCell.hpp"

class ludoCells
{
public:
    std::vector<std::vector<ludoCell>> cellsGrid; // 2D Vector, same as arr[][]

    ludoCells();

    void render();
};