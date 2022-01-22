// author: chris-scientist
// created at: 20/01/2022

#pragma once

#include "GameStatus.h"
#include "GameBoard.h"

class BoardComplete {
  private:
    BoardComplete();
  public:
    static const GameStatus checkIfTie(const GameBoard aBoardModel);
};
