#pragma once
#include "ludoCell.hpp"
#include "raylib-cpp.hpp"

class LudoCell; //Forward-Declaration

class Pawn
{
  private:
    int ID;
    int score = 0;
    
    float size = 30;
    raylib::Color color;
    raylib::Rectangle rect = {10, 10, size, size}; // Default
    
    public:
    bool isMoveable = false;
    

    LudoCell *currentCell = nullptr;
    LudoCell *homeCell = nullptr;
    LudoCell *spawnCell = nullptr;
    

    // Easter Egg Left By Faiz
    Pawn ( LudoCell *hC );

    void update();
    void render();
    
    void returnHome();               //Aka die
    void moveTo(LudoCell *nextCell); //Aka Keep moving Forward #eren
    void spawn();
    void die();

    const raylib::Rectangle   getRect();
    const raylib::Color getColor();
    const bool getState();
    const int getScore();
};