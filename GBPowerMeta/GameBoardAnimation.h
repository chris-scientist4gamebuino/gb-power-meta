// author: chris-scientist
// created at: 15/01/2022
// updated at: 10/03/2022

#pragma once

#include <Arduino.h>

#include "AGameBoardAnimation.h"

class GameBoardAnimation : public AGameBoardAnimation {
  private:
    void initialize();
    void nextStep();
  public:
    GameBoardAnimation();
};
