#include "ludoCells.hpp"
#include "globals.hpp"
#include "ludoCell.hpp"
#include "maps.hpp"
#include "raylib-cpp.hpp"
#include <iostream>
#include <map>
#include <string>

/// @brief Draw All Cells in the 'cells' vector
void ludoCells::render()
{
    for (auto &row : cellsGrid)
        for (auto &cell : row)
        {
            // std::cout << cell.rect.width  << std::endl
            //           << cell.rect.height << std::endl
            //           << cell.rect.x      << std::endl
            //           << cell.rect.y      << std::endl;
            cell.render();
        }
}
// clang-format off

/// @brief Create the board by initializing all cells
ludoCells::ludoCells()
{
   init();
}

void ludoCells::init() 
{
     for (size_t y = 0; y < 15; y++)
    {
        std::vector<ludoCell> cellsRow;
        for (size_t x = 0; x < 15; x++)
        {
            float             width  = GetScreenWidth()  / 15;
            float             height = GetScreenHeight() / 15;
            raylib::Color     color  = colorLegend[colorMap[y][x]];
            raylib::Rectangle rect   = {x * width, y * height, width, height};

            int gridID    = y * 15 + x + 1;
            int pathID    = pathIDMap[y][x] ;
            int specialID = specialIDLegend[specialIDMap[y][x]];

            // std::cout << width << height;
            ludoCell cell(
                rect,                        // Rectangle itself
                color, // Color from legend
                gridID,                      // Grid ID... All Cells Numerized
                pathID,                      // Special cell ID, (1-6 win path)
                specialID // Path Id of Direct path that all pawns move on
            );
            
            if (cell.getSpecialID() > 0 || cell.getPathID() > 0)
                cell.setOutlineThickness(1);

            cellsRow.push_back(cell);
            // std::cout << cell.rect.width  << std::endl
            //           << cell.rect.height << std::endl
            //           << cell.rect.x      << std::endl
            //           << cell.rect.y      << std::endl
            //           << cell.getGridID() << cell.getSpecialID();
        }
        cellsGrid.push_back(cellsRow);
    }
}