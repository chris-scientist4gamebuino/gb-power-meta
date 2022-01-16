// author: chris-scientist
// created at: 14/01/2022
// updated at: 16/01/2022

#pragma once

#include "TokenDuringTheGame.h"

class GameController;

class GameView {
  private:
    GameView();
  public:
    static void rendering(GameController * gameController, const TokenDuringTheGame token);
};
