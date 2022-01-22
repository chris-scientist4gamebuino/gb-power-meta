// author: chris-scientist
// created at: 14/01/2022
// updated at: 20/01/2022

#pragma once

#include "TokenDuringTheGame.h"
#include "GameStatus.h"

class GameController;

class GameView {
  private:
    GameView();
  public:
    static void rendering(GameController * gameController, const TokenDuringTheGame token, GameStatus aStatusOfGame);
};
