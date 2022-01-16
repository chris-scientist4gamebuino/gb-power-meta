// author: chris-scientist
// created at: 14/01/2022

#pragma once

#include "Constants.h"
#include "GameBoard.h"
#include "GameCommands.h"
#include "GameView.h"
#include "Player.h"
#include "GameBoardAnimation.h"

class GameController {
  private:
    GameBoard boardModel;
    Player playerOne;
    Player playerTwo;
    GameBoardAnimation boardAnimation;
    GameCommands commands;
  public:
    GameController();
    void initialize();
    void run();
    GameBoard * getBoardModel();
    Player getPlayerOne() const;
    Player getPlayerTwo() const;
};
