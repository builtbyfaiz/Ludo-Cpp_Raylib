#include "ludoCell.hpp"

/// @brief Draw a Ludo Cell
void ludoCell::render()
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
void ludoCell::setColor (raylib::Color  c) { color     =   c; }  
void ludoCell::setGridID   (const int gID) { gridID    = gID; }
void ludoCell::setPathID   (const int pID) { pathID    = pID; }
void ludoCell::setSpecialID(const int sID) { specialID = sID; }
void ludoCell::setOutlineThickness(float thickness)
{
    outlineThickness = thickness;
}

int ludoCell::getGridID()    { return gridID;    }
int ludoCell::getPathID()    { return pathID;    }
int ludoCell::getSpecialID() { return specialID; }
