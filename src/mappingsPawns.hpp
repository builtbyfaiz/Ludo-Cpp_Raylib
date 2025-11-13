#pragma once
#include "globals.hpp"
#include "raylib-cpp.hpp"
#include <map>


// Home ID to Pawn Color
std::map<int, raylib::Color> colorLegendPawns = {
    {0, WHITE},

    {1, LUDO_RED}, // Top-left 1
    {2, LUDO_RED}, // Top-left 2
    {3, LUDO_RED}, // Top-left 3
    {4, LUDO_RED}, // Top-left 4

    {5, LUDO_GREEN}, // Top-right 1
    {6, LUDO_GREEN}, // Top-right 2
    {7, LUDO_GREEN}, // Top-right 3
    {8, LUDO_GREEN}, // Top-right 4

    {9, LUDO_BLUE},  // Bottom-left 1
    {10, LUDO_BLUE}, // Bottom-left 2
    {11, LUDO_BLUE}, // Bottom-left 3
    {12, LUDO_BLUE}, // Bottom-left 4

    {13, LUDO_YELLOW}, // Bottom-right 1
    {14, LUDO_YELLOW}, // Bottom-right 2
    {15, LUDO_YELLOW}, // Bottom-right 3
    {16, LUDO_YELLOW}  // Bottom-right 4
};

raylib::Vector2 colorSpawnMap(const raylib::Color color){
    if(color==LUDO_RED)    return {1, 6};
    if(color==LUDO_GREEN)  return {1, 6};
    if(color==LUDO_BLUE)   return {1, 6};
    if(color==LUDO_YELLOW) return {1, 6};
}
std::map<raylib::Color, raylib::Vector2> colorSpawnaMap= {
    {LUDO_RED,    {1, 6}},
    {LUDO_GREEN,  {6, 1}},
    {LUDO_BLUE,   {6,13}},
    {LUDO_YELLOW, {13,6}}
};