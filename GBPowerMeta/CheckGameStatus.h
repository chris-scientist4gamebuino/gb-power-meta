// author: chris-scientist
// created at: 20/01/2022

#pragma once

#include "GameStatus.h"
#include "TokenDuringTheGame.h"
#include "GameBoard.h"
#include "Player.h"

class CheckGameStatus {
  private:
    CheckGameStatus();
  public:
    static GameStatus run(TokenDuringTheGame aCurrentToken, const GameBoard aBoardModel, Player * aCurrentPlayer);
};
