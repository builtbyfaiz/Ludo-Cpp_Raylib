#include "ludoCell.hpp"

// Setter Methods
void ludoCell::setColor (raylib::Color c) { color     = c ; }  
void ludoCell::setGridID   (const int ID) { gridID    = ID; }
void ludoCell::setPathID   (const int ID) { pathID    = ID; }
void ludoCell::setSpecialID(const int ID) { specialID = ID; }
void ludoCell::setOutlineThickness(float thickness)
{
    outlineThickness = thickness;
}

int ludoCell::getGridID()    { return gridID;    }
int ludoCell::getPathID()    { return pathID;    }
int ludoCell::getSpecialID() { return specialID; }
