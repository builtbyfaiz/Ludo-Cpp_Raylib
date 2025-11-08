#pragma once
#include "globals.hpp"
#include "raylib-cpp.hpp"
#include <map>
#include <string>

// Grid color mapping for the Ludo board.
// Each string represents a row; characters correspond to color codes defined in colorLegend.
std::string colorMap[15] = {
    "RRRRRR   GGGGGG", // Row 1
    "R    R GGG    G", // Row 2
    "R    R G G    G", // Row 3
    "R    R G G    G", // Row 4
    "R    R G G    G", // Row 5
    "RRRRRR G GGGGGG", // Row 6
    " R    OGO      ", // Row 7
    " RRRRRROYYYYYY ", // Row 8 (center path)
    "      OBO    Y ", // Row 9
    "BBBBBB B YYYYYY", // Row 10
    "B    B B Y    Y", // Row 11
    "B    B B Y    Y", // Row 12
    "B    B B Y    Y", // Row 13
    "B    BBB Y    Y", // Row 14
    "BBBBBB   YYYYYY"  // Row 15
};

// Mapping from color code characters to Raylib Color objects.
// Used to render the board grid with appropriate colors.
std::map<char, raylib::Color> colorLegend = {
    {'R', LUDORED},       // Top-left home area
    {'G', LUDOGREEN},     // Top-right home area
    {'B', LUDOBLUE},      // Bottom-left home area
    {'Y', LUDOYELLOW},    // Bottom-right home area
    {'O', raylib::BLACK}, // Central void cells
    {' ', raylib::WHITE}  // Path cells
};

// Special cell ID mapping for the Ludo board.
// Each string represents a row; numeric characters indicate special cells leading to the center/win.
std::string specialIDMap[15] = {
    "               ", // Row 1
    "       1       ", // Row 2
    "       2       ", // Row 3
    "       3       ", // Row 4
    "       4       ", // Row 5
    "       5       ", // Row 6
    "       6       ", // Row 7
    " 123456 654321 ", // Row 8 (Center Path)
    "       6       ", // Row 9
    "       5       ", // Row 10
    "       4       ", // Row 11
    "       3       ", // Row 12
    "       2       ", // Row 13
    "       1       ", // Row 14
    "               "  // Row 15
};

// Mapping from special cell ID characters to integer values.
// Used for identifying special cells programmatically.
std::map<char, int> specialIDLegend = {
    {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4},
    {'5', 5}, {'6', 6}, {' ', -1} // Non-special cells
};

// Path ID mapping for the Ludo board.
// 2D array where each cell contains a unique path ID or -1 if not part of the path.
// Used for movement logic and win condition checks.
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
