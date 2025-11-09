#include <vector>
#include "pawn.hpp"

class LudoCells;

class Pawns 
{
    private:
    

    std::vector<Pawn> pawnSet1;
    std::vector<Pawn> pawnSet2;
    std::vector<Pawn> pawnSet3;
    std::vector<Pawn> pawnSet4;

    public:
    std::vector<Pawn> allPawns;

    Pawns(LudoCells *cells);

    void init(LudoCells *cells);
    void render();
};