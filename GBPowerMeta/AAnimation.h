// author: chris-scientist
// created at: 16/01/2022

#pragma once

#include <Arduino.h>

#include "GameBoard.h"

class AAnimation {
  private:
    bool isTriggered;
  protected:
    GameBoard * gameBoardModel;
    virtual void initialize() = 0;
    virtual void nextStep() = 0;
  public:
    AAnimation();
    void reset();
    void run();
    void setGameBoardModel(GameBoard * aGameBoardModel);
};
