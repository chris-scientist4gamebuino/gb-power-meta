// author: chris-scientist
// created at: 11/03/2022

#pragma once

#include <Arduino.h>

#include "AScreenAnimation.h"

class PlayersScreenAnimation : public AScreenAnimation {
  private:
    int16_t xOffset;
  public:
    PlayersScreenAnimation();
    void initialize();
    void run();
};