#include <vector>
#include "pawn.hpp"

class LudoCells;

class Pawns 
{
    private:
    
    public:
    std::vector<Pawn> allPawns;
    LudoCells *cells;
    Pawns() = default;

    void init(LudoCells *cells);
    void move(Pawn pawn, int amount);

    void render();
    void handleInput();
};