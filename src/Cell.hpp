#pragma once
#include "globals.hpp"

// clang-format off
class Cell
{
  private: 
    raylib::Color color;
    raylib::Rectangle rect;

    const int gridID_, pathID_, homeID_, winPathID;

    raylib::Color outlineColor     = LUDOGRAY;
    float         outlineThickness = 0;
    
    public:
    const enum Type {PATH_CELL, HOME_CELL, SPECIAL_PATH_CELL, OTHER} type;
    
    // Cell():type(OTHER){}
    
    Cell(raylib::Rectangle r = {0, 0, 0, 0},
         raylib::Color     c = raylib::WHITE,
         Type              t = OTHER,
         const int gridID    = 0,
         const int pathID    = 0,
         const int homeID    = 0,
         const int specialID = 0)

        : rect(r), color(c), type(t), gridID_(gridID), pathID_(pathID), homeID_(homeID),
          winPathID(specialID){}

    void render();

    // Getters
    int getGridID();
    int getPathID();
    int getHomeID();
    int getWinPathID();
    raylib::Color getColor();
    raylib::Rectangle getRect();

    // Setters
    void setColor(raylib::Color color);
    void setGridID(int gID);
    void setPathID(int pID);
    void setHomeID(int hID);
    void setSpecialID(int sID);
    void setOutlineThickness(float thickness);
};
