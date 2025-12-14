#include "pawns.hpp"
#include "ludoCells.hpp"
#include "mappingsPawns.hpp"
#include <iostream>
#include <string>

void Pawns::init()
{
    raylib::Color color;
    // std::cout<<"Reportin Duty debug";
    // std::cout<<static_cast<std::string>(cells->cellsGrid[2][3].getColor());
    for (auto &row : cells->cellsGrid)
    {
        for (auto &cell : row)
        {
            if (cell.getHomeID() > 0)
            {
                allPawns.emplace_back(&cell); 
                Pawn &pawn = allPawns.back(); 

                allPawns.back().spawnCell =
                    &cells->cellsGrid[colorSpawnMap(pawn.getColor()).y]
                                     [colorSpawnMap(pawn.getColor()).x];
            }
        }
    }
}

void Pawns::move(Pawn &pawn, int dice)
{
    int newPathID = pawn.currentCell->getPathID() + dice;
    if (newPathID > 52)
        newPathID -= 52;


    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (cells->cellsGrid[i][j].getPathID() == newPathID)
            {
                pawn.moveTo(&cells->cellsGrid[i][j]);
                pawn.score+= dice;
                return;
            }
        }
    }
}

void Pawns::render()
{
    for (auto &pawn : allPawns)
    {
        // std::cout<<pawn.getRect().x;
        // std::cout<<pawn.getRect().y;
        // std::cout<<pawn.getRect().width;
        pawn.render();
    }
}

void Pawns::handleInput() {}