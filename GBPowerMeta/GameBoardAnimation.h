// author: chris-scientist
// created at: 15/01/2022

#pragma once

#include <Arduino.h>

class GameBoard;

class GameBoardAnimation {
  private:
    GameBoard * gameBoardModel;
    bool isTriggered;
    void initialize();
    void nextStep();
  public:
    GameBoardAnimation();
    void reset();
    void run();
    void setGameBoardModel(GameBoard * aGameBoardModel);
};
