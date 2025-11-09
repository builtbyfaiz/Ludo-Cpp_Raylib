#include "ludoCell.hpp"

/// @brief Draw a Ludo Cell
void LudoCell::render()
{
    rect.Draw(color); // Draw The Cell
    rect.DrawLines(
        outlineColor,
        outlineThickness); // Draw Outline of the Cell, If thickness > 0

    // int fontSize = rect.height / 2.5;
    // int textY = rect.y + (rect.height - fontSize) / 2;
    // int textX = rect.x + (rect.width - fontSize - 20) / 2; // Not perfect but
    // almost enough

    // int ID = gridID;
    // if (specialID > 0)
    //     ID = specialID;
    // if (pathID > 0)
    //     ID = pathID;
    // DrawText(std::to_string(ID).c_str(), textX, textY, fontSize, BLACK); //
    // Draw numbers in them, also MAGIC nums :P
}

// Setter Methods
void LudoCell::setColor (raylib::Color  c) { color     =   c; }  
void LudoCell::setGridID   (const int gID) { gridID    = gID; }
void LudoCell::setPathID   (const int pID) { pathID    = pID; }
void LudoCell::setHomeID   (const int hID) { homeID    = hID; }
void LudoCell::setSpecialID(const int sID) { specialID = sID; }
void LudoCell::setOutlineThickness(float thickness)
{
    outlineThickness = thickness;
}

int LudoCell::getGridID()    { return gridID;    }
int LudoCell::getPathID()    { return pathID;    }
int LudoCell::getHomeID()    { return homeID;    }
int LudoCell::getSpecialID() { return specialID; }
