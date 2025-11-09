#pragma once
#include "globals.hpp"
#include "raylib-cpp.hpp"
#include <map>


// Home ID to Pawn Color
std::map<int, raylib::Color> colorLegendPawns = {
    {0, WHITE},

    {1, LUDORED}, // Top-left 1
    {2, LUDORED}, // Top-left 2
    {3, LUDORED}, // Top-left 3
    {4, LUDORED}, // Top-left 4

    {5, LUDOGREEN}, // Top-right 1
    {6, LUDOGREEN}, // Top-right 2
    {7, LUDOGREEN}, // Top-right 3
    {8, LUDOGREEN}, // Top-right 4

    {9, LUDOBLUE},  // Bottom-left 1
    {10, LUDOBLUE}, // Bottom-left 2
    {11, LUDOBLUE}, // Bottom-left 3
    {12, LUDOBLUE}, // Bottom-left 4

    {13, LUDOYELLOW}, // Bottom-right 1
    {14, LUDOYELLOW}, // Bottom-right 2
    {15, LUDOYELLOW}, // Bottom-right 3
    {16, LUDOYELLOW}  // Bottom-right 4
};