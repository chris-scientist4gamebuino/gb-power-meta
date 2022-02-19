// author: chris-scientist
// created at: 14/01/2022
// updated at: 19/02/2022

#pragma once

#include "Constants.h"
#include "GameBoard.h"
#include "GameState.h"
#include "GameStatus.h"
#include "GameCommands.h"
#include "GameView.h"
#include "MenuUI.h"
#include "Player.h"
#include "SettingController.h"

class GameController {
  private:
    GameBoard boardModel;
    GameState state;
    GameStatus statusOfGame;
    Player playerOne;
    Player playerTwo;
    GameCommands commands;
    MenuUI menuPause;

    void play();
    void checkGameStatus();
    void pause();
  public:
    GameController();
    void initialize();
    void run();
    void setSettingController(SettingController * aSettingController);
    GameBoard * getBoardModel();
    Player getPlayerOne() const;
    Player getPlayerTwo() const;
    Player * getCurrentPlayer();
    GameState * getState();
};
