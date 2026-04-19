#pragma once
#include "Game.hpp"
// Stores Rules and logical utilities for the game.
class GameRules
{
  private:
    static Game *game; // As of now, I am passing the full game, but its a pointer so its still light

  public:
    static void bindToGameState(Game *gameState);
    static bool movesExist();

    static bool canSpawn(Pawn &selectedPawn); // Checks if Pawn is spawnable at current state, pass selected pawn
    static bool canMove(Pawn &selectedPawn);  // Checks if Pawn is moveable at current state, pass selected pawn
};