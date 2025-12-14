#pragma once
#include "raylib-cpp.hpp"

// clang-format off
// This type is depracated
enum Type
{
    NONE,
    SAFE,
    BASE_WALL,
    BASE_SPAWN,
    BASE_SPECIAL,
    PAWN_HOME,
    PAWN_PATH
};

//Color-Pallete defined as RGBA values
const raylib::Color LUDO_RED    = {236, 28 , 34 , 255};
const raylib::Color LUDO_GREEN  = {1  , 161, 70 , 255};
const raylib::Color LUDO_BLUE   = {37 , 174, 253, 255};
const raylib::Color LUDO_YELLOW = {250, 220, 22 , 255};
const raylib::Color LUDOGRAY    = {0  , 0  , 0  , 255};
