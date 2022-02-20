// author: chris-scientist
// created at: 20/02/2022

#pragma once

#include "GameRound.h"
#include "Player.h"

class EndGameView {
  private:
    EndGameView();
  public:
    static void rendering(const GameRound aRound, const Player aPlayerOne, const Player aPlayerTwo);
};