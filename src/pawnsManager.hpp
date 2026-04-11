#include "Pawn.hpp"

#include <vector>


class Cells;

class PawnsManager
{
  public:
    Cells *cells_;
    std::vector<Pawn> allPawns;

    void init();
    void move(Pawn &pawn, int amount);

    void selectPawn(Pawn &pawn);

    void handleInput();
    void render();

    PawnsManager(Cells *cells) : cells_(cells) {}
};