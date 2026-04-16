#include "Cells.hpp"

#include "Cell.hpp"
#include "CellMaps.hpp"
#include "raylib-cpp.hpp" // IWYU pragma: keep

#include <string>

// clang-format off

// Initialie all the cells of the board
void Cells::init()
{
    grid.clear(); // Start by clearing grid so, we can use init as reset.

    // fill the 15 By 15 block grid by using nested for.
    for (size_t y = 0; y < 15; y++)
    {
        // Create a row i.e an array made up of cells.
        std::vector<Cell> cellsRow; 
        for (size_t x = 0; x < 15; x++)
        {
            float width  = GetScreenWidth() / 15.0;
            float height = GetScreenHeight() / 15.0;

            raylib::Color     color = boardColorGrid(y, x);
            raylib::Rectangle rect  = {x * width, y * height, width, height};

            int gridID    = y * 15 + x + 1;             // 1 - 255
            int pathID    = pathIDGrid[y][x];           // 1 - 52
            int homeID    = homeIDGrid[y][x];           // 1 - 16
            int winPathID = winPathIDGrid[y][x] - '0';  // Ascii to Int, #TODO will turn it into direct func soon

            Cell::Type type = pathID > 0 ? Cell::PATH_CELL : Cell::OTHER;

            // std::cout << width << height;
            Cell cell(rect,     // Rectangle [X, Y, Size]
                      color,    // Color from legend
                      type,     // Path, Home, Other etc., not used so much as of now
                      gridID,   // Grid ID... All Cells Numerized
                      pathID,   // Path Id of Direct path that all pawns move on
                      homeID,   // Base Cells Id
                      winPathID // Special cell ID, (1-6 win path)
            );

            if (cell.getWinPathID() > 0 || cell.getPathID() > 0)
                cell.setOutlineThickness(1);

            cellsRow.push_back(cell);
        }
        grid.push_back(cellsRow);
    }
}

/// @brief Draw All Cells in the 'cells' vector
void Cells::render()
{
    for (auto &row : grid)
        for (auto &cell : row)
            cell.render();
}