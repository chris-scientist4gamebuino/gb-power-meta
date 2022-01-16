// author: chris-scientist
// created at: 15/01/2022

#pragma once

#include "GameBoard.h"

class GameBoardView {
  private:
    GameBoardView();
  public:
    static void rendering(GameBoard * aGameBoard);
};
