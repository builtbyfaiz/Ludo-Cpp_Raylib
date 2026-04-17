#pragma once
#include "globals.hpp"

// clang-format off
class Cell
{
  private:
    const int gridID_, pathID_, homeID_, winPathID_;
    
    raylib::Rectangle rect;
    raylib::Color color;
    raylib::Color outlineColor = LUDO_GRAY;
    
    float outlineThickness = 0;

  public:
    // Default Constructor with default values
    Cell(raylib::Rectangle r = {0, 0, 0, 0},
         raylib::Color     c = raylib::WHITE,
         const int gridID    = 0,
         const int pathID    = 0,
         const int homeID    = 0,
         const int winPathID = 0)

        : rect(r), color(c), gridID_(gridID), pathID_(pathID), homeID_(homeID),
          winPathID_(winPathID) {}

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
    void setOutlineThickness(float thickness);
};
