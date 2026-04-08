#include "Cell.hpp"

/// @brief Draw a Ludo Cell
void Cell::render()
{
    rect.Draw(color); // Draw The Cell
    rect.DrawLines(
        outlineColor,
        outlineThickness); // Draw Outline of the Cell, If thickness > 0

    // int fontSize = rect.height / 2.5;
    // int textY = rect.y + (rect.height - fontSize) / 2;
    // int textX = rect.x + (rect.width - fontSize - 20) / 2; // Not perfect but almost enough

    // int ID = gridID;
    // if (specialID > 0)
    //     ID = specialID;
    // if (pathID > 0)
    //     ID = pathID;
    // if (homeID >0) ID = homeID;
    // DrawText(std::to_string(ID).c_str(), textX, textY, fontSize, BLACK); // Draw numbers in them, also MAGIC nums :P
}

// Setter Methods
void Cell::setColor (raylib::Color  c) { color     =   c; }  
// void Cell::setGridID   (const int gID) { gridID_    = gID; }
// void Cell::setPathID   (const int pID) { pathID_    = pID; }
// void Cell::setHomeID   (const int hID) { homeID_    = hID; }
// void Cell::setSpecialID(const int sID) { winPathID = sID; }
void Cell::setOutlineThickness(float thickness)
{
    outlineThickness = thickness;
}

int Cell::getGridID()    { return gridID_;    }
int Cell::getPathID()    { return pathID_;    }
int Cell::getHomeID()    { return homeID_;    }
int Cell::getWinPathID() { return winPathID; }

raylib::Color Cell::getColor()    { return color; }
raylib::Rectangle Cell::getRect() { return rect;  }
