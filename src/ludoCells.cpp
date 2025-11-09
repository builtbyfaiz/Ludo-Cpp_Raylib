#include "ludoCells.hpp"
#include "mappingsCells.hpp"
#include "globals.hpp"
#include "ludoCell.hpp"
#include "raylib-cpp.hpp"
#include <iostream>
#include <map>
#include <string>


/// @brief Draw All Cells in the 'cells' vector
void LudoCells::render()
{
    for (auto &row : cellsGrid)
        for (auto &cell : row)
        {
            cell.render();
        }
}

// clang-format off
/// @brief Create the board by initializing all cells
LudoCells::LudoCells()
{
   init();
}

void LudoCells::init() 
{
     for (size_t y = 0; y < 15; y++)
    {
        std::vector<LudoCell> cellsRow;
        for (size_t x = 0; x < 15; x++)
        {
            float             width  = GetScreenWidth()  / 15;
            float             height = GetScreenHeight() / 15;
            raylib::Color     color  = colorLegend[colorMap[y][x]]; 
            raylib::Rectangle rect   = {x * width, y * height, width, height};

            int gridID    = y * 15 + x + 1 ;          // 1 --> 255
            int pathID    = pathIDMap[y][x];          // 1-59 I think
            int homeID    = homeIDMap[y][x];          // 1-4
            int specialID = specialIDMap[y][x] - '0'; // Ascii to Int
            
            LudoCell::Type type =
                pathID > 0 ? LudoCell::PATH_CELL : LudoCell::OTHER;
            
            // std::cout << width << height;
            LudoCell cell(
                rect,                        // Rectangle [X, Y, Size]
                color,                       // Color from legend
                type,                        // Path, Home, Other etc.
                gridID,                      // Grid ID... All Cells Numerized
                pathID,                      // Special cell ID, (1-6 win path)
                homeID,
                specialID                    // Path Id of Direct path that all pawns move on
            );
            // if (cell.getSpecialID() > 0 || cell.getPathID() > 0)
                cell.setOutlineThickness(1);

            cellsRow.push_back(cell);
        }
        cellsGrid.push_back(cellsRow);
    }
}