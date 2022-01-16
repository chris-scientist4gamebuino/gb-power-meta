// author: chris-scientist
// created at: 15/01/2022
// updated at: 16/01/2022

#pragma once

#include <Arduino.h>

#include "AAnimation.h"

class GameBoardAnimation : public AAnimation {
  private:
    void initialize();
    void nextStep();
  public:
    GameBoardAnimation();
};
