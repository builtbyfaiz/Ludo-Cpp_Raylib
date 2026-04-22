#pragma once
#include "Globals.hpp"
#include "Pawn.hpp"
#include <vector>

// clang-format off
class Cell
{
  private:
    const int gridID_, pathID_, homeID_, winPathID_;
    
    bool safe_ = false; // If cell is marked as safe cell

    
    raylib::Rectangle rect;
    raylib::Color color;
    raylib::Color outlineColor = LUDO_BLACK;
    
    float outlineThickness = 0;
    
    public:
    // Default Constructor with default values
    Cell(raylib::Rectangle r = {0, 0, 0, 0},
         raylib::Color     c = raylib::WHITE,
         const int gridID    = 0,
         const int pathID    = 0,
         const int homeID    = 0,
         const int winPathID = 0,
         const bool safe     = 0)

        : rect(r), color(c), gridID_(gridID), pathID_(pathID), homeID_(homeID),
          winPathID_(winPathID), safe_(safe) {}

          void render();
          
          void addPawn(Pawn *pawn);
    void removePawn(Pawn *pawn);

    // Getters
    int getGridID();
    int getPathID();
    int getHomeID();
    int getWinPathID();

    std::vector<Pawn*> pawnsOnCell;
    int getPawnsOnTop();
    bool isSafe();
    
    raylib::Color getColor();
    raylib::Rectangle getRect();

    // Setters
    void setColor(raylib::Color color);
    void setOutlineThickness(float thickness);
};