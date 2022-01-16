// author: chris-scientist
// created at: 15/01/2022

#pragma once

#include "Player.h"
#include "GameCommands.h"

class PlayersView {
  private:
    PlayersView();
  public:
    static void rendering(const Player aPlayerOne, const Player aPlayerTwo, const TokenDuringTheGame token);
};
