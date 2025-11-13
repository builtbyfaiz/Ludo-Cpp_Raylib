#pragma once
#include "globals.hpp"
#include "raylib-cpp.hpp"
#include <map>
#include <string>

// clang-format off
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
std::map<char, raylib::Color> colorLegend = 
{
    {'R', LUDO_RED      }, // Top-left  
    {'G', LUDO_GREEN    }, // Top-right 
    {'B', LUDO_BLUE     }, // Bottom-left  
    {'Y', LUDO_YELLOW   }, // Bottom-right
    {'O', raylib::BLACK}, // Central void cells
    {' ', raylib::WHITE}  // Path cells
};

// Path ID mapping for the Ludo board.
// 2D array where each cell contains a unique path ID or 0 if not part of the path.
// Used for movement logic and win condition checks.
int pathIDMap[15][15] = 
{
    { 0,  0,  0,  0,  0,  0, 24, 25, 26,  0,  0,  0,  0,  0,  0},
    { 0,  0,  0,  0,  0,  0, 23,  0, 27,  0,  0,  0,  0,  0,  0},
    { 0,  0,  0,  0,  0,  0, 22,  0, 28,  0,  0,  0,  0,  0,  0},
    { 0,  0,  0,  0,  0,  0, 21,  0, 29,  0,  0,  0,  0,  0,  0},
    { 0,  0,  0,  0,  0,  0, 20,  0, 30,  0,  0,  0,  0,  0,  0},
    { 0,  0,  0,  0,  0,  0, 19,  0, 31,  0,  0,  0,  0,  0,  0},
    {13, 14, 15, 16, 17, 18,  0,  0,  0, 32, 33, 34, 35, 36, 37},
    {12,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 38},
    {11, 10,  9,  8,  7,  6,  0,  0,  0, 44, 43, 42, 41, 40, 39},
    { 0,  0,  0,  0,  0,  0,  5,  0, 45,  0,  0,  0,  0,  0,  0},
    { 0,  0,  0,  0,  0,  0,  4,  0, 46,  0,  0,  0,  0,  0,  0},
    { 0,  0,  0,  0,  0,  0,  3,  0, 47,  0,  0,  0,  0,  0,  0},
    { 0,  0,  0,  0,  0,  0,  2,  0, 48,  0,  0,  0,  0,  0,  0},
    { 0,  0,  0,  0,  0,  0,  1,  0, 49,  0,  0,  0,  0,  0,  0},
    { 0,  0,  0,  0,  0,  0, 52, 51, 50,  0,  0,  0,  0,  0,  0}
};

int homeIDMap[15][15] = {{0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0},
                         {0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0},
                         {0, 0,  1,  2, 0, 0, 0, 0, 0, 0, 0,  5,  6, 0, 0},
                         {0, 0,  3,  4, 0, 0, 0, 0, 0, 0, 0,  7,  8, 0, 0},
                         {0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0},
                         {0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0},
                         {0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0},
                         {0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0},
                         {0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0},
                         {0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0},
                         {0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0},
                         {0, 0,  9, 10, 0, 0, 0, 0, 0, 0, 0, 13, 14, 0, 0},
                         {0, 0, 11, 12, 0, 0, 0, 0, 0, 0, 0, 15, 16, 0, 0},
                         {0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0},
                         {0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0}};

// Special cell ID mapping for the Ludo board.
// Each string represents a row; numeric characters indicate special cells leading to the center/win.
std::string specialIDMap[15] = 
{
    "000000000000000", // Row01
    "000000010000000", // Row 2
    "000000020000000", // Row 3
    "000000030000000", // Row 4
    "000000040000000", // Row 5
    "000000050000000", // Row 6
    "000000060000000", // Row 7
    "012345606543210", // Row 8 (Center Path)
    "000000060000000", // Row 9
    "000000050000000", // Row 10
    "000000040000000", // Row 11
    "000000030000000", // Row 12
    "000000020000000", // Row 13
    "000000010000000", // Row 14
    "000000000000000"  // Row 15
};