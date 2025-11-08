#pragma once
#include "raylib-cpp.hpp"

using namespace raylib;

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

const raylib::Color LUDORED   = {236, 28, 34,255};
const raylib::Color LUDOGREEN = {1, 161, 70,255};
const raylib::Color LUDOBLUE  = {37, 174, 253, 255};
const raylib::Color LUDOYELLOW = {250, 220, 22,255};
const raylib::Color LUDOGRAY = {0, 0, 0, 255};
