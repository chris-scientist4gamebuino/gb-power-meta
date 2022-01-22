// author: chris-scientist
// created at: 15/01/2022
// updated at: 20/01/2022

#pragma once

#include "Player.h"
#include "TokenDuringTheGame.h"
#include "GameStatus.h"

class PlayersView {
  private:
    PlayersView();
  public:
    static void rendering(const Player aPlayerOne, const Player aPlayerTwo, const TokenDuringTheGame token, GameStatus aStatusOfGame);
};
