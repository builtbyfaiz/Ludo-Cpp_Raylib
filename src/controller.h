#include "board.hpp"
#include "ludoLogic.h"


class BoardController
{
  private:
    Board *board_ = nullptr;
    int   turn   = 1;
    int   dice   = 6;

  public:

    void init(Board *board);

    BoardController();
    ~BoardController();
};

