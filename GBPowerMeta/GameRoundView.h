// author: chris-scientist
// created at: 20/02/2022

#pragma once

#include "GameRound.h"

class GameRoundView {
  private:
    GameRoundView();
  public:
    static void rendering(const GameRound round);
};
