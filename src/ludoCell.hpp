#pragma once
#include "raylib-cpp.hpp"
#include "constants.hpp"

using namespace raylib;
class ludoCell
{

private:
    raylib::Color color;
    int gridID = -1, pathID = -1, specialID = -1;
    raylib::Color outlineColor = LUDOGRAY;
    float outlineThickness = 0;

public:
    raylib::Rectangle rect;

    ludoCell() : rect(0, 0, 0, 0), color(raylib::WHITE) {}
    ludoCell(raylib::Rectangle r,
             raylib::Color c = raylib::RED,
             int gID = -1, int sID = -1, int pID = -1)
        : rect(r), color(c), gridID(gID), specialID(sID), pathID(pID) {}

    void render();
    void setColor(raylib::Color color);
    void setGridID(int gridID);
    void setPathID(int pathID);
    void setSpecialID(int specialID);
    void setOutlineThickness(float thickness);

    int getGridID();
    int getPathID();
    int getSpecialID();
};
