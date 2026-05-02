#pragma once
#include "globals.hpp"
#include "raylib-cpp.hpp" // IWYU pragma: keep

#include <map>

// Home ID to Pawn Color
inline std::map<int, raylib::Color> pawnIdToColor = {
    {0, WHITE},

    {1, LUDO_RED}, // Top-left 1
    {2, LUDO_RED}, // Top-left 2
    {3, LUDO_RED}, // Top-left 3
    {4, LUDO_RED}, // Top-left 4

    {5, LUDO_GREEN}, // Top-right 1
    {6, LUDO_GREEN}, // Top-right 2
    {7, LUDO_GREEN}, // Top-right 3
    {8, LUDO_GREEN}, // Top-right 4

    {9,  LUDO_BLUE}, // Bottom-left 1
    {10, LUDO_BLUE}, // Bottom-left 2
    {11, LUDO_BLUE}, // Bottom-left 3
    {12, LUDO_BLUE}, // Bottom-left 4

    {13, LUDO_YELLOW}, // Bottom-right 1
    {14, LUDO_YELLOW}, // Bottom-right 2
    {15, LUDO_YELLOW}, // Bottom-right 3
    {16, LUDO_YELLOW}  // Bottom-right 4
};

// Returns Vector2 of 2d Array indices corresponding to the spawn cell on a 15 by 15 Grid
inline const raylib::Vector2 ColorToPawnSpawnPos(const raylib::Color color)
{
    // inline keyword is here being used to prevent multiple definitions, std::map did not work for custom datatypes
    if(color == LUDO_RED)    return {1, 6};
    if(color == LUDO_BLUE)   return {6, 13};
    if(color == LUDO_GREEN)  return {8, 1};
    if(color == LUDO_YELLOW) return {13, 8};
    
    return {0,0}; // Return 0,0 if nothing matches
}