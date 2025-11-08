#include <iostream>
#include <string>
#include <map>
#include "raylib-cpp.hpp"
#include "constants.hpp"
#include "ludoCell.hpp"
#include "ludoCells.hpp"
#include "maps.hpp"

/// @brief Draw Ludo Cells, Their Outlines and their IDs
void ludoCell::render()
{
    rect.Draw(color);                               // Draw The Cell
    rect.DrawLines(outlineColor, outlineThickness); // Draw Outline of the Cell, If thickness > 0

    // int fontSize = rect.height / 2.5;
    // int textY = rect.y + (rect.height - fontSize) / 2;
    // int textX = rect.x + (rect.width - fontSize - 20) / 2; // Not perfect but almost enough

    // int ID = gridID;
    // if (specialID > 0)
    //     ID = specialID;
    // if (pathID > 0)
    //     ID = pathID;
    // DrawText(std::to_string(ID).c_str(), textX, textY, fontSize, BLACK); // Draw numbers in them, also MAGIC nums :P
}

/// @brief Draw All Cells in the 'cells' vector
void ludoCells::render()
{
    DrawRectangle(10, 10, 25, 25, raylib::RED);
    for (auto &row : cellsGrid)
        for (auto &cell : row)
            cell.render();
}

/// @brief Create the board by initializing all cells
ludoCells::ludoCells()
{
    for (size_t y = 0; y < 15; y++)
    {
        std::vector<ludoCell> cellsRow;
        for (size_t x = 0; x < 15; x++)
        {
            float width = GetScreenWidth() / 15;
            float height = GetScreenHeight() / 15;
            ludoCell cell(
                {x * width, y * height, width, height}, // Rectangle itself
                colorLegend[colorMap[y][x]],            // color from legend
                y * 15 + x + 1,                         // grid ID
                specialIDLegend[specialIDMap[y][x]],    // special cell ID, 1-6
                pathIDMap[y][x]                         // Direct path that all pawns move on
            );
            if (cell.getSpecialID() > 0 || cell.getPathID() > 0)
                cell.setOutlineThickness(1);

            cellsRow.push_back(cell);
        }
        cellsGrid.push_back(cellsRow);
    }
    cellsGrid[1][1].rect.width *= 4;
    cellsGrid[1][1].rect.height *= 4;
    cellsGrid[1].erase(cellsGrid[1].begin() + 2); // removes element in row 1, column 2

    Type typeMap[15][15] = {};
}

// Setter Methods
void ludoCell::setColor(raylib::Color c) { color = c; }
void ludoCell::setGridID(const int ID) { gridID = ID; }
void ludoCell::setPathID(const int ID) { pathID = ID; }
void ludoCell::setSpecialID(const int ID) { specialID = ID; }
void ludoCell::setOutlineThickness(float thickness) { outlineThickness = thickness; }

int ludoCell::getGridID() { return gridID; }
int ludoCell::getPathID() { return pathID; }
int ludoCell::getSpecialID() { return specialID; }
