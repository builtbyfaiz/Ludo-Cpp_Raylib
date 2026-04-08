#include "Cells.hpp"

#include "Cell.hpp"
#include "CellMaps.hpp"
#include "raylib-cpp.hpp" // IWYU pragma: keep

#include <map>
#include <string>

/// @brief Draw All Cells in the 'cells' vector
void Cells::render()
{
    for (auto &row : grid)
        for (auto &cell : row)
            cell.render();
}

// clang-format off
/// @brief Create the board by initializing all cells
Cells::Cells(){}

void Cells::init() 
{
    grid.clear();
    
    for (size_t y = 0; y < 15; y++)
    {
        std::vector<Cell> cellsRow; 
        for (size_t x = 0; x < 15; x++)
        {
            // Create 15 By 15 Block grid.
            float width  = GetScreenWidth()  / 15.0;
            float height = GetScreenHeight() / 15.0;
            
            raylib::Color     color  = boardColorGrid(y, x);
            raylib::Rectangle rect   = {x * width, y * height, width, height};

            int gridID    = y * 15 + x + 1 ;           // 1 - 255
            int pathID    = pathIDGrid[y][x];          // 1 - 52 
            int homeID    = homeIDGrid[y][x];          // 1 - 16
            int winPathID = winPathIDGrid[y][x] - '0'; // Ascii to Int, #TODO will turn it into direct func soon

            Cell::Type type =
                pathID > 0 ? Cell::PATH_CELL : Cell::OTHER;
            
            // std::cout << width << height;
            Cell cell(
                rect  ,    // Rectangle [X, Y, Size]
                color ,    // Color from legend
                type  ,    // Path, Home, Other etc.
                gridID,    // Grid ID... All Cells Numerized
                pathID,    // Path Id of Direct path that all pawns move on
                homeID,    // Base Cells Id
                winPathID  // Special cell ID, (1-6 win path)
            );

            if (cell.getWinPathID() > 0 || cell.getPathID() > 0)
                cell.setOutlineThickness(1);
                
            // if(cell.getPathID()!=0) pathCells.push_back(cell);

            cellsRow.push_back(cell);
        }
        grid.push_back(cellsRow);
    }
}