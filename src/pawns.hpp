#include "pawn.hpp"
#include <vector>

class LudoCells;

class Pawns
{
  public:
    LudoCells *cells_;
    std::vector<Pawn> allPawns;
    
    void init();
    void move(Pawn &pawn, int amount);
    
    void handleInput();
    void render();
    
    Pawns(LudoCells *cells) : cells_(cells) {}
};