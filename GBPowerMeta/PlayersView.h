// author: chris-scientist
// created at: 15/01/2022
// updated at: 23/01/2022

#pragma once

#include "Player.h"
#include "TokenDuringTheGame.h"
#include "GameStatus.h"
#include "GameState.h"

class PlayersView {
  private:
    PlayersView();
  public:
    static void rendering(const Player aPlayerOne, const Player aPlayerTwo, const TokenDuringTheGame token, GameState aState, GameStatus aStatusOfGame);
};
