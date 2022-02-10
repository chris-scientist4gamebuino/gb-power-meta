// author: chris-scientist
// created at: 14/01/2022
// updated at: 23/01/2022

#pragma once

#include "Constants.h"
#include "GameBoard.h"
#include "GameState.h"
#include "GameStatus.h"
#include "GameCommands.h"
#include "GameView.h"
#include "Player.h"
#include "GameBoardAnimation.h"

class GameController {
  private:
    GameBoard boardModel;
    GameState state;
    GameStatus statusOfGame;
    Player playerOne;
    Player playerTwo;
    GameBoardAnimation boardAnimation;
    GameCommands commands;

    void play();
    void checkGameStatus();
  public:
    GameController();
    void initialize();
    void run();
    GameBoard * getBoardModel();
    Player getPlayerOne() const;
    Player getPlayerTwo() const;
    Player * getCurrentPlayer();
    GameState * getState();
};
