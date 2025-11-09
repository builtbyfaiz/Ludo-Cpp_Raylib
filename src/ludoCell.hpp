#pragma once
#include "globals.hpp"
#include "pawn.hpp"
#include "raylib-cpp.hpp"

// clang-format off
class LudoCell
{
  private: 
    raylib::Color color;
    int              gridID,
                     pathID,
                     homeID,
                  specialID;
    float         outlineThickness;
    raylib::Color outlineColor     = LUDOGRAY;
    raylib::Rectangle rect;
    
    public:
    const enum Type {PATH_CELL, HOME_CELL, OTHER} type;
    
    LudoCell():type(OTHER){}
    LudoCell(raylib::Rectangle  r    = {0, 0, 0, 0} ,
             raylib::Color      c    = raylib::WHITE,
             Type               t    = OTHER,
             int           gridID    = 0,
             int           pathID    = 0,
             int           homeID    = 0,
             int           specialID = 0)
              : rect(r), color(c), type(t), gridID(gridID), pathID(pathID), homeID(homeID), specialID(specialID) {} // clang-format on

    void render();

    // Getters
    int getGridID();
    int getPathID();
    int getHomeID();
    int getSpecialID();
    raylib::Rectangle getRect();

    // Setters
    void setColor(raylib::Color color);
    void setGridID(int gID);
    void setPathID(int pID);
    void setHomeID(int hID);
    void setSpecialID(int sID);
    void setOutlineThickness(float thickness);
};
