#include <vector>
#include "pawn.hpp"

class LudoCells;

class Pawns 
{
    private:
    
    public:
    std::vector<Pawn> allPawns;

    Pawns() = default;

    void init(LudoCells *cells);
    void assignSpawnCells(LudoCells *cells);
    void render();
    void handleInput();
};