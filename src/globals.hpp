#pragma once
#include "raylib-cpp.hpp" // IWYU pragma: keep

//Color-Pallete defined as RGBA values

const raylib::Color LUDO_WHITE  = {220, 220, 220, 255};
const raylib::Color LUDO_BLACK  = {10 ,  10,  10, 255};
const raylib::Color LUDO_GRAY   = {120, 120, 120, 255};
const raylib::Color LUDO_RED    = {236,  28,  34, 255};
const raylib::Color LUDO_BLUE   = {37 , 174, 253, 255};
const raylib::Color LUDO_GREEN  = {1  , 161,  70, 255};
const raylib::Color LUDO_YELLOW = {250, 220,  22, 255};

const raylib::Color OUTLINE_COLOR_DEFAULT   = BLACK;
const raylib::Color OUTLINE_COLOR_SELECTION = PURPLE;
const raylib::Color OUTLINE_COLOR_HIGHLIGHT = {0, 255, 255, 255};

const float OUTLINE_THICKNESS_DEFAULT   = 2.0; 
const float OUTLINE_THICKNESS_SELECTION = 5.0; 
const float OUTLINE_THICKNESS_HIGHLIGHT = 3.0; 
