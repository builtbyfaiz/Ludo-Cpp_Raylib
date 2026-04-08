#include "pawn.hpp"
#include <vector>

class LudoCells;

class PawnsManager
{
  public:
    LudoCells *cells_;
    std::vector<Pawn> allPawns;
    
    void init();
    void move(Pawn &pawn, int amount);
    
    void handleInput();
    void render();
    
    PawnsManager(LudoCells *cells) : cells_(cells) {}
};