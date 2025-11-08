#pragma once
#include <vector>
#include "raylib.hpp"
#include "constants.hpp"

class ludoCell
{

private:
    Color color;
    int gridID = -1, pathID = -1, specialID = -1;
    Color outlineColor = LUDOGRAY;
    float outlineThickness = 0;

public:
    Rectangle rect;
    ludoCell() : rect({0, 0, 0, 0}), color(WHITE) {}
    ludoCell(float x, float y, float w, float h,
             Color c = RED,
             int gID = -1, int sID = -1, int pID = -1)
        : rect({x, y, w, h}), color(c), gridID(gID), specialID(sID), pathID(pID) {}

    void render();
    void setColor(Color color);
    void setGridID(int gridID);
    void setPathID(int pathID);
    void setSpecialID(int specialID);
    void setOutlineThickness(float thickness);

    int getGridID();
    int getPathID();
    int getSpecialID();
};

class ludoCells
{
public:
    std::vector<std::vector<ludoCell>> cellsGrid; // 2D Vector, same as arr[][]

    ludoCells();

    void render();
};