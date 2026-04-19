#include "GameRules.hpp"

#include "raylib-cpp.hpp" // IWYU pragma: keep

// Initialize Static variables for the static class
Game *GameRules::game;

void GameRules::bindToGameState(Game *gameState) { game = gameState; }

bool GameRules::canSpawn(Pawn &pawn) { return (!pawn.isSpawned() && game->dice == 6); }
bool GameRules::canMove(Pawn &pawn) { return pawn.isSpawned(); }

bool GameRules::movesExist()
{
    for (auto &pawn : game->board.pawns)
    {
        if (pawn.getColor() == game->currentPlayer->color)
        {
            if (canMove(pawn) || canSpawn(pawn))
                return true; // we can  move it, valid move, will check for winpath conditions later
        }
        //TODO add winpath logic here as well
    }
    return false;
}
