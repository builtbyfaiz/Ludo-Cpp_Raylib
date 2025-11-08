#pragma once
#include "globals.hpp"
#include "raylib-cpp.hpp"

// clang-format off
class ludoCell
{
  private: 
    raylib::Color color;
    int           gridID           = -1,
                  pathID           = -1,
                  specialID        = -1;
    float         outlineThickness =  0;
    raylib::Color outlineColor     = LUDOGRAY;

  public:
    raylib::Rectangle rect;

    ludoCell(raylib::Rectangle r = {0, 0, 0, 0} ,
             raylib::Color     c = raylib::WHITE,
             int             gID = -1,
             int             sID = -1,
             int             pID = -1)
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
