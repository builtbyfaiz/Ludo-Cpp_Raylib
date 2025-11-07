#include <iostream>
#include <string>
#include <map>
#include "raylib.h"
#include "constants.hpp"
#include "ludoCells.hpp"

/// @brief Draw Ludo Cells, Their Outlines and their IDs
void ludoCell::draw()
{
    DrawRectangleRec(rect, color);                              // Draw Boxes
    DrawRectangleLinesEx(rect, outlineThickness, outlineColor); // Draw Outline of them

    int fontSize = rect.height / 2.5;
    int textY = rect.y + (rect.height - fontSize) / 2;
    int textX = rect.x + (rect.width - fontSize - 20) / 2; // Not perfect but almost enough

    int ID = gridID;
    if (specialID > 0)
        ID = specialID;
    if (pathID > 0)
        ID = pathID;

    // DrawText(std::to_string(ID).c_str(), textX, textY, fontSize, BLACK); // Draw numbers in them, also MAGIC nums :P
}

/// @brief Draw All Cells in the 'cells' vector
void ludoCells::draw()
{
    for (auto &cellRow : cellsGrid)
    {
        for (auto &cell : cellRow)
        {
            cell.draw();
        }
    }
}

/// @brief Create the board by initializing all cells
ludoCells::ludoCells()
{
    std::string colorMap[15] = {
        "RRRRRR   GGGGGG", // row 1
        "R    R GGG    G", // row 2
        "R    R G G    G", // row 3
        "R    R G G    G", // row 4
        "R    R G G    G", // row 5
        "RRRRRR G GGGGGG", // row 6
        " R    OGO      ", // row 7
        " RRRRRROYYYYYY ", // row 8 center path
        "      OBO    Y ", // row 9
        "BBBBBB B YYYYYY", // row 10
        "B    B B Y    Y", // row 11
        "B    B B Y    Y", // row 12
        "B    B B Y    Y", // row 13
        "B    BBB Y    Y", // row 14
        "BBBBBB   YYYYYY"  // row 15
    };

    std::map<char, Color> colorLegend = {
        {'R', LUDORED},    // top-left home
        {'G', LUDOGREEN},  // top-right home
        {'B', LUDOBLUE},   // bottom-left home
        {'Y', LUDOYELLOW}, // bottom-right home
        {'O', BLACK},      // Void Cells
        {' ', WHITE}       // Path
    };

    std::string specialIDMap[15] = {
        "               ", // row 1
        "       1       ", // row 2
        "       2       ", // row 3
        "       3       ", // row 4
        "       4       ", // row 5
        "       5       ", // row 6
        "       6       ", // row 7
        " 123456 654321 ", // row 8 center path
        "       6       ", // row 9
        "       5       ", // row 10
        "       4       ", // row 11
        "       3       ", // row 12
        "       2       ", // row 13
        "       1       ", // row 14
        "               "  // row 15
    };

    std::map<char, int> specialIDLegend = {
        {'1', 1},
        {'2', 2},
        {'3', 3},
        {'4', 4},
        {'5', 5},
        {'6', 6},
        {' ', -1}};

    int pathIDMap[15][15] = {
        {-1, -1, -1, -1, -1, -1, 24, 25, 26, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, 23, -1, 27, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, 22, -1, 28, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, 21, -1, 29, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, 20, -1, 30, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, 19, -1, 31, -1, -1, -1, -1, -1, -1},
        {13, 14, 15, 16, 17, 18, -1, -1, -1, 32, 33, 34, 35, 36, 37},
        {12, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 38},
        {11, 10, 9, 8, 7, 6, -1, -1, -1, 44, 43, 42, 41, 40, 39},
        {-1, -1, -1, -1, -1, -1, 5, -1, 45, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, 4, -1, 46, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, 3, -1, 47, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, 2, -1, 48, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, 1, -1, 49, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, 52, 51, 50, -1, -1, -1, -1, -1, -1}};

    for (size_t y = 0; y < 15; y++)
    {
        std::vector<ludoCell> cellsRow;
        for (size_t x = 0; x < 15; x++)
        {
            float width = GetScreenWidth() / 15;
            float height = GetScreenHeight() / 15;
            ludoCell cell(
                x * width,                           // x-position
                y * height,                          // y-position
                width,                               // width
                height,                              // height
                colorLegend[colorMap[y][x]],         // color from legend
                y * 15 + x + 1,                      // grid ID
                specialIDLegend[specialIDMap[y][x]], // special cell ID, 1-6
                pathIDMap[y][x]                      // Direct path that all pawns move on
            );
            if (cell.getSpecialID() > 0 || cell.getPathID() > 0)
                cell.setOutlineThickness(1);
            
            // if (x > 8 && y < 6)
            //         cell.setOutlineThickness(0); // 1st Quadrant
            // if (x < 6 && y < 6)
            //     cell.setOutlineThickness(0); // 2nd Quadrant
            // if (x < 6 && y < 8)
            //     cell.setOutlineThickness(0); // 3rd Quadrant
            // if (x > 8 && y > 8)
            //     cell.setOutlineThickness(0); // 4th Quadrant

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
void ludoCell::setColor(Color c) { color = c; }
void ludoCell::setGridID(const int ID) { gridID = ID; }
void ludoCell::setPathID(const int ID) { pathID = ID; }
void ludoCell::setSpecialID(const int ID) { specialID = ID; }
void ludoCell::setOutlineThickness(float thickness) { outlineThickness = thickness; }

int ludoCell::getGridID() { return gridID; }
int ludoCell::getPathID() { return pathID; }
int ludoCell::getSpecialID() { return specialID; }
