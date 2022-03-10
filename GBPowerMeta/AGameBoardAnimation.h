// author: chris-scientist
// created at: 16/01/2022
// updated at: 10/03/2022

#pragma once

#include <Arduino.h>

#include "GameBoard.h"

class AGameBoardAnimation {
  private:
    bool isTriggered;
  protected:
    GameBoard * gameBoardModel;
    virtual void initialize() = 0;
    virtual void nextStep() = 0;
  public:
    AGameBoardAnimation();
    void reset();
    void run();
    void setGameBoardModel(GameBoard * aGameBoardModel);
};
