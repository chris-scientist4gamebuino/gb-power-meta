// author: chris-scientist
// created at: 14/01/2022
// updated at: 05/03/2022

#pragma once

#include <Arduino.h>

#include "Constants.h"
#include "GameBoard.h"
#include "GameState.h"
#include "GameStatus.h"
#include "GameRound.h"
#include "GameCommands.h"
#include "GameView.h"
#include "MenuUI.h"
#include "QuitGameDialogBox.h"
#include "Player.h"
#include "SettingController.h"

class GameController {
  private:
    GameBoard boardModel;
    GameState state;
    GameStatus statusOfGame;
    GameRound round;
    Player playerOne;
    Player playerTwo;
    Player * lastPlayerToStart;
    GameCommands commands;
    MenuUI menuPause;
    QuitGameDialogBox quitGameDialog;

    void play();
    void checkGameStatus();
    void pause();
    void stopGameDialogBox();
    Player * getPlayerToStart();
  public:
    GameController();
    void initialize(const uint8_t anInitialColorForPlayerOne);
    void initializeMenu(uint8_t * menuPauseItems, size_t nbItemsPause);
    void run();
    void newRound();
    void setSettingController(SettingController * aSettingController);
    GameBoard * getBoardModel();
    const GameRound getRound() const;
    Player getPlayerOne() const;
    Player getPlayerTwo() const;
    Player * getCurrentPlayer();
    GameState * getState();
};
